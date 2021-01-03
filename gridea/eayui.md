---
title: 'EayUI'
date: 2019-10-16 21:22:42
tags: [Django]
published: true
hideInList: false
feature: /post-images/eayui.jpg
---
# EasyUI

<http://www.jeasyui.net/tutorial/147.html>

```JS
<script type="text/javascript" charset="utf-8">
	var datagrid;
$(function() {
    $('datagrid').datagrid({
        url:'',
        title:'wkh',
        iconCls:'icon-save',
        pagination:true,//分页工具条
        pageSize:10,
        pageList:[10,20,30,40,50],//每页显示数量选择
        fit:true,//自适应页面宽高
        fitColumns:false,//设置横向滚动条
        nowarp:false,//字段字数过多自动折行
        border:false,
        idField:'id',//生成每行的id，翻页会记住，比如跨页删除
        sortName:'name',//排序参数
        sortOrder:'desc',//排序参数,降序
        columns:[ [
            {
                title:'编号'，
                field:'id',
                width:100,
                sortable:true//用户点击排序
            },
            {
                title:'姓名'，
                field:'name',
                width:100
            },
            {
                title:'密码'，
                field:'password',
                width:100
            }
        ] ],
        toolbar:[
            {
            text:'增加',
            iconCls:'icon-add',
            handler:function(){}
        	},'-'            
            {
            text:'删除',
            iconCls:'icon-remove',
            handler:function(){}
        	},'-'
            {
            text:'修改',
            iconCls:'icon-edit',
            handler:function(){}
        	},'-'
  			{
            text:'查询',
            iconCls:'icon-search',
            handler:function(){}
        	},'-'
        ],//方式一
        toolbar:'#toolbar',//方式二，设置一个div，放到最上面
        
    })
})
</script>
```

## task1

```python
from django.core.paginator import Paginator, Page, EmptyPage, PageNotAnInteger 
#从Django自带的paginator模块插入类
contact_list = models.objects.all() #这边的model指代数据表
paginator = Paginator(contact_list, 20) #20是每页显示的数量，把数据库取出的数据生成paginator对象，并指定每页显示的数量
page = request.GET.get('page') #从查询字符串获取page的当前页数
if page: #判断：获取当前页码的数据集，这样在模版就可以针对当前的数据集进行展示
    data_list = paginator.page(page).object_list
else:
    data_list = paginator.page(1).object_list
try:  #实现分页对象，分别判断当页码存在/不存在的情况，返回当前页码对象
    page_object = paginator.page(page)
except PageNotAnInteger:
    page_object = paginator.page(1)
except EmptyPage:
    page_object = paginator.page(paginator.num_pages)
return render(request, "websql/usersqllog.html", {
    'page_object':page_object,
    'data_list':data_list
}) #返回给模版当前页码对象和当前页码的数据集

```

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Titlename</title>
    <link rel="stylesheet" type="text/css" href="/static/easyui/themes/default/easyui.css">
    <link rel="stylesheet" type="text/css" href="/static/easyui/themes/icon.css">
    <script type="text/javascript" src="/static/js/jquery.js"></script>
    <script type="text/javascript" src="/static/easyui/jquery.easyui.min.js"></script>
</head>
<style>
    ul{
        list-style: none;
        margin:0px;
        padding:0px;
        width:auto;
    }
    ul li{
        float:left;
        margin-top:10px;
        padding:10px;
        border-style: solid;
        border:1px solid;
    }
</style>
<body class="easyui-layout" style="font-size:14px;">
    <div style="padding:5px;background:#fafafa;width:200px;border:1px solid #ccc;margin-left: 10px">
        <a href="{% url 'index' %}" class="easyui-linkbutton" data-options="iconCls:'icon-back'">返回首页</a>
    </div>
    <div style="margin-left:10px;">
    <table id="dg" class="easyui-datagrid" title="Titlename" style="width:1000px;height:560px"
            data-options="singleSelect:true,collapsible:true">
        <thead>
            <tr>
                <th field="id" width="50px">序号</th>
                <th field="name" width="100px">用户名</th>
                <th field="address_ip" width="200px">访问的ip地址</th>
                <th field="create_time" width="400px">访问时间</th>
            </tr>
        </thead>
        <tbody>
        {% for data in data_list %}
            <tr>
                <td width="50px">{{ data.id }}</td>
                <td width="100px">{{ data.name }}</td>
                <td width="100px">{{ data.ip }}</td>
                <td width="400px">{{ data.time }}</td>
            </tr>
        {% endfor %}
        </tbody>

    </table>
    </div>
    <div style="margin-left:10px;">
        <ul class="pagination">
            {% if page_object.has_previous %}
                <li>
                <a href="?page={{ page_object.previous_page_number }}" aria-label="Previous"><span aria-hidden="true">&laquo;</span></a>
                </li>
            {% endif %}

           {% for pg in page_object.paginator.page_range %}
            {% if page_object.number == pg %}
            <li class="active"><a href="?page={{ pg }}">{{ pg }}</a></li>
            {% else %}
            <li><a href="?page={{ pg }}">{{ pg }}</a></li>
            {% endif %}
            {% endfor %}
            {% if page_object.has_next %}
                <li>
                    <a href="?page={{ page_object.next_page_number }}" aria-label="Next"><span aria-hidden="true">&raquo;</span></a></li>
            {% endif %}
        </ul>
    </div>
</body>
</html>
```

## task2

```python
前台：

<table id="dg"></table>

 $('#dg').datagrid({
            url:'/url/'，

　　　　 columns:[[
                {field:'Name',title:'name',width:100},
                {field:'User',title:'user',width:100}

　　　　]]

}）

后台：主要有3个参数，page（页数）、rows（每页行数）、total（总行数）

思路：

1、datagrid会自己传page 跟rows过来，直接在后台获取

2、得到page跟rows后把它们类型转为int、从数据库取出数据把总行数赋给total，然后把数据放到列表里面

3、判断page是不是第一页：

　　3.1、如果是第一页：判断有多少行（rows），取rows行数据

　　3.2、如果不是第一页：从列表删除page-1条数据得到剩余的数据，然后再做第3.1步

4、把total跟得到的数据拼起来：ealist = {'rows':alist,'total':total}

5、把ealist转成json格式数据return回去， ok

def userlist(request):
    page = request.GET['page']
    rows = request.GET['rows']
    User_list = Userdb.objects.all().order_by('-id')
    alist=[]
    for i in User_list.values():
        alist.append(i)
    tl = len(alist)
    easy_list = []
    rs = rows
    a = int(page)-1
    b = int(rs)
    total = json.dumps(tl)
    if (a==0):
        a = 1
        if(b>len(alist)):
            ealist = {'rows':alist,'total':total}
        else:
            for s in range(a*b):
                easy_list.append(alist[s])
            ealist = {'rows':easy_list,'total':total}
    else:
        ss = alist[a*b:]
        if(len(ss)<b):
            ealist = {'rows':ss,'total':total}
        else:
            for i in range(a*b):
                easy_list.append(ss[i])
            ealist = {'rows':easy_list,'total':total}
    easylist = json.dumps(ealist,cls=CJsonEncoder)
    return HttpResponse(easylist)

//如果数据里面有时间的话，使用json.dumps（）会出错。下面这个函数就是处理这个问题

class CJsonEncoder(json.JSONEncoder):
    def default(self, obj):
        try:
            if isinstance(obj, datetime):
                 return obj.struct_time('%Y-%m-%d %H:%M:%S')
            elif isinstance(obj, date):
                da = str(obj.strftime('%Y-%m-%d'))
                #return obj.strftime('%Y-%m-%d')
                return da
            else:
                return json.JSONEncoder.default(self, obj)
        except Exception,e:
            print e
```

## task3

```python
import json
from django.core import serializers
from .models import UserInfo
def findByPage(request):
    res = '{"total":12,"rows":[{"id":1,"username":"admin","password":"admin","sex":"男","age":20},' \
          '{"id":2,"username":"admin","password":"admin","sex":"男","age":20},' \
          '{"id":3,"username":"admin","password":"admin","sex":"男","age":20},' \
          '{"id":4,"username":"admin","password":"admin","sex":"男","age":20},'\
           '{"id":5,"username":"admin","password":"admin","sex":"男","age":20},' \
           '{"id":6,"username":"admin","password":"admin","sex":"男","age":20},' \
           '{"id":7,"username":"admin","password":"admin","sex":"男","age":20},' \
           '{"id":8,"username":"admin","password":"admin","sex":"男","age":20},' \
           '{"id":9,"username":"admin","password":"admin","sex":"男","age":20},' \
           '{"id":10,"username":"admin","password":"admin","sex":"男","age":20},' \
           '{"id":11,"username":"admin","password":"admin","sex":"男","age":20},' \
          '{"id":12,"username":"admin","password":"admin","sex":"男","age":20}]}'

    page = request.GET.get("page")
    rows = request.GET.get("rows")
    list = UserInfo.objects.all()[:2]
    total = len(list)
    json_data = serializers.serialize("json",list)
    json_data = json.loads(json_data)
    resList = {"total":12,"rows":json_data}
    ulist = json.dumps(resList)
    return HttpResponse(res)
```

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>使用者列表頁面</title>
    <link href="/static/css/base.css" rel="stylesheet">
    <link rel="stylesheet" href="/static/easyui/uimaker/easyui.css">
    <link rel="stylesheet" type="text/css" href="/static/easyui/uimaker/icon.css">
    <script type="text/javascript" src="/static/jquery/jquery.min.js"></script>
    <script type="text/javascript" src="/static/easyui/jquery.easyui.min.js"></script>
    <script type="text/javascript" src="/static/easyui/easyui-lang-zh_CN.js"></script>
    <script type="text/javascript">
        $(function(){
            $("#tt").datagrid({
              title:"納稅人資訊",
              url:"/findByPage/",
              method:"GET",
              loadMsg:"資料載入中..",
              pagination:true,
              striped:true,
              columns:[[
               {field:"id","title":"編號",width:100,align:"center"},
                    {field:"username","title":"使用者名稱稱",width:100,align:"center"},
                    {field:"password","title":"使用者密碼",width:100,align:"center"},
                    {field:"sex","title":"性別",width:100,align:"center"},
                    {field:"age","title":"年齡",width:100,align:"center"},
                    {field:"opreation","title":"操作",formatter:function(value,rowData,index){
                    return "<a href='javascript:void(0)' onclick='detail("+rowData.id+")'>詳情   </a>"
                    +"<a href='javascript:void(0)' onclick='removeTaxPayer("+rowData.id+")'>刪除   </a>"
                    +"<a href='javascript:void(0)' onclick='edit("+rowData.id+")'>修改   </a>"
                    }}
              ]]
              })
        })

    </script>
</head>
<body>
    <table id="tt"></table>

</body>
</html>
```

