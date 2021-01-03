---
title: JQuery
date: 2019-05-05 10:00:00
tags: [Programming Language]
published: true
hideInList: false
feature: /post-images/jquery.png
---



[TOC]

# 一些函数

* css(name, value) 样式：在style里面写的，用css来操作。

  * name:样式名  value：样式值

  ```javascript
  $("#four").css("backgroundColor", "red");
  $(".green").css("backgroundColor", "green");
  $("li").css("color", "red");
  ```

* attr(name, value),用法和css一样，属性：在里面里面写的，用attr方法操作。

  * 对于布尔类型的属性，不要attr方法，应该用prop方法 prop用法跟attr方法一样。

  ```javascript
  $(function () {
      $("input").eq(0).click(function () {
        $("#ck").prop("checked", true);
      });
    
      $("input").eq(1).click(function () {
        $("#ck").prop("checked", false);
      });
    });
  ```

  

* show([speed], [callback])

  * speed:动画的持续时间  可以是毫秒值 还可以是固定字符串
  * callback回调函数

* index()会返回当前元素在所有兄弟元素里面的索引。

* 滑入滑出

  * 滑入：slideDown
  * 滑出：slideU

* 淡入淡出

  * 淡入：fadeIn  
  * 淡出：fadeOut    
  * 切换：fadeToggle

* 

# jQuery基本概念

## jQuery的入口函数

使用jQuery的三个步骤：

```javascript
1. 引入jQuery文件
2. 入口函数
3. 功能实现
```

关于jQuery的入口函数：

```javascript
//第一种写法
$(document).ready(function() {
	
});
//第二种写法
$(function() {
	
});
```

jQuery入口函数与js入口函数的对比

```javascript
1.	JavaScript的入口函数要等到页面中所有资源（包括图片、文件）加载完成才开始执行。
2.	jQuery的入口函数只会等待文档树加载完成就开始执行，并不会等待图片、文件的加载。
```

## jQuery对象与DOM对象的区别

```javascript
1. DOM对象：使用JavaScript中的方法获取页面中的元素返回的对象就是dom对象。
2. jQuery对象：jquery对象就是使用jquery的方法获取页面中的元素返回的对象就是jQuery对象。
3. jQuery对象其实就是DOM对象的包装集（包装了DOM对象的集合（伪数组））
4. DOM对象与jQuery对象的方法不能混用。

```

DOM对象转换成jQuery对象：

```javascript
var $obj = $(domObj);
// $(document).ready(function(){});就是典型的DOM对象转jQuery对象


```

jQuery对象转换成DOM对象：

```javascript
var $li = $(“li”);
//第一种方法（推荐使用）
$li[0]
//第二种方法
$li.get(0)


```

## $

* $其实就是一个函数，以后用$的时候，记得跟小括号 $();

* 3种用法

  * 参数是一个function, 入口函数

  ```javascript
  $(function () {
      
    });
    console.log(typeof $);
  ```

  * $(domobj)  把dom对象转换成jquery对象

  ```javascript
  $(document).ready(function () {
  
    });
  ```

  * 参数是一个字符串,用来找对象

  ```javascript
  $("div") $("div ul")   $(".current")
  ```

# 选择器

## 什么是jQuery选择器

jQuery选择器是jQuery为我们提供的一组方法，让我们更加方便的获取到页面中的元素。注意：jQuery选择器返回的是jQuery对象。

jQuery选择器有很多，基本兼容了CSS1到CSS3所有的选择器，并且jQuery还添加了很多更加复杂的选择器。【查看jQuery文档】

jQuery选择器虽然很多，但是选择器之间可以相互替代，就是说获取一个元素，你会有很多种方法获取到。所以我们平时真正能用到的只是少数的最常用的选择器。



## 基本选择器

| 名称       | 用法               | 描述                                 |
| ---------- | ------------------ | :----------------------------------- |
| ID选择器   | $(“#id”);          | 获取指定ID的元素                     |
| 类选择器   | $(“.class”);       | 获取同一类class的元素                |
| 标签选择器 | $(“div”);          | 获取同一类标签的所有元素             |
| 并集选择器 | $(“div,p,li”);     | 使用逗号分隔，只要符合条件之一就可。 |
| 交集选择器 | $(“div.redClass”); | 获取class为redClass的div元素         |

> 总结：跟css的选择器用法一模一样。

## 层级选择器

| 名称                 | 用法                   | 描述                                                        |
| -------------------- | ---------------------- | :---------------------------------------------------------- |
| 子代选择器           | $(“ul>li”);            | 使用>号，获取儿子层级的元素，注意，并不会获取孙子层级的元素 |
| 后代选择器           | $(“ul li”);            | 使用空格，代表后代选择器，获取ul下的所有li元素，包括孙子等  |
| 紧邻下一个元素选择器 | $("#id + .classname ") |                                                             |
| 兄弟元素选择器       | $("#id ~ .classname ") |                                                             |

> 跟CSS的选择器一模一样。

## 过滤选择器

> 这类选择器都带冒号:

| 名称         | 用法                               | 描述                                                        |
| ------------ | ---------------------------------- | :---------------------------------------------------------- |
| :odd         | $(“li:odd”).css(“color”, ”red”);   | 获取到的li元素中，选择索引号为奇数的元素                    |
| :even        | $(“li:even”).css(“color”, ”red”);  | 获取到的li元素中，选择索引号为偶数的元素                    |
| :eq（index） | $(“li:eq(2)”).css(“color”, ”red”); | 获取到的li元素中，选择索引号为2的元素，索引号index从0开始。 |
| :gt（index） | $("li:gt(2)")                      | 下标大于 2 的li                                             |
| :lt（index） | $("li:lt(2)")                      | 下标小于 2 的li                                             |
| :first       | $("li:first")                      | 第一个li                                                    |
| :last        | $("li:last")                       | 最后一个li                                                  |
| :not()       | $("li:not(#runoob)")               | 挑选除 id="runoob" 以外的所有li                             |

## 筛选选择器(方法)

> 筛选选择器的功能与过滤选择器有点类似，但是用法不一样，筛选选择器主要是方法。

| 名称               | 用法                        | 描述                             |
| ------------------ | --------------------------- | :------------------------------- |
| children(selector) | $(“ul”).children(“li”)      | 相当于$(“ul>li”)，子类选择器     |
| find(selector)     | $(“ul”).find(“li”);         | 相当于$(“ul li”),后代选择器      |
| siblings(selector) | $(“#first”).siblings(“li”); | 查找兄弟节点，不包括自己本身。   |
| parent()           | $(“#first”).parent();       | 查找父亲                         |
| eq(index)          | $(“li”).eq(2);              | 相当于$(“li:eq(2)”),index从0开始 |
| next()             | $(“li”).next()              | 找下一个兄弟                     |
| prev()             | $(“li”).prev()              | 找上一次兄弟                     |

## 内容过滤选择器

| 用法                       | 描述                         |
| -------------------------- | ---------------------------- |
| $("div:contains('Runob')") | 包含 Runob文本的元素         |
| $("td:empty")              | 不包含子元素或者文本的空元素 |
| $("div:has(selector)")     | 含有选择器所匹配的元素       |
| $("td:parent")             | 含有子元素或者文本的元素     |

## 可见性过滤选择器

| 用法            | 描述                                     |
| --------------- | ---------------------------------------- |
| $("li:hidden")  | 匹配所有不可见元素，或type为hidden的元素 |
| $("li:visible") | 匹配所有可见元素                         |

## 属性过滤选择器

| 用法                         | 描述                                       |
| ---------------------------- | ------------------------------------------ |
| $("div[id]")                 | 所有含有 id 属性的 div 元素                |
| $("div[id='123']")           | id属性值为123的div 元素                    |
| $("div[id!='123']")          | id属性值不等于123的div 元素                |
| $("div[id^='qq']")           | id属性值以qq开头的div 元素                 |
| $("div[id$='zz']")           | id属性值以zz结尾的div 元素                 |
| $("div[id*='bb']")           | id属性值包含bb的div 元素                   |
| $("input[id] [name$='man']") | 多属性选过滤，同时满足两个属性的条件的元素 |

## 状态过滤选择器

| 用法                 | 描述               |
| -------------------- | ------------------ |
| $("input:enabled")   | 匹配可用的 input   |
| ("input:disabled")   | 匹配不可用的 input |
| $("input:checked")   | 匹配选中的 input   |
| $("option:selected") | 匹配选中的 option  |

## 表单选择器

| 用法           | 描述                                                         |
| -------------- | ------------------------------------------------------------ |
| $(":input")    | 匹配所有 input, textarea, select 和 button 元素              |
| $(":text")     | 所有的单行文本框，$(":text") 等价于$("[type=text]")，推荐使用$("input:text")效率更高，下同 |
| $(":password") | 所有密码框                                                   |
| $(":radio")    | 所有单选按钮                                                 |
| $(":checkbox") | 所有复选框                                                   |
| $(":submit")   | 所有提交按钮                                                 |
| $(":reset")    | 所有重置按钮                                                 |
| $(":button")   | 所有button按钮                                               |
| $(":file")     | 所有文件域                                                   |

## 

# class操作

## 添加样式类

* addClass() - 向被选元素添加一个或多个类

```javascript
//name：需要添加的样式类名，注意参数不要带点.
addClass(name);
//例子,给所有的div添加one的样式。
$(“div”).addClass(“one”);
```

## 移除样式类

* removeClass() - 从被选元素删除一个或多个类

```javascript
//name:需要移除的样式类名
removeClass(“name”);
//例子，移除div中one的样式类名
$(“div”).removeClass(“one”);
```

## 判断是否有样式类

* hasClass（）用于判断的样式类名

```javascript
//name:用于判断的样式类名，返回值为true false
hasClass(name)
//例子，判断第一个div是否有one的样式类
$(“div”).hasClass(“one”);
```

## 切换样式类

* toggleClass() - 对被选元素进行添加/删除类的切换操作

```javascript
//name:需要切换的样式类名，如果有，移除该样式，如果没有，添加该样式。
toggleClass(name);
//例子
$(“div”).toggleClass(“one”);
```

# jQuery HTML

## jQuery - 获取内容和属性

* 获得内容
  * text() - 设置或返回所选元素的文本内容
  * html() - 设置或返回所选元素的内容（包括 HTML 标记）
  * val() - 设置或返回表单字段的值

```javascript
$("#btn1").click(function(){
  alert("Text: " + $("#test").text());
}); 

$("#btn2").click(function(){
  alert("HTML: " + $("#test").html());
});

$("#btn1").click(function(){
  alert("值为: " + $("#test").val());
});
```

* 获取属性 attr()

```javascript
$("button").click(function(){
alert($("#runoob").attr("href"));
});
```

## 添加新的 HTML 内容

* append() - 在被选元素的结尾插入内容
* prepend() - 在被选元素的开头插入内容
* after() - 在被选元素之后插入内容
* before() - 在被选元素之前插入内容

```javascript
$("p").append("追加文本");
$("p").prepend("在开头追加文本");
function appendText()
{
    var txt1="<p>文本。</p>";              // 使用 HTML 标签创建文本
    var txt2=$("<p></p>").text("文本。");  // 使用 jQuery 创建文本
    var txt3=document.createElement("p");
    txt3.innerHTML="文本。";               // 使用 DOM 创建文本 text with DOM
    $("body").append(txt1,txt2,txt3);        // 追加新元素
}

$("img").after("在后面添加文本");
$("img").before("在前面添加文本");
function afterText()
{
    var txt1="<b>I </b>";                    // 使用 HTML 创建元素
    var txt2=$("<i></i>").text("love ");     // 使用 jQuery 创建元素
    var txt3=document.createElement("big");  // 使用 DOM 创建元素
    txt3.innerHTML="jQuery!";
    $("img").after(txt1,txt2,txt3);          // 在图片后添加文本
}
//参数可以是个 list:
function afterText(){
    var txt1="<b>I </b>";                    // 使用 HTML 创建元素
    var txt2=$("<i></i>").text("love ");     // 使用 jQuery 创建元素
    var txt3=document.createElement("big");  // 使用 DOM 创建元素
    txt3.innerHTML="jQuery!";
    $("img").after([txt1,txt2,txt3]);          // 在图片后添加文本
}
```

## 删除元素

* remove() - 删除被选元素（及其子元素）
* empty() - 从被选元素中删除子元素

## jQuery 尺寸方法

* width() 方法设置或返回元素的宽度（不包括内边距、边框或外边距）
* height() 方法设置或返回元素的高度（不包括内边距、边框或外边距）

```javascript
$("button").click(function(){
  var txt="";
  txt+="div 的宽度是: " + $("#div1").width() + "</br>";
  txt+="div 的高度是: " + $("#div1").height();
  $("#div1").html(txt);
});
```

* innerWidth() 方法返回元素的宽度（包括内边距）
* innerHeight() 方法返回元素的高度（包括内边距）

```javascript
$("button").click(function(){
  var txt="";
  txt+="div 宽度，包含内边距: " + $("#div1").innerWidth() + "</br>";
    txt+="div 高度，包含内边距: " + $("#div1").innerHeight();
  $("#div1").html(txt);
});
```

* outerWidth() 方法返回元素的宽度（包括内边距和边框）
* outerHeight() 方法返回元素的高度（包括内边距和边框）

```javascript
$("button").click(function(){
  var txt="";
  txt+="div 宽度，包含内边距和边框: " + $("#div1").outerWidth() + "</br>";
  txt+="div 高度，包含内边距和边框: " + $("#div1").outerHeight();
  $("#div1").html(txt);
});
```

# jQuery 效果

## 隐藏和显示

*  $(*selector*).hide(*speed,callback*);
   *  隐藏HTML 元素
   *  可选的 speed 参数规定隐藏/显示的速度，可以取以下值："slow"、"fast" 或毫秒。
   *  可选的 callback 参数是隐藏或显示完成后所执行的函数名称。

* $(*selector*).show(*speed,callback*); 
  * 显示 HTML 元素

```javascript
$("#hide").click(function(){
  $("p").hide();
});
 
$("#show").click(function(){
  $("p").show();
});
```

* $(*selector*).toggle(*speed,callback*);
  * toggle() 方法来切换 hide() 和 show() 方法。显示被隐藏的元素，并隐藏已显示的元素

```javascript
$("button").click(function(){
  $("p").toggle();
});
```

## 淡入淡出

* $(*selector*).fadeIn(*speed,callback*);
  * fadeIn()用于淡入已隐藏的元素

```javascript
$("button").click(function(){
  $("#div1").fadeIn();
  $("#div2").fadeIn("slow");
  $("#div3").fadeIn(3000);
});
```

* $(*selector*).fadeOut(*speed,callback*);
  * fadeOut() 方法用于淡出可见元素

```javascript
$("button").click(function(){
  $("#div1").fadeOut();
  $("#div2").fadeOut("slow");
  $("#div3").fadeOut(3000);
});
```

* $(*selector*).fadeToggle(*speed,callback*);
  *  fadeToggle() 方法可以在 fadeIn() 与 fadeOut() 方法之间进行切换。如果元素已淡出，则 fadeToggle() 会向元素添加淡入效果。如果元素已淡入，则 fadeToggle() 会向元素添加淡出效果。

```javascript
$("button").click(function(){
  $("#div1").fadeToggle();
  $("#div2").fadeToggle("slow");
  $("#div3").fadeToggle(3000);
});
```

* $(*selector*).fadeTo(*speed,opacity,callback*);
  *  fadeTo() 方法允许渐变为给定的不透明度（opacity值介于 0 与 1 之间）

```javascript
$("button").click(function(){
  $("#div1").fadeTo("slow",0.15);
  $("#div2").fadeTo("slow",0.4);
  $("#div3").fadeTo("slow",0.7);
});
```

## 滑动

* $(*selector*).slideDown(*speed,callback*);
  * slideDown() 方法用于向下滑动元素

```javascript
$("#flip").click(function(){
  $("#panel").slideDown();
});
```

* $(*selector*).slideUp(*speed,callback*);
  * slideUp() 方法用于向上滑动元素

```javascript
$("#flip").click(function(){
  $("#panel").slideUp();
});
```

* $(*selector*).slideToggle(*speed,callback*);
  * slideToggle() 方法可以在 slideDown() 与 slideUp() 方法之间进行切换。如果元素向下滑动，则 slideToggle() 可向上滑动它们。如果元素向上滑动，则 slideToggle() 可向下滑动它们。

```javascript
$("#flip").click(function(){
  $("#panel").slideToggle();
});
```

## 动画

- animate()

  - 第一个参数：对象，里面可以传需要动画的样式
  - 第二个参数：speed 动画的执行时间
  - 第三个参数：动画的执行效果，默认swing缓动，可以是liner匀速
  - 第四个参数：回调函数

  ```javascript
  $(function () {
      $("input").eq(0).click(function () {
        $("#box1").animate({left:800}, 8000);
        //swing:秋千 摇摆
        $("#box2").animate({left:800}, 8000, "swing");
        //linear:线性 匀速
        $("#box3").animate({left:800}, 8000, "linear", function () {
          console.log("hahaha");
        });
      })
    });
  ```

- 停止动画

  - stop(clearQueue,jumpToEnd):停止当前正在执行的动画
    - clearQueue:是否清除动画队列 true  false
    - jumpToEnd:是否跳转到当前动画的最终效果 true false

# jQuery 遍历

## 祖先

* parent() 方法返回被选元素的直接父元素
* parents() 方法返回被选元素的所有祖先元素，它一路向上直到文档的根元素 (<html>)
  * 可以使用可选参数来过滤对祖先元素的搜索
* parentsUntil() 方法返回介于两个给定元素之间的所有祖先元素

## 后代

* children() 方法返回被选元素的所有直接子元素
* find() 方法返回被选元素的后代元素，一路向下直到最后一个后代

## 同胞

* siblings() 方法返回被选元素的所有同胞元素
* next() 方法返回被选元素的下一个同胞元素
* nextAll() 方法返回被选元素的所有跟随的同胞元素
* nextUntil() 方法返回介于两个给定参数之间的所有跟随的同胞元素
* prev()
* prevAll()  
* prevUntil()
  * 方法的工作方式与上面的方法类似，只不过方向相反而已：它们返回的是前面的同胞元素（在 DOM 树中沿着同胞之前元素遍历，而不是之后元素遍历）

## 过滤

* first() 方法返回被选元素的首个元素
* last() 方法返回被选元素的最后一个元素
* eq() 方法返回被选元素中带有指定索引号的元素
* filter() 方法允许您规定一个标准。不匹配这个标准的元素会被从集合中删除，匹配的元素会被返回
* not() 方法返回不匹配标准的所有元素

# jQuery特殊属性操作

## val方法

> val方法用于设置和获取表单元素的值，例如input、textarea的值

```javascript
//设置值
$("#name").val(“张三”);
//获取值
$("#name").val();
```



## html方法与text方法

> html方法相当于innerHTML  text方法相当于innerText

```javascript
//设置内容
$(“div”).html(“<span>这是一段内容</span>”);
//获取内容
$(“div”).html()

//设置内容
$(“div”).text(“<span>这是一段内容</span>”);
//获取内容
$(“div”).text()
```

区别：html方法会识别html标签，text方法会那内容直接当成字符串，并不会识别html标签。

## width方法与height方法

> 设置或者获取高度

```javascript
//带参数表示设置高度
$(“img”).height(200);
//不带参数获取高度
$(“img”).height();

```

获取网页的可视区宽高

```javascript
//获取可视区宽度
$(window).width();
//获取可视区高度
$(window).height();
```

## scrollTop与scrollLeft

> 设置或者获取垂直滚动条的位置

```javascript
//获取页面被卷曲的高度
$(window).scrollTop();
//获取页面被卷曲的宽度
$(window).scrollLeft();
```



## offset方法与position方法

> offset方法获取元素距离document的位置，position方法获取的是元素距离有定位的父元素的位置。

```javascript
//获取元素距离document的位置,返回值为对象：{left:100, top:100}
$(selector).offset();
//获取相对于其最近的有定位的父元素的位置。
$(selector).position();
```

# jQuery事件机制

> JavaScript中已经学习过了事件，但是jQuery对JavaScript事件进行了封装，增加并扩展了事件处理机制。jQuery不仅提供了更加优雅的事件处理语法，而且极大的增强了事件的处理能力。

## jQuery事件发展历程(了解)

简单事件绑定>>bind事件绑定>>delegate事件绑定>>on事件绑定(推荐)

> 简单事件注册

```javascript
click(handler)			单击事件
mouseenter(handler)		鼠标进入事件
mouseleave(handler)		鼠标离开事件
```

缺点：不能同时注册多个事件

> bind方式注册事件

```javascript
//第一个参数：事件类型
//第二个参数：事件处理程序
$("p").bind("click mouseenter", function(){
    //事件响应方法
});
```

缺点：不支持动态事件绑定

> delegate注册委托事件

```javascript
// 第一个参数：selector，要绑定事件的元素
// 第二个参数：事件类型
// 第三个参数：事件处理函数
$(".parentBox").delegate("p", "click", function(){
    //为 .parentBox下面的所有的p标签绑定事件
});

```

缺点：只能注册委托事件，因此注册时间需要记得方法太多了

> on注册事件

## on注册事件(重点)

> jQuery1.7之后，jQuery用on统一了所有事件的处理方法。
>
> 最现代的方式，兼容zepto(移动端类似jQuery的一个库)，强烈建议使用。

on注册简单事件

```javascript
// 表示给$(selector)绑定事件，并且由自己触发，不支持动态绑定。
$(selector).on( "click", function() {});

```

on注册委托事件

```javascript
// 表示给$(selector)绑定代理事件，当必须是它的内部元素span才能触发这个事件，支持动态绑定
$(selector).on( "click",“span”, function() {});


```

on注册事件的语法：

```javascript
// 第一个参数：events，绑定事件的名称可以是由空格分隔的多个事件（标准事件或者自定义事件）
// 第二个参数：selector, 执行事件的后代元素（可选），如果没有后代元素，那么事件将有自己执行。
// 第三个参数：data，传递给处理函数的数据，事件触发的时候通过event.data来使用（不常使用）
// 第四个参数：handler，事件处理函数
$(selector).on(events[,selector][,data],handler);


```

## 事件解绑

> unbind方式（不用）

```javascript
$(selector).unbind(); //解绑所有的事件
$(selector).unbind("click"); //解绑指定的事件

```

> undelegate方式（不用）

```javascript
$( selector ).undelegate(); //解绑所有的delegate事件
$( selector).undelegate( “click” ); //解绑所有的click事件

```

> off方式（推荐）

```javascript
// 解绑匹配元素的所有事件
$(selector).off();
// 解绑匹配元素的所有click事件
$(selector).off("click");

```

## 触发事件

```javascript
$(selector).click(); //触发 click事件
$(selector).trigger("click");

```

## jQuery事件对象

jQuery事件对象其实就是js事件对象的一个封装，处理了兼容性。

```javascript
//screenX和screenY	对应屏幕最左上角的值
//clientX和clientY	距离页面左上角的位置（忽视滚动条）
//pageX和pageY	距离页面最顶部的左上角的位置（会计算滚动条的距离）

//event.keyCode	按下的键盘代码
//event.data	存储绑定事件时传递的附加数据

//event.stopPropagation()	阻止事件冒泡行为
//event.preventDefault()	阻止浏览器默认行为
//return false:既能阻止事件冒泡，又能阻止浏览器默认行为。

```



# jQuery补充知识点

## 链式编程

> 通常情况下，只有设置操作才能把链式编程延续下去。因为获取操作的时候，会返回获取到的相应的值，无法返回 jQuery对象。

```javascript
end(); // 筛选选择器会改变jQuery对象的DOM对象，想要回复到上一次的状态，并且返回匹配元素之前的状态。

```

## each方法

> jQuery的隐式迭代会对所有的DOM对象设置相同的值，但是如果我们需要给每一个对象设置不同的值的时候，就需要自己进行迭代了。

作用：遍历jQuery对象集合，为每个匹配的元素执行一个函数

```javascript
// 参数一表示当前元素在所有匹配元素中的索引号
// 参数二表示当前元素（DOM对象）
$(selector).each(function(index,element){});

```

## 多库共存

> jQuery使用$作为标示符，但是如果与其他框架中的$冲突时，jQuery可以释放$符的控制权.

```javascript
var c = $.noConflict();//释放$的控制权,并且把$的能力给了c
```

# 插件

## 常用插件

> 插件：jquery不可能包含所有的功能，我们可以通过插件扩展jquery的功能。
>
> jQuery有着丰富的插件，使用这些插件能给jQuery提供一些额外的功能。

### jquery.color.js

> animate不支持颜色的渐变，但是使用了jquery.color.js后，就可以支持颜色的渐变了。

使用插件的步骤

```javascript
1. 引入jQuery文件
2. 引入插件（如果有用到css的话，需要引入css）
3. 使用插件

```

### jquery.lazyload.js

懒加载插件

### jquery.ui.js插件

jQueryUI专指由jQuery官方维护的UI方向的插件。

官方API：[http://api.jqueryui.com/category/all/](http://api.jqueryui.com/category/all/)

其他教程：[jQueryUI教程](http://www.runoob.com/jqueryui/jqueryui-tutorial.html)

基本使用:

```javascript
1.	引入jQueryUI的样式文件
2.	引入jQuery
3.	引入jQueryUI的js文件
4.	使用jQueryUI功能
```

## 制作jquery插件

> 原理：jquery插件其实说白了就是给jquery对象增加一个新的方法，让jquery对象拥有某一个功能。

```javascript
//通过给$.fn添加方法就能够扩展jquery对象
$.fn. pluginName = function() {};
```



