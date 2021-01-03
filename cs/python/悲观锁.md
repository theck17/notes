---
title: '悲观锁'
date: 2020-03-22 23:16:27
tags: [Django]
published: true
hideInList: false
feature: /post-images/bei-guan-suo.jpg
---
# 悲观锁
```python
class OrderCommitView(View):
    """悲观锁"""
    # 开启事务装饰器
    @transaction.atomic
    def post(self,request):
        """订单并发 ———— 悲观锁"""
        # 拿到商品id
        goods_ids = request.POST.getlist('goods_ids')

        # 校验参数
        if len(goods_ids) == 0 :
            return JsonResponse({'res':0,'errmsg':'数据不完整'})

        # 当前时间字符串
        now_str = datetime.now().strftime('%Y%m%d%H%M%S')

        # 订单编号
        order_id = now_str + str(request.user.id)
        # 地址
        pay_method = request.POST.get('pay_method')
        # 支付方式
        address_id = request.POST.get('address_id')
        try:
            address = Address.objects.get(id=address_id)
        except Address.DoesNotExist:
            return JsonResponse({'res':1,'errmsg':'地址错误'})

        # 商品数量
        total_count = 0
        # 商品总价
        total_amount = 0

         # 获取redis连接
        conn = get_redis_connection('default')
        # 拼接key
        cart_key = 'cart_%d' % request.user.id

        # 创建保存点
        sid = transaction.savepoint()

        order_info = OrderInfo.objects.create(
            order_id = order_id,
            user = request.user,
            addr = address,
            pay_method = pay_method,
            total_count = total_count,
            total_price = total_amount
        )

        for goods_id in goods_ids:
            # 尝试查询商品
            # 此处考虑订单并发问题,
            try:
                # goods = Goods.objects.get(id=goods_id)  # 不加锁查询
                goods = Goods.objects.select_for_update().get(id=goods_id)  # 加互斥锁查询
            except Goodsgoods.DoesNotExist:
                # 回滚到保存点
                transaction.rollback(sid)
                return JsonResponse({'res':2,'errmsg':'商品信息错误'})
            # 取出商品数量
            count = conn.hget(cart_key,goods_id)
            if count is None:
                # 回滚到保存点
                transaction.rollback(sid)
                return JsonResponse({'res':3,'errmsg':'商品不在购物车中'})

            count = int(count)

            if goods.stock < count:
                # 回滚到保存点
                transaction.rollback(sid)
                return JsonResponse({'res':4,'errmsg':'库存不足'})

            # 商品销量增加
            goods.sales += count
            # 商品库存减少
            goods.stock -= count
            # 保存到数据库
            goods.save()

            OrderGoods.objects.create(
                order = order_info,
                goods = goods,
                count = count,
                price = goods.price
            )

            # 累加商品件数
            total_count += count
            # 累加商品总价
            total_amount += (goods.price) * count

        # 更新订单信息中的商品总件数
        order_info.total_count = total_count
        # 更新订单信息中的总价格
        order_info.total_price = total_amount + order_info.transit_price
        order_info.save()

        # 事务提交
        transaction.commit()

        return JsonResponse({'res':5,'errmsg':'订单创建成功'})
```

```python
DATABASES = {
    'default': {
        # 'ENGINE': 'django.db.backends.sqlite3',
        # 'NAME': os.path.join(BASE_DIR, 'db.sqlite3'),
        #  配置mysql
        'ENGINE': 'django.db.backends.mysql',
        'NAME': 'mydatabase',
        'USER': 'mydatabaseuser',
        'PASSWORD': 'mypassword',
        'HOST': '127.0.0.1',
        'PORT': '3306',
        # Django在web上一种简单的将事务绑定到HTTP请求上的操作是将每个请求都用事务包装起来，即在数据库的配置中设置ATOMIC_REQUESTS值为 True
        'ATOMIC_REQUESTS' : True
    }
}
```

```python
# 悲观锁创建订单
from django.http import JsonResponse
from django.views.generic import View

from apps.goods.models import GoodsSKU
from apps.order.models import OrderInfo, OrderGoods

from django_redis import get_redis_connection

from django.db import transaction

# 悲观锁处理创建订单
class OrderCommitView(View):
    """订单创建"""
    @ transaction.atomic
    def post(self, request):
        # 判断用户是否登录
        user = request.user
        if not user.is_authenticated():
            return JsonResponse({'res': 0, 'errmsg': '用户未登录'})

        # 接收参数
        addr_id = request.POST.get('addr_id')
        pay_method = request.POST.get('pay_method')
        sku_ids = request.POST.get('sku_ids')  # 以,分隔的字符串 3,4

        # 参数校验
        if not all([addr_id, pay_method, sku_ids]):
            return JsonResponse({'res': 1, 'errmsg': '参数不完整'})

        # 校验地址id
        try:
            addr = Address.objects.get(id=addr_id)
        except Address.DoesNotExist:
            return JsonResponse({'res': 2, 'errmsg': '地址信息错误'})

        # 校验支付方式
        if pay_method not in OrderInfo.PAY_METHODS.keys():
            return JsonResponse({'res': 3, 'errmsg': '非法的支付方式'})

        # 组织订单信息
        # 组织订单id: 20180316115930+用户id
        from datetime import datetime
        order_id = datetime.now().strftime("%Y%m%d%H%M%S") + str(user.id)

        # 运费
        transit_price = 10

        # 总数目和总价格
        total_count = 0
        total_price = 0

        # 设置事务保存点
        sid = transaction.savepoint()

        try:
            # 向df_order_info中添加一条记录
            order = OrderInfo.objects.create(
                order_id=order_id,
                user=user,
                addr=addr,
                pay_method=pay_method,
                total_count=total_count,
                total_price=total_price,
                transit_price=transit_price
            )

            # 订单中包含几个商品需要向df_order_goods中添加几条记录
            # 获取redis链接
            conn = get_redis_connection('default')
            # 拼接key
            cart_key = 'cart_%d' % user.id

            # 将sku_ids分割成一个列表
            sku_ids = sku_ids.split(',')  # [3,4]

            # 遍历sku_ids，向df_order_goods中添加记录
            for sku_id in sku_ids:
                # 根据id获取商品的信息
                try:
                    # select * from df_goods_sku where id=<sku_id> for update;
                    # sku = GoodsSKU.objects.get(id=sku_id)
                    print('user: %d try get lock' % user.id)
                    sku = GoodsSKU.objects.select_for_update().get(id=sku_id)
                    print('user: %d get locked' % user.id)
                except GoodsSKU.DoesNotExist:
                    # 回滚事务到sid保存点
                    transaction.savepoint_rollback(sid)
                    return JsonResponse({'res': 4, 'errmsg': '商品信息错误'})

                # 从redis中获取用户要购买的商品的数量
                count = conn.hget(cart_key, sku_id)

                # 判断商品的库存
                if int(count) > sku.stock:
                    # 回滚事务到sid保存点
                    transaction.savepoint_rollback(sid)
                    return JsonResponse({'res': 6, 'errmsg': '商品库存不足'})

                # 模拟订单并发问题
                # print('user: %d' % user.id)
                import time
                time.sleep(10)

                # 向df_order_goods中添加一条记录
                OrderGoods.objects.create(
                    order=order,
                    sku=sku,
                    count=count,
                    price=sku.price
                )

                # 减少商品库存，增加销量
                sku.stock -= int(count)
                sku.sales += int(count)
                sku.save()

                # 累加计算订单中商品的总数目和总价格
                total_count += int(count)
                total_price += sku.price * int(count)

            # 更新订单信息中商品的总数目和总价格
            order.total_count = total_count
            order.total_price = total_price
            order.save()
        except Exception as e:
            # 回滚事务到sid保存点
            transaction.savepoint_rollback(sid)
            return JsonResponse({'res': 7, 'errmsg': '下单失败1'})
        # 删除购物车中对应的记录
        # hdel(key, *args)
        conn.hdel(cart_key, *sku_ids)

        # 返回应答
        return JsonResponse({'res': 5, 'errmsg': '订单创建成功'})
```

