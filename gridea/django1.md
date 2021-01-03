---
title: 'django1'
date: 2019-09-02 20:08:26
tags: [Django]
published: true
hideInList: false
feature: /post-images/django1.jpg
---
# DJANGO & PYTHON

```PYTHON
html:
    <li class="first-list">
        <a class="active" href="{% url 'index' %}">
            <h3>主页</h3>	
        </a>
    </li>

urls.py:
	path(r'',views.index,name="index"),
	path(r'register/',views.register,name="register"),
	path(r'register_hy/',views.register_hy,name="register_hy"),
	path(r'register_fs/',views.register_fs,name="register_fs"),
	path(r'liuyan/',views.liuyan,name="liuyan"),
	path(r'register_hysq/',views.register_hysq,name="register_hysq"),
	path(r'register_fssq/',views.register_fssq,name="register_fssq"),
	# path(r'news/',views.news,name="news"),
	re_path(r'news/(\d+)/',views.news,name="news"),
	path(r'news_list/',views.news_list,name="news_list"),
	# re_path(r'news_list/(\d+)/$',views.news_list,name='news_list'),					
	# path(r'activity/',views.activity,name="activity"),		
	re_path(r'activity/(\d+)/',views.activity,name="activity"),							
	# 搜索引擎
	# path('search/', views.MySearchView(), name='haystack'),
	path('', views.MySearchView(), name='haystack'),
   
views.py:
    huodong=HuoDong.objects.all().order_by('-hdtime')
    zixun=ZiXun.objects.order_by('-zxtime')[0:4]
	huodong1 = huodong[0]
	huodong2 = huodong[1]
	huodong3 = huodong[2]
    return render(request,'index.html',locals())
    #提交表单
    if request.method == "POST":
		new_hy = HYInfo()
		new_hy.hyname = request.POST.get('hyname')
		new_hy.hyphone = request.POST.get("hyphone")
		new_hy.hywechat = request.POST.get("hywechat")
		new_hy.hyemail = request.POST.get("hyemail")
		new_hy.hycar = request.POST.get("hycar")
		new_hy.hycarprice = request.POST.get("hycarprice")
		# new_hy.hypicture = request.POST.get("hypicture")
		new_hy.hypicture = request.FILES['hypicture']
		# if new_hy.hypicture:
			# new_img = Test(name=request.POST.get('hypicture'),image=file)
		new_hy.save()
  html
 <form role="form" action="{% url 'register_fssq' %}" method="post">
    {% csrf_token %}
    <div class="fields-grid">
        <div class="styled-input agile-styled-input-top">
            <input type="text" name="fsname" required="">
            <label>全名</label>
        </div>
    </div>
    <input type="submit" value="提交">
</form>


<a style="float:right;" class="btn btn-primary" href="{% url 'activity' hd.id %}">
>>查看详情
</a>
```

# 总结

```python
url(regex,views,kwargs=None,name=None)
url(r'^show/$',show_views,{'name':'laoshe','age':'89'})

{% for 变量 in 列表|元组|字典 %}
{% endfor %}

{% if 条件 %}
满足条件运行的内容
{% else %}
不满足条件运行的内容
{% endif %}

增：
	Author.objects.create(name='zsf',age=85)
	obj = Author(names='laoshe',age=65)
    obj.save()
查：
    Entry.objects.all()
    Entry.objects.values('列1','列2',...)
    Author.objects.values('name','age')
    Author.objects.order_by('age')
    Entry.objects.exclude(条件)#取反
    Author.objects.exclude(id=3)
    Entry.objects.filter(参数)#过滤
    Author.objects.filter(id=1)
    Entry.objects.filter(属性__exact=值)#精确查询，等值判断
    Author.objects.filter(id__exact=1) == select * from author where id=1
    #筛选出属性中包含指定关键字的记录(模糊查询)
    Author.objects.filter(name__contains='ao') == select * from author where name like '%ao%'
修改：
    au = Author.objects.get(id=1)
    au.name = "老舍"
    au.age = 45
    au.save()
    
    Entry.objects.all().update(属性=值,属性=值)
    Author.objects.all().update(age=75)
删除：
	1、删除单个对象
			obj = Author.objects.get(id=1)
			obj.delete()
	2、删除多个对象
			Author.objects.all().delete()
```

# 原生数据库操作

```python
原生的数据库操作方法
		1、查询
			函数：raw(sql语句)
			语法：Entry.objects.raw(sql)

		2、增删改
			def doSQL(request):
				with connection.cursor() as cursor:
					sql = "delete from author"
					cursor.execute(sql)
					return HttpResponse('...')
```

# 模型关系

```python
1.模型中的关系映射
	关系映射
	1、一对一(1:1)
		entry = models.OneToOneField(Entry)

		class Wife(models.Model):
			... ...
			author = models.OneToOneField(Author)
		
	2、一对多(1:M)
		1、什么是一对多
			A表中的一条数据可以与B表中的多条数据关联
			B表中的一条数据只能与A表中的一条数据关联

			如：
				出版社(Publisher) 和 图书(Book)
				商品类型(GoodsType) 和 商品(Goods)
		2、在数据库中的体现
			通过外键(Foreign Key)来体现一对多
			在"多"表中增加外键(Foreign Key)对"一"表的主键进行引用
		3、语法
			使用 外键(Foreign Key)
			在"多"的实体中，增加：
				属性=models.ForeignKey(Entry)
			ex:
				Book(多) 和 Publisher(一)

				class Book(models.Model):
					... ...
					publisher = models.ForeignKey(Publisher)

		4、查询
			1、正向查询 - 通过Book查询Publisher	
				#查询id为1的书籍的信息
					book = Book.objects.get(id=1)
				#查询关联的publisher
					publisher = book.publisher
			2、反向查询 - 通过Publisher查询Book

				Django会在 1 的实体中增加 关联对象_set 属性
				用于查询 多 的数据

				结合 Publisher 和 Book 之间关系 ：
					在 Publisher 中 增加了一个 book_set 属性

				ex:
					publisher=Publisher.objects.get(id=1)
					books = publisher.book_set.all()
	3、多对多(M:N)
		1、什么是多对多
			A表中的一条记录可以与B表中的任意多条记录匹配
			B表中的一条记录可以与A表中的任意多条记录匹配
			ex：
				作者 与 书籍
		2、在数据库中的体现
			必须至少创建第三张表，关联涉及到的两张表数据
		3、语法
			允许在任何一个实体中增加操作：
				entry = models.ManyToManyField(Entry)
			ex:
				class Author(models.Model):
					... ...
					book = models.ManyToManyField(Book)
		4、查询
			class Author(models.Model):
				... ...
				book = models.ManyToManyField(Book)
			
			1、正向查询-通过Author查询所有的Book
				author = Author.objects.get(id=1)
				books = author.book.all()
				通过 关联属性.all() 查询所有对应数据

			2、反向查询-通过Book查询所有的Author
				Django中 会在Book 实体中增加一个隐式属性 author_set

				book = Book.objects.get(id=1)
				authors = book.author_set.all()

2、HttpRequest
	1、HTTP 协议
		1、请求(request)
			1、请求起始行
			2、请求消息头
			3、请求主体
		2、响应(response)
			1、响应起始行
				协议名称/版本号 响应状态码 原因短句
			2、响应消息头
			3、响应主体
	2、HttpRequest介绍
		1、什么是HttpRequest
			HttpRequest，在Django中是对请求对象的封装体现。
			它封装了请求过程中所有的信息。在Django中，
			HttpRequest被化身成了request封装到视图处理函数中作为参数，在调用视图时自动传入

		2、HttpRequest中的主要内容
			1、request.scheme : 请求协议
			2、request.body : 请求主体
			3、request.path : 请求路径
			4、request.get_host() : 请求主机/域名
			5、request.method : 请求方法
			6、request.GET : get请求方式提交的数据
			7、request.POST : post请求方式提交的数据
			8、request.COOKIES : cookies中的数据
```

# http

```python
HttpRequest
	1、HTTP 协议
		1、请求(request)
			1、请求起始行
			2、请求消息头
			3、请求主体
		2、响应(response)
			1、响应起始行
				协议名称/版本号 响应状态码 原因短句
			2、响应消息头
			3、响应主体
	2、HttpRequest介绍
		1、什么是HttpRequest
			HttpRequest，在Django中是对请求对象的封装体现。它封装了请求过程中所有的信息。在Django中，HttpRequest被化身成了request封装到视图处理函数中作为参数，在调用视图时自动传入

		2、HttpRequest中的主要内容
			1、request.scheme : 请求协议
			2、request.body : 请求主体
			3、request.path : 请求路径
			4、request.get_host() : 请求主机/域名
			5、request.method : 请求方法
			6、request.GET : get请求方式提交的数据
			7、request.POST : post请求方式提交的数据
			8、request.COOKIES : cookies中的数据
```

# AJAX

```PYTHON
2.AJAX
	A:Asynchoronous  异步的
	J:JavaScript （JSON）
	A:And
	X:XML  

	XML和HTML
	ML:标记语言
	XML: extensive markup language 可扩展

	相同点：都是用标签，属性，文本组织的
	不同点：HTML：标签被w3cshool规定好的标签，标签的属性也是规定好的。
	XML：可以自己定义规则。与平台无关的，客户端与服务端，客户端与客户端之间，
	用来传递信息，数据描述的载体。
	缺点：在传递数据时，描述信息的标签，占据了带宽。
	后来，设备与设备之间传输信息的格式，由XML格式的信息传递，变为了JSON,
	{‘name’:'tom','age':18}.
	JSON  (javascript object notation)javascript对象描述。

	JSON和XML是一类，描述数据信息的格式
	JavaScript和html是一类，都是语言

	异步：不用等待执行结果，可以去执行其他事情。
	同步：必须等待一个事情结束了，才能继续进行下一步。

	程序中不是说异步就一定好，有各自的应用场合。
	AJAX不是一种语言，是一种纯前端的技术（浏览器使用的）
	浏览器里内嵌了一个对象，XMLHTTPRequest，通过该对象也能发起一个请求，并等待服务器的响应，
	处理响应。简称xhr
	浏览器地址栏里输入地址不就是发起请求吗？
	打开一个网页，有黄金3秒钟，为了提高用户体验，先把静态的内容呈现，
	特别复杂的内容会单独再发起请求，慢慢加载。整体
	页面加载，给用户一个反馈。等用户看到后面的内容时，可能几十秒过去了，这时候已经加载出来了。

3.AJAX应用场合

	1.单独发请求，单独响应，单独刷新局部页面。
	2.注册
		有些网站注册内容项比较多，因为用户名重复或者其中一项错误，但是只在
		全部写完，点击注册时才知道错误，返回注册页面，之前输入的内容都没有了，
		还得重新输入。
		怎么能及时提示？
		在输入完用户名后，输入其他内容时，已经去服务器请求，这样就能提前知道。
		单独刷新页面，保留其他内容的基础上，只修改用户名。
    3.使用AJAX的步骤
        标准JS:
            1.获得 XMLHTTPRequest对象
            2.进行配置：包括请求路径，发送的数据，如何处理收到的响应
            3.发送请求

        标准Jquery
            $.ajax(配置参数)；
            配置参数以字典，键值对的方式，也就是JS对象的形式传入。
            
        在注册的html模板中加载JS，位置写到head中。
        Jquery文件放到静态文件中
        
            <script src="static/js/jquery-1.11.3.js"></script>
            <script>
                $(function (){
                   var inputusername = $('#username');
                    var spanusername = $('#span_username');
                    inputusername.blur(function () {
                        var name = inputusername.val();
                        $.ajax({
                            url:'/check',
                            data:{'username':name},
                            type:'post',
                            datatype:'json',
							async:'true',
                            successs:function (date) {
                                console.log(data)
                            },       
                            error:function (err) {
                                console.log('错误信息:'+err)
                                }
                            });
                        }); 
                })
            </script>
        $(function () {}是当DOM树加载完毕后执行的
        当输入完用户名之后去输入其他的时候，就去提交请求。当用户名文本框失去焦点blur的时候，就把用户名
        发送给服务器。因为要获取这个文本框对象，这里增加id属性为input_username。
        无论有没有重名，服务器必须给一个响应，如果不可用，提示该用户名已被占用。
        直到用户名改为可用为止。
        在注册模块中，增加一个<span>行内标记，服务器要动态修改它的文本内容，所以也需要获取该元素的JS对象，
        也增加一个id属性span_username。
        $.ajax（）中的参数具体介绍：
            
            url：ajax请求发送路径
            data：发送数据
            type：请求的类型
            datatype：指明服务器返回的数据类型
			async:'true'
            success：function（）{}请求成功触发得回调函数
            error：function（）{}请求失败触发的回调函数
```

# cookies&session

```PYTHON
1、cookies
	1、什么是cookies
		cookies 是一种数据存储技术
		将一段文本保存在客户端(浏览器)的一种技术，并可以长时间保存
	2、cookies的应用场合
		1、保存登录信息
		2、保存搜索关键词
	3、django 中使用 cookies
		1、设置 cookies 的值(将数据保存进客户端)
			语法：
				响应对象.set_cookie(key,value,expires)
					key:cookie的名字
					value:cookie的值
					expires:cookie的保存时间，以s为单位
						60*60*24*365
			1、不使用模板
				resp = HttpResponse('')
				resp.set_cookie('uname','zsf',60)
				return resp
			2、使用模板
				resp = render(request,'xxx.html',locals())
				resp.set_cookie(key,value,expires)
				return resp
			3、使用重定向
				resp = HttpResponseRedirect('/xxx/')
				resp.set_cookie(key,value,expires)
				return resp
		2、获取 cookies 的值(从客户端中取数据)
				request.COOKIES
				封装了当前站点下的所有cookie信息
		3  删除  resp.delete_cookie('id')				
2、session - 会话
	1、什么是session	
		session，实际上就是在服务器上为浏览器开辟一段空间，用于保存相关的信息
	2、在 Django 中使用session
		1、设置 session 的值
			request.session['key'] = 值;
			设置session的过期时间
			request.session.set_expiry(time)
			time 就是以秒为单位的一个时间
		2、获取session的值
			request.session[key] 或 request.session.get(key)
		3、删除 session 的值
			del request.session['key']
	3、在 settings.py中，有关session的设置
		1、SESSION_COOKIE_AGE
			作用：设置sessionID在cookies中的存活时间
			ex:
				SESSION_COOKIE_AGE=60*10
				sessionID在cookie中保留10分钟
		2、SESSION_EXPIRE_AT_BROWSER_CLOSE
			作用：设置在浏览器关闭时同时清除服务器上对应的session空间
			ex:
				SESSION_EXPIRE_AT_BROWSER_CLOSE=True
```

# 表单

```python
1、表单
	1、form元素：收集信息并提交给服务器
		属性
		1、action
			指定提交给服务器上处理程序的地址
			默认提交给本页
		2、method
			提交方法/方式
			取值：
			1、get
				默认值
				向服务器要数据时使用get
				特点：
				1、提交的数据会显示在地址栏上
				2、安全性较低
				3、有提交数据的大小限制 - 2KB
			2、post
				要提交数据给服务器处理时，使用post
				特点：
				1、隐式提交，看不到提交的数据
				2、安全性较高
				3、无提交数据的大小限制
		3、enctype （encode type编码方式）
			enctype 属性规定在发送到服务器之前应该如何对表单数据进行编码
			即允许将什么样的数据提交给服务器
			1、application/x-www-form-urlencoded
				默认值，允许将所有的文本数据提交给服务器
			2、multipart/form-data
				允许将文件提交给服务器
			3、text/plain
				允许将普通字符提交给服务器，特殊字符不行
	2、表单控件
		用于与用户进行数据交互，只有放在form元素里才能被提交
		控件类型
			1、文本框 与 密码框
				文本框：<input type="text">
				密码框：<input type="password">
				属性：
					1、name ：为控件起名，在服务器上使用
					2、maxlength ：限制输入的最大字符数
					3、placeholder ：提示占位符
			2、按钮
				1、提交按钮
					<input type="submit">
				2、重置按钮
					<input type="reset">
					重置，可简单理解为重填
				3、普通按钮
					两种写法
					<input type="button">
					<button>按钮上的文字</button>
					按钮的属性
					value ：值指的是在控件上所显示的值
						如：<input type="submit" value="登录">
				4、单选按钮 和 复选框
				单选按钮：<input type="radio">
				复选框：<input type="checkbox">
				属性：
					1、name
						为控件定义名称。除了定义名称之外，name属性也起到了分组的作用。
						一组的单选按钮和复选框，名称必须一致
					2、value
						值，单选和复选框的值是提交给服务器的值
					3、checked
						预选中,该属性无值
		具体演示见01_from.html所示
		 <form action="login" method="post" enctype="application/x-www-form-urlencoded">	
			用户名称：
			<input type="text" name="uname" placeholder="请输入用户名" maxlength=8>
			性别：性别只能选择一个，用单选按钮，性别是一组的单选按钮，名称一致均为“gender”，value值为0或者1
			<input checked type="radio" name="gender" value='0'>男
			<input type="radio" name="gender" value='1'>女
			其中，checked表示的就是预选中，默认性别为男
			爱好：可以选择0个或多个，用复选框，一组的name相同，都是"hobby",也可以定义value属性
			<input type="checkbox" name='hobby' value='0'>吃
			<input type="checkbox" name='hobby' value='1'>喝
			<input type="checkbox" name='hobby' value='2'>玩
			<input type="checkbox" name='hobby' value='3'>乐
			
			<button type="submit">登录1</button>
			<input type="button" value="登录2">  通常不这么写
			<input type="submit" value="登录3">
			<input type="reset" value="重置1">
			<button type="reset" value="重置2">
			type是submit的才会提交数据，value是按钮上的文字，
			登录2，只是普通的按钮，不会提交数据		
			如果把该表单中的post方法改为get方法呢？可以看到数据的提交是放在地址url上的
			file:///C:/login?uname=asd&gender=0&hobby=0&hobby=1&addr=1

2.	html标签的自定义属性
	在html中，任意标记除了自带的属性外，我们还可以自定义添加属性，
    一般来说以下划线开头来区分，_p,_i等，为的目的是在后面拿出来这个
    属性使用，自定义的属性在页面上是不会显示的,因为浏览器不知道怎么解析
	示例见 02_form.html
	将01_form.html随意选择两个标签，添加自定义的属性，用浏览器打开无变化，
	查看源代码可以看到添加的属性
		<input type="text" name="uname" _i="a" _n="b" _p="c">	
		<input type="checkbox" name='hobby' value='0' _i="a" _n="b" _p="c">吃
		<input type="checkbox" name='hobby' value='1' _i="a" _n="b" _p="c">喝
```

# jquery

```python
3.Jquery
	简介：
		打开jquery-3.2.1.js（其他版本也可）文件，这个一个Jquery文件，
		里面的语法都是原生JavaScipts语法，但是比较难看懂，也无需看懂
		只需要知道Jquery是由js的变量，函数等封装而成的一个文件即可。
		Jquery是一个轻量级的JS库，称不上是一个框架。一般库包含多个模块文件，轻量级的原因是
		只需引入一个文件
		提供了比原生JS更为简便的页面元素的操作方式
	使用：
		1.引入jquery文件
			<script src="jquery-3.2.1.js"></script>
			引入的这一行必须放在其他jquery操作之前
		2.使用（内容非常多，只说最常用的）
			...
		3.在使用之前首先要明确一个概念，什么是Jquery对象
			 在JS中，通过document.getElementById()的方法得到
			 的对象是DOM对象，比如elem就是DOM对象的变量名
				var elem=document.getElementById("id");
				document.getElementsByTagName(标签名)得到的是一组的DOM对象
			那么，通过Jquery文件提供的某种方法得到的对象就是Jquery对象
			Jquery中提供的所有操作都只针对Jquery对象，其他的比如
			DOM对象不支持
			示例见 01_jquery_dom
			jquery对象获取父元素的方法是访问对象的方法parent（）
			DOM对象获取父元素的方式是通过该对象访问对象的属性parentNode
		4.通过什么方法得到Jquery对象呢？
			工厂函数----$() 
			通过工厂函数可以得到或者转换为Jquery对象
			比如$('#id')得到的就是一个jquery对象
			$可以简单理解为一个函数名
			function $(id){
				return document.getElementById(id);
			}
		5.DOM对象和jquery对象
			DOM对象：以DOM的方式获取出来的节点对象都是DOM对象，只能调用DOM提供的方法和属性
			jquery同理
			1. var $obj = $(DOM对象) ，$obj是在给jquery对象的变量起名字时，通常在变量名前
			加上$用于区分，也可以不加
			2.将jQuery对象转换为DOM对象，用的比较少.
				所有的工厂函数返回值是数组,不叫字典。
				1.var dom对象 = jQuery对象[0]；把工厂函数返回的数组取下标得到的就是
				DOM对象，取下标时自动转换。如果返回的是多个数组的话，用不同的下标位置。
				2.var dom对象 = jQuery对象.get(0)，作用同上		
	    6.jQuery选择器
		1.作用
		获取页面上的元素们，返回值是由Jquery对象组成的数组
		语法：$("选择器")
		选择器的介绍及使用示例参见文档，基本选择器和css的相同。
		#id，.class    element 
		2.常用选择器
			1.基本选择器
				1.ID选择器
				$("#id")返回页面中指定的ID值的元素
				2.类选择器
				$(".class"),返回页面中指定className的所有元素
				3.元素选择器
				$("element"),返回页面中指定标记的所有元素
				4.群组选择器
				$("selector1,selector2..."),返回满足函数内所有选择器的函数们
			2.层级选择器
				1.$("selector1 selsector2")
				后代选择器
				2.$("selector1>selector2")
				子代选择器
				3.$("selector1+selector2")
				相邻兄弟选择器，匹配紧紧跟在selecor1后面且满足selector2
				选择器的元素，注意必须是后面。
		3.事件
			页面加载是有顺序的
				浏览器接收服务器响应后，先在内存中生成DOM树，然后再去渲染（
				将DOM树上的图片，文字,标签等依次加载显示到网页上）
			Jquery因为要获取页面元素对象进行操作，就需要这个页面元素得加载出来，
			又想提高速度的话，就要在DOM树加载（也叫页面的初始化）完毕后执行操作
			三种方式：
			1.$(document).ready()
			2.$().ready()
			3.$(function(){})
			$(function(){
				//DOM树加载完成后就开始执行
			   });
			因为如果页面元素较多，可能在获取某个对象之前，这个元素还没加载出来
			这个时候就获取不到该对象。因此，在获取对象之前，一般会加上一个等待时间
			等DOM加载完毕后，再调用function（）这个没有函数名的函数，然后再获取对象。
		示例1：创建一个02_jquery.html
			给button按钮在Jquery中动态的绑定事件，弹出一句话alert
			语法：$("xxx").click(function(){
						动作触发执行的代码；
					});
			其中，click()方法是当按钮点击事件被触发时会调用一个函数	
		示例2：创建一个03_jquery-operation.html
			给一个输入框添加事件并动态改变其他元素的文本显示内容
		示例3：当点击事件在某个p元素上时，隐藏当前的p元素
			在script中动态的添加事件时，不用写函数名，但是函数的调用（）不能省略
			$("p").click(function(){
			});
			双击触发的事件，写法是dblclick(),用法和click()一样	
	Jquery集成了少量的css，通过方法css()为Jquery对象设置样式
		示例4：见04_query.html
	Jquery对象对属性的操作
		语法：Jquery对象.attr()   attribute属性的简写
		作用：读取jquery对象的属性值
		示例：$("#c").attr("id"); 获取id为c的对象元素的id属性

	Jquery中的$(this)和$(each)
	$(this)指的是当前操作的Jquery对象
	$(each)相当于for
	见05_query-each.html
	页面素材采用01_form中的元素，获取输入框中checkbox类型的对象
	：伪类选择器（不是真正的类clas）
	var $checkbox = $('input:checkbox');
		console.log('1--->',$checkbox);
		打印的结果是获得四个复选框对象
		在页面中选择一个复选框，我选的是爱好为吃，进一步筛选checked表示
		选中
		var $checked = $('input:checkbox:checked');
		console.log('2---->',$checked);
		这时打印的就成了当前我勾选的那个复选框了
		在页面中勾选几个就会得到几个对象

		对于多个对象循环遍历取出，赋值给一个字典中，再将字典添加到数组中
		$.each($checked,function () {
				...............
			 }
		
		var carts=[];是声明一个空的数组变量
		carts.push(cartg);是向数组中添加元素的方法，每个元素都是一个Jquery对象
		数组和列表很相似，但是数组要求元素具有同质性
		location.href='cartinfo/order';是跳转页面到这个地址，location是window对象
		的属性，等价于
		window.location.href='cartinfo/order';	
```

