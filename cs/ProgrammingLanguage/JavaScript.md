---
title: javascript
date: 2019-04-24 10:00:00
tags: [Programming Language]
published: true
hideInList: false
feature: /post-images/JavaScript.png
---



[TOC]

- 基本数据类型：String   Number   Boolean   Null   Underined
- 引用数据类型：Object

### 一些函数

```html
<script type="text/javascript">js代码放到这里面</script>
```

```javascript
alert("弹出一个警告框");
```

```javascript
document.write("在body标签里面打印内容");
```

```javascript
console.log("在控制台打印内容");
```

```javascript
confirm("确认修改吗？");//用于弹出一个带有确认和取消按钮的提示框，需要一个字符串参数
```



* typeof用于检查数据类型

```javascript
var a = 1
console.log(typeof a);
```

* pronpt()可以弹出一个提示框，里面有一个文本框可以输入一端内容，该函数需要传入一段字符串，这段字符串可以作为提示信息

```javascript
prompt("请输入姓名");
可以用变量接收
var name = prompt("请输入姓名");
```

* parseInt()解析字符串函数：返回一个整数

```javascript
parseInt(string,radix);
//string:要解析的字符串
//radix:按进制解析，省略默认10进制
```

* console.time("计时器的名字")可以用来开启一个计时器，它需要一个字符串作为参数，这个字符串将作为计时器的标识

* console.timeEnd("计时器的名字")可以用来关闭一个计时器，也需要一个计时器的名字作为参数

```javascript
console.time("test");
console.timeEnd("test");
```

* Math.sqrt()可以对一个数开方

```javascript
var a =  Math.sqrt(97)
```

* tostring()换成字符串,该方法不会改变原来变量，会将转换的结果返回

```javascript
var a = 123;
var b = a.tostring();
console.log(typeof a);//number
console.log(a);//123
a = a.tostring();
console.log(typeof a);//string
console.log(a);//"123"
```

* string()函数，转换成字符串，并将被转换的数据作为参数传递给函数

```javascript
var a = 123;
a = string(a);
console.log(typeof a);//string
console.log(a);//"123"
```











###  if条件

```js
if (条件表达式){
    语句1;
    语句2;
}
```

```javascript
if (条件表达式){
    语句1;
}
else{
    语句2;
}
```

```javascript
if (条件表达式1){
    语句1;
    语句2;
}
else if (条件表达式2){
    语句;
}
else if (条件表达式3){
    语句;
}
else{
    语句;
}
```

```javascript
//一个优化 if 的方法
const condition = 2
let obj = {
  '1' : () => { document.write(1) },
  '2' : () => { document.write(2) },
  '3' : () => { document.write(3) },
}
obj[condition]()
```



### switch语句

* switch后表达式和case后的表达式进行全等比较

```javascript
//switch 中 case的判断是===的判断，即数据类型和值的双重判断，这点要注意。
//另外switch的判断条件可以是String 、Number、Boolean、char、枚举、null、undefined
switch(条件表达式)
{
    case 表达式:
    	语句1;
    	break;
    case 表达式:
    	语句2;
    	break;
    case 表达式:
    	语句3;
    	break;
}
```

```javascript
switch(条件表达式)
{
    case 表达式:
        语句1
        break;
    case 表达式:
        语句2
        break;
    default:
        与上面的case都不同时执行的语句
}
```

### while循环

```javascript
while(条件表达式)
{
    循环代码块;
}
```

```javascript
do
{
    循环代码块;
}
while (条件表达式);
```



### for循环

```javascript
for(初始化表达式;条件表达式;更新表达式)
{
    循环代码块;
}
```

```javascript
//for in 循环
//不仅可以遍历对象的属性，还可以遍历数组。
var x
var nums = [1, 3, 5];
for (x in nums)
{
    document.write(nums[x]+ "<br />");  // x 为数组索引
}
```

```javascript
//for...of 循环是 ES6 新引入的特性。它既比传统的for循环简洁，同时弥补了forEach和for-in循环的短板。
for (var value of myArray) {
  console.log(value);
}
// 10
// 20
// 30

//我们可以使用const来替代let，这样它就变成了在循环里的不可修改的静态变量。
let iterable = [10, 20, 30];
for (const value of iterable) {
  console.log(value);
}
// 10
// 20
// 30

//循环一个字符串：
let iterable = "boo";
for (let value of iterable) {
  console.log(value);
}
// "b"
// "o"
// "o"

//循环一个类型化的数组(TypedArray)：
let iterable = new Uint8Array([0x00, 0xff]);
for (let value of iterable) {
  console.log(value);
}
// 0
// 255

//循环一个Map:
let iterable = new Map([["a", 1], ["b", 2], ["c", 3]]);
for (let [key, value] of iterable) {
  console.log(value);
}
// 1
// 2
// 3
for (let entry of iterable) {
  console.log(entry);
}
// [a, 1]
// [b, 2]
// [c, 3]

//循环一个 Set:
let iterable = new Set([1, 1, 2, 2, 3, 3]);
for (let value of iterable) {
  console.log(value);
}
// 1
// 2
// 3

//循环一个 DOM collection
//循环一个DOM collections，比如NodeList，之前我们讨论过如何循环一个NodeList，现在方便了，可以直接使用for-of循环：
// Note: This will only work in platforms that have
// implemented NodeList.prototype[Symbol.iterator]
let articleParagraphs = document.querySelectorAll("article > p");
for (let paragraph of articleParagraphs) {
  paragraph.classList.add("read");
}

//循环一个拥有enumerable属性的对象
//for–of循环并不能直接使用在普通的对象上，但如果我们按对象所拥有的属性进行循环，可使用内置的Object.keys()方法：
for (var key of Object.keys(someObject)) {
  console.log(key + ": " + someObject[key]);
}

//循环一个生成器(generators)
//我们可循环一个生成器(generators):
function* fibonacci() { // a generator function
  let [prev, curr] = [0, 1];
  while (true) {
    [prev, curr] = [curr, prev + curr];
    yield curr;
  }
}
for (let n of fibonacci()) {
  console.log(n);
  // truncate the sequence at 1000
  if (n >= 1000) {
    break;
  }
}
```

#### break 语句用于跳出循环。break 可以用于循环和 switch 

#### continue 用于跳过循环中的一个迭代。 continue 只能用于循环

### 对象

```javascript
//new关键字调用的函数，是构造函数constructor
//构造函数是专门用来创建对象的函数：var 对象名 = new Object();
var obj = new Object();
//在对象中保存的值叫做属性
//添加属性(三种方法)
方法1：var 对象名 = {};
方法2：对象.属性名 = 属性值;
方法3：obj['属性名'] = '属性值';//中括号里面可以传变量
//删除属性
delete 对象名.属性名;
delete obj.name;
//in运算符：可以检查对象中是否含有某属性，对象中没有但是原型中有也会返回true
console.log(“属性名” in 对象名);
console.log(“name” in obj);
//使用对象的hasOwnProperty()来检查***对象自身***是否含有该属性
console.log(对象名.hasOwnProperty("属性名"));
console.log(obj.hasOwnProperty("name"));

//枚举对象中的属性,使用for...in语句，对象中有几个属性，循环就执行几次
for(var 变量名 in 对象){  
	console.log("属性名："+变量名);//取出属性名
    console.log("属性值："+对象[变量名])//取出属性值
}
```

### 函数

* 函数简介

```javascript
//创建函数对象
方法1：var 函数名 = new Function("一段代码");//这种方法一般不用
方法2：function 函数名([形参1,形参2,形参3]){
    函数语句;
    console.log("这是我的一个函数");
}
方法3：var 函数名 = function([形参1,形参2,形参3]){
    函数语句;
    console.log("这是我的一个函数");
};
//调用函数
函数名();
//立即执行函数
(function(){
    alert("我是一个匿名函数");
})();
(function(a,b){
    console.log("a = "+a);
    console.log("b = "+b);
})(123,456);
```

* 函数的方法

```javascript
//call()和apply()
//这两个方法都是函数对象的方法，需要函数对象调用
//当函数调用call()和apply()时，都会执行函数体
//在调用call()和apply()可以将一个对象指定为第一个参数
	//此时对线会成为函数执行时的this
//call()方法可以将实参在对象之后一次传递fun.call(obj,1,2);
//apply()方法需要将是餐封装到一个数组中同意传递fun.apply(obj,[1,2]);
function fun(){
    alert(this)
}
fun.call();
fun.apply();
//arguments
//在调用函数时，浏览器每次都会传递两个隐含的参数
	//函数的上下文对象this
	//封装实参的对象arguments
		//arguments是一个类数组对象，它也可以通过索引来操作数据，也可以获取长度
		//在调用函数时，我们所传递的实参都会在arguments中保存
		//arguments.length可以用来获取实参长度
		//我们即使不定义形参，也可以通过arguments来使用实参，arguments[0]表示第一个实参
//arguments里面有个属性callee，表示当前正在执行的函数对象
function fun(a,b){
    console.log(arguments);//"[object Arguments]"
    console.log(arguments instanceof Array);//"false"
    console.log(Array.isArray(arguments));//"false"
    console.log(arguments.length);//2
    console.log(arguments[1]);//true
    console.log(arguments.callee);//会打印出当前正在执行的函数对象，就是这个函数
}
fun("hello",true);
```

### 作用域

* window全局对象，它代表浏览器窗口，由浏览器创建我们可以直接使用，

* 在全局作用域中创建的对象都会作为window对象的属性保存，创建的函数都会作为window的方法保存

```javascript
var a = 10;
console.log(window.a)
function fun(){
    console.log("我是fun函数")
}
fun()
window.fun()//和上一行效果一样
```

* 在函数中调用全局变量，使用window对象

```javascript
window.变量名
```

* 在函数中不使用var声明的变量都会设置为全局变量

* 创建函数时定义的形参就相当于在函数作用域中声明了变量

### this

* this是个隐含参数，解析器每次调用函数都会向函数内部传递一个this
* this指向一个对象，这个对象称为函数执行的上下文对象
* 根据函数调用的方式不同，this会只想不同的对象
  * 以函数的形式调用时，this永远都是window
  * 以方法的形式调用时，this就是调用方法的那个对象，谁调用this就是谁
  * 以构造函数调用时，this就是那个新创建的对象
  * 使用call()和apply()调用时，this是指定的那个对象（在第一个参数指定）

### 工厂方法

#### 创建对象

```javascript
function person(name,age,gender){
    var obj = new Object();
    obj.name = name;
    obj.age = age;
    obj.gender = gender;
    obj.sayName = function(){
        alert(this.name);
    };
    return obj;
}
var obj1 = person('wkh','18','男');
var obj2 = person('wkh2','128','男');

```

### 构造函数

#### 创建类

* 使用同一个构造函数创建的对象，称为一类对象，也将一个构造函数称为一类
  * 我们通过一个构造函数创建的对象称为是该类的实例

* 构造函数创建时字母大写
* 普通函数直接调用，构造函数使用new关键字调用
* 构造函数执行流程
  * 调用构造函数是立刻创建一个新的对象
  * 将新建的对象设置为函数中的this，在构造函数中使用this来引用新建的对象
  * 逐行执行函数中的代码
  * 将新建的对象作为返回值返回

```javascript
function Person(name, age, gender){
    this.name = name;
    this.age = age;
    this.gender = gender;
    this.sayName = function(){
        alert(this.name);
    };
}
var per = new Person('wkh', 18, '男');
console.log(per)
```

* 使用instanceof函数检查一个对象是否是一个类的实例

  * 语法：对象名 instanceof 构造函数名

    ```javascript
    console.log(per instanceof Person);
    ```

### 原型prototype

* 每创建一个函数，解析器都会向函数中添加一个属性prototype，这个属性对应着一个对象，这个对象就是原型对象
* 函数以普通函数形式调用时，原型对象没有任何作用
* 函数以构造函数形式调用时，它所创建的对象中都会有一个隐含的属性指向该构造函数的原型对象
* 原型对象就相当于一个公共区域，所有同一个类的实例都可以访问这个原型对象，我们可以将对象中共有的内容设置到原型对象中
* 当访问一个对象的属性或方法时，它会先在自身中寻找，如果有则直接使用，如果没有，则会去原型对象中寻找

```javascript
function Myclass(){
    
}
var obj = new Myclass();
console.log(Myclass.prototype);
//访问该属性
//对象名.__proto__
console.log(obj.__proto__ == Myclass.prototype);
//向Myclass类的原型对象中添加公有属性
Myclass.protype.属性名 = 属性值;
Myclass.protype.a = 123;
console.log(obj.a)
//向Myclass类的原型对象中添加公有方法
Myclass.prototype.方法名 = function(){
    alert('hello world');
}
Myclass.prototype.sayHello = function(){
    alert('hello world');
}
obj.sayHello();
```

 ### 垃圾回收(GC)

* 浏览器自动处理，我们只需要将不再使用的变量设置为null

``` javascript
var obj = new Object();
obj = null;
```

### 数组

* 数组也是一个对象，也是用来存储一些值的
* 普通对象是使用字符串作为属性名，而数组使用数字来作为索引操作元素

* 数组的存储性能比普通对象号，常用数组存储数据

```javascript
//创建数组对象
方法1：var 数组名 = new Array(元素1，元素2，元素3);
	  var arr = new Array(1,2,3);//创建一个数组(1,2,3)
	  var arr = new Array(10);//创建一个长度为10的空数组
方法2：var arr = [元素1，元素2，元素3];
      var arr = [10];//创建的数组中只有一个元素10
//使用typeof检查数组时，会返回object
console.log(typeof 数组名);
console.log(typeof arr);//object
//向数组中添加元素
数组名[索引下标] = 值;
arr[0] = 10;
//读取数组中的元素,如果读取不存在索引，返回undefined
console.log(数组名[索引下标]);
console,log(arr[0]);
//length属性获取连续数组的长度，还可以修改数组长度
数组名.length;
console.log(arr.length);//返回数组长度
数组名.length = 10;
arr.length = 10;
//向数组末尾添加数据
数组名[数组名.length] = 数据;
arr[arr.length] = 20;
```

* 数组的几个方法

```javascript
//push()想数组的末尾添加一个或多个元素，并返回新数组的长度
var arr = [1,2,3];
//arr.push(4,5,6);
var result = arr.push(4,5,6);
console.log(arr);//"1,2,3,4,5,6"
console.log("result = "+result);//result = 6

//pop()该方法可以删除数组的最后一个元素,并返回被删除的元素
result = arr.pop();
console.log(arr);//"1,2,3,4,5"
console.log("result = "+result);//result = 6

//unshift()向数组的开头添加一个或多个元素，并返回新数组的长度
arr.unshift("w,k,h");
console.log(arr);//"w,k,h,1,2,3,4,5"

//shift()可以删除数组的第一个元素，并返回被删除的元素
result = arr.shift();
console.log(arr);//"k,h,1,2,3,4,5"
console.log("result = "+result);//result = w

//slice(start,end)传入开始位置索引和结束位置索引
//从某个已有的数组返回选定的元素,不会改变原数组
//左闭右开，包含开始位置的索引，不包含结束位置的索引
//第二个参数可以省略不写，此时会截取开始位置索引往后的所有元素
//如果传一个负值，则从后往前计算，开始是-1
var arr = [1,2,3,4,5,6];
var result = arr.slice(0,2);
console.log(arr);//"1,2,3,4,5,6"
console.log(result);//"3,4,5,6"

//splice(start,num, , ,...)删除指定元素，并向数组添加新元素，被删除的元素返回，并将会改变原数组
	//第一个参数：开始位置索引
	//第二个参数：删除的数量
	//第三个参数及以后：可以传递一些新的元素，这些元素自动插入到开始位置索引之前
var arr = [1,2,3,4,5,6];
var result = arr.aplice(0,2,w,k,h);
console.log(arr);//"w,k,h,3,4,5,6"
console.log(result);//"1,2"

//concat()连接两个或更多的数组，并返回结果,不会对原数组产生影响
var arr1 = [1,2,3];
var arr2 = [4,5,6];
var result = arr1.concat(arr2);
console.log(arr1);//"1,2,3"
console.log(arr1);//"4,5,6"
console.log(result);//"1,2,3,4,5,6"
var arr3 = [7,8,9];
var result1 = arr1.concat(arr2,arr3,"10","11")
console.log(result1);

//join()该方法可以将数组转换成一个字符串，不会对原数组产生影响
//在join()中可以指定一个字符串，这个字符串会成为数组元素的连接符，默认为“,”
var arr = [1,2,3];
var result = arr.join();
console.log(arr);//"1,2,3"
console.log(result);//"1,2,3"
console.log(typeof arr);//object
console.log(typeof result);//string
var result1 = arr.join("@");
console.log(result1);//"1@2@3"

//reverse()反转数组，会影响原数组
var arr = [1,2,3];
arr.reverse();
console.log(arr);//"3,2,1"

//sort()对数组中的元素按照Unicode编码排序，会影响原数组
var arr = ["d","a","b","e","c"];
arr.sort();
console.log(arr);//"a,b,c,d,e"
//对数字排序时可能出错，可以在sort()添加回调函数，浏览器会使用数组中的元素作为实参去调用回调函数
//浏览器会根据回调函数的返回值决定元素顺序
	//如果返回值大于0，元素会交换位置
	//如果返回值小于或等于0.元素位置不变
var arr2 = [2,3,11];
arr2.sort();
console.log(arr2);//"11,2,3"
var arr3 = [2,3,11];
arr3.sort(function(a,b){
    /*if(a>b){
        return 1;
    }else if(a<b){
        return -1;
    }else{
        return 0;
    }*/
    //升序
    //return a-b;
    //降序
    return b-a;
});
console.log(arr3)
```

* 数组的遍历

```javascript
//方法1：
var arr = [1,2,3];
for(var i=0 ; i<arr.length ; i++){
    console.log(arr[i]); 
}
//方法2：forEach()方法，用来遍历数组，仅支持IE8+
//forEach()需要一个函数作为参数,这个函数称为回调 函数，数组有几个元素函数就执行几次，每次执行时，浏览器会将遍历到的元素以实参的形式传递进来，我们可以定义形参来读取这些内容
//浏览器会在回调函数中传递三个参数
	//	第一个参数是当前正在遍历的元素value
	//	第二个参数是当前正在遍历的元素的索引index
	//	第三个参数是当前正在遍历的数组

var arr = [1,2,3,4,5,6];
arr.forEach(function(value,index,obj){
    //console.log("hello");
    console.log()
});
```

* 数组去重

```javascript
var arr = [1,4,3,6,5,4,1,1,5,2,6,5,2,7,4,8,9,6,3];
//获取数组中的每个元素
for(var i=0 ; i<arr.length ; i++){
    //console.log(arr[i]);
    //获取当前元素后的所有元素
    for(var j=i+1; j<arr.length ; j++){
        //console.log(arr[j]);
        //判断两个数是否相等
        if(arr[i] == arr[j]){
           //如果相等删除出现重复的元素，则删除j对应的元素
            arr.splice(j,1);
            //当删除了当前j位置的元素后，后面的元素会自动补位，此时不会在比较这个位置的元素，我们需要再一次比较j位置的元素
            //使j自减
            j--;
           }
    }
}
console.log(arr);
```

### Date对象

* 基本使用

```javascript
//在js中使用Date对象来表示时间
var d = new Date();
console.log(d);//输出当前时间
//创建一个指定的时间对象，需要在构造函数中传递一个表示时间的字符串作为参数
//格式：月/日/年 时:分:秒
var d = new Date("04/25/2019 11:15:06");
console.log(d);//输出指定时间
```

* 关于date的函数

```javascript
//getDate()获取当前日期对象中的几日
var d = new Date();
var date = d.getDate();
console.log(date);
//getDay获取当前日期对象中的周几
var d = new Date();
var day = d.getDay();
console.log(day);
//getMonth获取当前日期对象中的几月
var d = new Date();
var month = d.getMonth();
console.log(month);
//getFullYear获取当前日期对象中的年份
var d = new Date();
var year = d.getFullYear();
console.log(year);
//getTime获取当前日期对象的时间戳，从格林威治标准时间1970.01.01 00:00:00到当前日期所花费的毫秒数
var d = new Date();
var time = d.getTime();
console.log(time);
//获取当前的时间戳
time = Date.now();
console.log(time);//上一行代码执行时的时间戳
```

### Math

* Math和其他对象不同，他不是一个构造函数，不用创建对象，它里面封装了一些数学常用的公式

```javascript
//打印圆周率
console.log(Math.PI);//3.141592653587973
//abs()可以用来计算一个数的绝对值
console.log(Math.abs(-1));//1
//ceil()可以对一个数进行向上取整
console.log(Math.ceil(1.4));//2
//floor()可以对一个数进行向下取整
console.log(Math.floor(1.7));//1
//round()对一个数四舍五入取整
console.log(Math.round(1.4));//1
console.log(Math.round(1.7));//2
//random()可以用来生成一个0-1之间的随机数
console.log(Math.random());//0.31654687984654
console.log(Math.round(Math.(random()*x)));//Math.round(Math.(random()*x));生成一个0-x之间的随机整数
console.log(Math.round(Math.(random()*y-x)+x));//生随机证书成一个x-y之间的
//max()可以获取多个数中的最大值
var max = Math.max(10,30,50);
console.log(max);//50
//min()可以获取多个数中的最大值
var min = Math.min(10,30,50);
console.log(min);//10
//pow(x,y)返回x的y次幂
console.log(Math.pow(2,3));//8
//sqrt(x)对x开方
console.log(Math.sqrt(9));//3
```

### 包装类

* 基本数据类型：String   Number   Boolean   Null   Underined引用数据类型：Object
* 在JS中提供了三个包装类，可以将基本数据类型的数据转换为对象
  * String()可以将基本数据类型字符串转换为String对象
  * Number()可以将基本数据类型的数字转换为Number对象
  * Boolean()可以将基本数据类型的布尔值转换为Boolean对象
* 方法和属性只能添加给对象，不能添加给基本数据类型，当我们对一些基本数据类型添加属性和方法时，浏览器会临时使用包装类将其转换为对象，然后在调用对象的属性和方法，调用完成后，再将其转换为基本数据类型

```javascript
var num = new Number(3);
console.log(num);//3
console.log(typeof num);//object
num.hello = "abcdef";
console.log(num.hello);
var str = new String("hello");
console.log(str);//hello3
console.log(typeof str);//object
var bool = new Boolean(true);
console.log(bool);//true
console.log(typeof bool);//object
```

* String对象的方法

```javascript
var str = "Hello World";
//在底层字符串是以字符数组的形式保存的["H","e","l","l"]
console.log(str.length);//11
console.log(str[4]);//"o"
//charAt()可以返回字符串中指定索引位置的字符,不会影响原字符串
var str = "Hello World";
var result = str.charAt(6);
console.log(str);"Hello World"
console.log(result);"W"
//charCodeAt()获取指定位置字符的编码，返回Unicode编码,不会影响原字符串
var str = "Hello World";
var result = str.charCodeAt(1);
console.log(str);"Hello World"
console.log(result);"101"
//fromCharCode()可以根据字符编码去获取字符
var result = string.fromCharCode(72); 
console.log(result);"H"
//concat()可以用来连接两个或多个字符串,作用和+一样，不会影响原字符串
var str = "Hello World";
var result = str.concat("你好");
console.log(result);//"Hello World你好"
//indexOf()检索字符串是否含有指定内容,如果存在则返回第一次出现位置的索引,如果没有返回-1
//第二个参数可以指定开始查找的位置
var str = "Hello World";
var result = str.indexOf("l");
console.log(result);//2
var result2 = str.indexOf("l",1);
console.log(result2);//3
//lastIndexOf()从后向前搜索字符串,返回元素下标
//也可以指定第二个参数
var str = "Hello World";
var result = str.lastIndexOf("w");
console.log(result);//6
//slice()可以从字符串中截取指定的内容,不会影响原字符串
var str = "abcdefghijk";
var result = str.slice(0,2)//左闭右开
console.log(str);//"abcdefghijk"
console.log(result);//"ab"
//substring()可以用来截取一个字符串，和slice()类似
//第一个参数是开始位置的索引，第二个参数是结束位置的索引
//这个方法不能接受负值作为参数(默认负值为0)，并且自动调整参数位置，第一个要小于第二个
var str = "abcdefghijk";
var result = str.substring(1,2);
console.log(str);
console.log(result);
//substr()用来截取字符串，
	//第一个参数是开始位置的索引，第二个参数是截取的数量
var str = "abcdefghijk";
var result = str.substr(1,2);
console.log(str);
console.log(result);//bc
//split()可以将一个字符串拆分为一个数组,需要一个字符串作为参数，根据该字符串查分
//如果传递一个空串作为参数，则会将每个字符都茶分为数组中的元素
str = "abc,bcd,efg,hij";
var result = str.split(",");
console.log(str);
console.log(result);//"abc,bcd,efg,hij"
console.log(Array.isArray(result));//"true"
//toUpperCase()将字符串转换为大写并返回,不影响原字符串
var str = "abcdefg";
var result = str.toUpperCase();
console.log(result);//"ABCDEFG"
//toLowerCase()将字符串转换为小写并返回,不影响原字符串
var str = "ABCDEFG";
var result = str.toLowerCase();
console.log(result);//"abcdefg"
```

### 正则表达式

* 正则表达式.test("");
* 正则表达式.exce("");

* 使用构造函数创建正则表达式对象
  * var 变量名 = new RegExp("正则表达式","匹配模式");
    * 匹配模式
      * i：忽略大小写
      * g：全局匹配模式

```javascript
//var 变量名 = new RegExp("正则表达式","匹配模式");
var reg = new RegExp("a");//这个正则表达式可以用来检查字符串中是否含有a
console.log(reg);//"/a/"
console.log(typeof reg);//"object"使用typeof检查正则对象会返回object
var str = "a";
//正则表达式的方法
//test()可以用来检查一个字符串是否符合正则表达式的规则，符合返回true，否则返回false
var result = reg.test(str);
cosole.log(result);//true

```

* 使用字面量来创建正则表达式
  * var 变量名 = /正则表达式/匹配模式
* "[] == |"中括号和竖线都可以表示或
* {} 通过量词可以设置一个内容出现的次数
  * 量词会对它前边一个内容起作用
  * {n}出现n次
  * {m,n}出现m到n次
* []表示选择中括号中的一个
* +表示至少一个，相当于{1,}
* *表示至少0个，相当于{0,}
* ？表示0个或1个，相当于{0,1}
* ^：在中括号中表示除了……，在//中表示以……开头
* /w任意字母、数字和_
* /W除了字母、数字和_
* /d任意数字
* /D除了数字
* /s空格
* /S除了空格
* /b单词边界
* /B除了单词边界

```javascript
//var 变量名 = /正则表达式/匹配模式
//var reg = new RegExp("a", "i");
var reg = /a/i;//和上一句作用相同
console.log(reg.test("abc"));//true
//创建一个正则表达式，检查字符串中是否含有a或b或c
var reg = /a|b|c/;
var reg = /[abc]/;//"[] == |"中括号和竖线都可以表示或
//创建一个正则表达式检查字符串中是否有字母
var reg = /[a-z]/i;
var reg = /[A-z]/;
//检查一个字符串中是否含有abc或adc或aec
var reg = /a[bde]c/;
//检查字符串中是否含有除了ab的其他字符
var reg = /[^ab]/;
//检查一个字符串中是否含有aaa
var reg = /a{3}/;
//检查一个字符串是否以a开头
var reg = /^a/;
//检查一个字符串的结尾是否为a
var reg = /a$/;
//检查字符串中是否含有.
var reg = /\./;
//检查字符串中是否含有\
var reg = /\\/;
//检查一个字符串是否含有单词child
var reg = /\bchild\b/;
```

* 匹配手机号

```javascript
var phoneStr = "18437923722";
var phoneReg = /^1[3-9][0-9]{9}$/;
```

* 去除字符串中的空格

```javascript
//去除字符串中的空格
var str = "          he         llo               ";
str = str.replace(/\s/g,"");
console.log(str);
//去除字符串中开头空格
str = str.replace(/^\s*/,"");
//去除字符串中结尾空格
str = str.replace(/\s*$/,"");
//去除字符串中开头和结尾空格，保留中间的空格
str = str.replace(/^\s+|\s$/g,"");
```

### DOM

* Document Object Model可以通过js操作网页
* 节点
  * 文档节点：整个HTML文档
  * 元素节点：HTML文档中的标签
  * 属性节点：元素的属性
  * 文本节点：HTML标签中的文本内容

| 节点     | nodeName  | nodeType | nodeValue              |
| :------- | --------- | -------- | ---------------------- |
| 文本节点 | #document | 9        | null                   |
| 元素节点 | 标签名    | 1        | null                   |
| 属性节点 | 属性名    | 2        | 属性值                 |
| 文本节点 | #text     | 3        | 文本内容，标签间的空白 |

* 浏览器已经为我们提供了文档节点对象，这个对象时window属性，可以在页面中直接使用，文档节点是整个网页
* innerHTML属性用来获取标签(节点)中的内容，对自结束标签不起作用
* innerText属性可以获取到元素的文本内容，会将html标签去掉 
* 读取节点属性
  * 元素.属性名

```html
<html>
    <head> 
    </head>
    <body>
        <button id="btn">按钮按钮按钮</button>
        <script type="text/javascript">
        	//console.log(document);
            //获取button对象
        	var btn = decument.getElementById("btn");
        	console.log(btn);//[object HTMLButtonElement]
            //修改按钮的文本
            console.log(btn.innerHTML);//"按钮按钮按钮"
            btn.innerHTML = "i'm Button";
        </script>
    </body>
</html>
```

#### 获取元素节点

* 通过document对象调用：document.方法名
  * 方法getElementById()：通过id属性获取一个元素节点对象
  * 方法getElementsByTagName()：通过标签名过去一组元素节点对象
  * 方法getElementsByName()：通过name属性获取一组元素节点对象

```html
<html>
    <head> 
    </head>
    	<script type="text/javascript">
            window.onload = function(){
                //查找#bj节点
                var btn = document.getElementById("btn");//为按钮绑定一个单击响应函数
                btn.onclick = function(){ 
                    var bj = document.getElementById("bj");
                    //获取元素内部的html代码,通过innerHTML属性获取
                    alert(bj.innerHTML);
                };
                //查找所有li节点
                var btn = document.getElementById("btn");//为按钮绑定一个单击响应函数
                btn.onclick = function(){ 
                    var lis = document.getElementsByTagName("li"); //返回一个类数组对象
                    for(var i=0 ; i<lis.length ; i++){
                        alert(lis[i].innerHTML);
                    }
                };
                //查找所有name=gender的所有节点
                var btn = document.getElementById("btn");//为按钮绑定一个单击响应函数
                btn.onclick = function(){ 
                    var inputs = document.getElementsByName("gender"); 
                    for(var i=0 ; i<inputs.length ; i++){
                        //读取节点属性
                        alert(inputs[i].value);
                    }
                };
        </script>
    <body>
        <button id="btn">按钮按钮按钮</button>
    </body>
</html>
```

#### 获取元素节点的子节点

* 通过具体的元素节点调用：节点对象.属性；document.方法()
  * 方法getElementsByTagName()：返回当前节点的指定标签名后代节点
  * 属性childNodes：表示当前节点的所有子节点，包括元素节点、文本节点和文本节点间的空白
  * 属性firstChild：表示当前节点的第一个子节点，包括节点间的空白文本
  * 属性firstElementChild：获取当前元素的第一个子元素，不包括节点间的空白文本，但是IE8+
  * 属性lastChild：表示当前节点的最后一个子节点

```html
<html>
    <head> 
    </head>
    	<script type="text/javascript">
            window.onload = function(){
                //查找#city节点下的所有li节点
                var btn = document.("btn");//为按钮绑定一个单击响应函数
                btn.onclick = function(){ 
                    var city = document.getElementById("city");
                    var lis = document.getElementsByTagName("li");
                    for(var i-0 ; i<lis.length ; i++){
                        alert(lis[i].innerHTML);
                    } 
                }; 
                //查找#city节点下的所有子节点
                var btn = document.("btn");//为按钮绑定一个单击响应函数
                btn.onclick = function(){ 
                    var city = document.getElementById("city");
                    var cns = city.childNodes;
                    alert(cns.length);
                };
                //查找#phone节点下的第一个子节点
                var btn = document.("btn");//为按钮绑定一个单击响应函数
                btn.onclick = function(){ 
                    var phone = document.getElementById("phone");
                    //phone.childNodes[0];
                    var fir = phone.firstChild;
                    alert(fir);
                };
        </script>
    <body>
        <button id="btn">按钮按钮按钮</button>
    </body>
</html>
```

#### 获取父节点和兄弟节点

* 通过具体的节点调用
  * 属性parentNode：表示当前节点的父节点
  * 属性previousSibling：表示当前节点的前一个兄弟节点，也可能获取到空白文本
  * 属性previousElementSibling：表示当前元素的前一个兄弟元素，不包括空白文本，但是IE8+
  * 属性nextSibling：表示当前节点的后一个兄弟节点

```html
<html>
    <head> 
    </head>
    	<script type="text/javascript">
            //定义一个函数，用来为指定元素绑定单击响应函数
            //idstr要绑定单击响应函数的对象的id属性值
            //fun事件的回调函数，当单击元素时，该函数会被触发
            function myClick(idstr,fun){
                var btn = document.getElementById(idstr);
                btn.onclick = fun;
            }
         
            window.onload = function(){
                //返回#bj的父节点
                myclick("btn01",function(){
                    var bj = document.getElementById("bj");
                    var pn = bj.parentNodes;
                    alert(pn.innerText);
                })
                //返回#android的前一个兄弟节点
                myclick("btn02",function(){
                    var and = document.getElementById("android");
                    var ps = and.previousSibling;
                    alert(ps);
                })
                //返回#username的value属性值
                myclick("btn03",function(){
                    var um = document.getElementById("username");
                    //文本框的value属性值就是文本框中的内容
                    alert(um.value);
                })
                //设置或修改#username的value属性值
                myclick("btn04",function(){
                    var um = document.getElementById("username"); 
                    um.value = "hhhhhhhhh";
                })
                //获取#bj的文本值
                myclick("btn05",function(){
                    var bj = document.getElementById("bj");
                    alert(bj.innerHTML);
                })
            };  
        </script>
    <body>
        <button id="btn">按钮按钮按钮</button>
    </body>
</html>
```

#### DOM查询剩余方法

```html
<html>
    <head> 
        <meta charset="UTF-8">
        <title></title>
        <script type="text/javascript">
            
            window.onload = function(){
                //document.body获取body标签
                var body = document.body;
                console.log(body);
                //document.documentElement获取html跟标签
                var html = document.documentElement;
                console.log(html);
                //document.all代表页面中所有的元素
                //var all = document.getElementsByTagName("*");
                var all = document.all;
                console.log(all);//undefined
                console.log(all.length)
                for(var i=0 ; i<all.length ; i++){
                    console.log(all[i]);
                }
                //根据元素的class属性查询一组元素节点对象,IE8+
                var box1 = document.getElementsByClassName("box1");
                console.log(box1.length);
                //获取class为box1中的所有div
                //document.querySelector()需要一个选择器字符串作为参数,可以根据CSS选择器来查询一个元素节点对象
                //该方法只会返回唯一的元素，如果满足条件的有多个，会返回第一个
                var div = document.querySelector(".box1 div");
                console.log(div.innerHTML)
                //document.querySelectorAll()和上面方法一样，会把符合条件的多个元素封装到一个数组中返回
                var box1 = document.querySelectorAll(".box1");
                console.log(box1.length);
                console.log(box1);
            };
            
        </script>
    </head>
    <body>   
        <div class="box1">
            <div></div>
        </div>
        <div>
        </div>
    </body>
</html>
```

#### DOM增删改

* document.createElement();
  * 可以用于创建一个元素节点对象，它需要一个标签名作为参数，将会根据该标签名创建元素节点对象，并将创建好的对象作为返回值返回
* document.createText();
  * 可以用来创建一个文本节点对象，需要一个文本内容作为参数，将会根据该内容创建文本节点，并将新的节点返回
* 父节点.appendChild(子节点);
  * 向一个父节点中添加一个新的子节点
* 父节点.insertBefore(新子节点，旧子节点);
  * 在指定的旧子节点前插入新子节点
* 父节点.replaceChild(新子节点，旧子节点);
  * 使用指定的新子节点替换旧子节点
* 父节点.removeChild(子节点);
  * 可以删除一个子节点
* 子节点.parentNode.removeChild(子节点);
  * 可以删除一个子节点

```html
<html>
    <head> 
        <meta charset="UTF-8">
        <title></title>
        <script type="text/javascript">
            
            window.onload = function(){
                //创建一个广州节点，添加到#city下
                myClick("btn01",function(){
                    //方法1：
                    //创建广州节点<li>广州</li>
                	//创建li元素节点
                	var li = document.createElement("li");
                	//创建广州文本节点
                	var gzText = document.createText("广州");
                	//将广州文本节点添加到li子节点
                	li.appendChild(gzText);
                	//获取id为city的节点
                	var city = document.getElementById("city");
                	//将广州添加到city下
                	city.appendChild(li);
                    //方法2：
                    var city = document.getElementById("city");
                    city.innerHTML += "<li>广州</li>";
                    //方法3：以上两种综合使用 
                    var li = document.createElement("li");
                    li.innerHTML = "广州"；
                    city.appendChild(li);
                });
                //将"广州"节点添加到#bj前面
                myClick("btn02",function(){
                    var li = document.createElement("li");
                    var gzText = document.createTextNode("广州");
                    li.appendChild(gzText);
                    //获取id为bj的节点
                    var bj = document.getElementById("bj");
                    var city = document.getElementById("city");
                    city.insertBefore(li,bj);
                });
                //使用"广州"节点替换#bj节点
                myClick("btn03",function(){
                    var li = document.createElement("li");
                    var gzText = document.createTextNode("广州");
                    li.appendChild(gzText);
                    //获取id为bj的节点
                    var bj = document.getElementById("bj");
                    var city = document.getElementById("city");
                    city.replaceChild(li,bj);
                });
                //删除#bj节点
                myClick("btn04",function(){
                    //方法1：
                    var bj = document.getElementById("bj");
                    var city = document.getElementById("city");
                    city.removeChild(bj);
                    /方法2：
                    var bj = document.getElementById("bj");
                    bj.parentNode.removeChild(bj);
                });
            };
            
            function myClick(idStr,fun){
                var btn = document.getElementById(idStr);
                btn.onclick = fun;
            }
            
        </script>
    </head>
    <body>   
        <div id="total">
            <div class="inner">
                <p>
                    你喜欢哪个城市？
                </p>
                
                <ul id="city">
                    <li id="bj">北京</li>
                    <li>上海</li>
                    <li>东京</li>
                    <li>首尔</li>
                </ul>
            </div>
        </div>
    </body>
</html>
```

#### JS修改CSS样式

* 元素对象.style.样式名 = 样式值;
* 加入css样式名中含有-，比如background-color，这种要改成驼峰命名法，backgroundColor

```javascript
var box1 = document.getElementById("box1"); 
box1.style.width = "300px";
```

#### JS读取CSS样式

* 读取内联样式
  * 元素对象.style.样式名
* 读取元素当前显示的样式
  * 元素对象.currentStyle.样式名;***仅仅兼容IE***
  * window. getComputedStyle();***支持其他浏览器***
    * 该方法会返回一个对象，对象中封装了当前元素对应的样式
    * 第一个参数：要获取样式的元素
    * 第二个参数：可以传递一个伪元素，一般都传null

```js
var box1 = document.getElementById("box1"); 
alert(box1.style.width);//只能读取内联样式
alert(box1.currentStyle.width);//读取当前显示的样式
var obj = window.getComputedStyle(box1,null);//读取当前显示的样式
console.log(obj.width); 
```

* 其他样式操作属性：元素对象.属性名
  * clientWidth
  * clientHeight
    * 获取元素的可见宽度和高度，包括内容区***width***和内边距***padding***，不带px，只读不能修改
  * offsetWidth
  * offsetHeight
    * 获取元素的的整个宽度，包括内容区***width***、内边距***padding***和边框***border***，只读不能将修改
  * offsetParent
    * 可以用来获取当前元素的定位父元素
    * 会获取到离当前元素最近的开启了定位（position不等于static）的祖先元素
    * 如果祖先元素都没有开启定位，则返回body'
  * offsetLeft
    * 当前元素相对于其定位元素的水平偏移量 
  * offsetTop
    * 当前元素相对于其定位元素的垂直偏移量
  * scrollWidth
  * scrollHeight
    * 获取当前元素滚动区域的高度和宽度
  * scrollLeft
    * 可以获取当前元素水平滚动条滚动的距离
  * scrollTop
    * 可以获取当前元素垂直滚动条滚动的距离

```javascript
var box1 = document.getElementById("box1"); 
alert(box1.clientWidth);
alert(box1.clientHeight);
alert(box1.offsetWidth);
alert(box1.offsetHeight);
alert(box1.offsetParent);
alert(box1.offsetLeft);
alert(box1.offsetTop);
```

### 文档的加载

- 浏览器加载页面的顺序是自上而下的，读一行执行一行，如果将script标签写到页面的上面，在代码执行时页面还没有加载 （DOM对象也没有加载），将js代码编写到页面代码的下部，就可以实现页面加载完在执行js代码
- onload()事件会在整个页面加载完成后触发，为window绑定一个onload事件
- 这样可以确保我们的代码执行时所有的DOM树已经加载完毕

```html
<html>
    <head>
         <script type="text/javascript">
             window.onload = function(){
                 //获取按钮对象
            	var btn = document.getElementById("btn");
                  //绑定一个单击事件
                btn.onclick = function(){
                  alert("lalala");
                };
             };
        </script>
    </head>
    <body> 
        <button id="btn">按钮按钮按钮</button>
    </body>
</html>
```





### 事件

#### 事件简介

* 事件就是用户与浏览器的交互行为，JavaScript与HTML之间的交互是通过事件实现
  * 鼠标点击、鼠标移动、按下键盘、关闭窗口等等
* 我们可以在事件对应的属性中设置一些JS代码，当事件被触发时，这些代码会被执行

```html
<html>
    <head> 
    </head>
    <body>
        <!--这种写法称为结构和行为耦合，不方便维护-->
        <!--<button id="btn" onclick="alert('hello!');">按钮按钮按钮</button>-->
        <button id="btn">按钮按钮按钮</button>
        <script type="text/javascript">
            //获取按钮对象
            var btn = document.getElementById("btn");
            //可以为按钮的对应事件绑定处理函数的形式来响应事件,当事件被触发时，其对应的函数会被调用
            //绑定一个单击事件
            btn.onclick = function(){//像这种为单击事件绑定的函数，我们称为单击响应函数
              alert("lalala");  
            };
        </script>
    </body>
</html>
```

* 对象.事件名 = function(){};

* onmousemove
  *  鼠标在元素中移动时触发

```javascript

```

#### 事件对象

* 当事件的响应函数被触发时，浏览器每次都会将一个事件对象作为实参传递到响应函数
  * 在事件对象中，封装了当前事件相关的一切信息，比如鼠标坐标，键盘按下那个键，滚轮方向等

#### 事件冒泡（Bubble）

* 所谓的时间冒泡就是事件的向上传导，当后代元素上的事件被触发时，其祖先元素的相同事件也会被触发

```html
<html>
    <head> 
         <script type="text/javascript">
            var s1 = document.getElementById("s1");
             s1.onclick = function(event){
               //解决兼容性问题
               //event = event || window.event;
                 alert("123456");
                 //取消事件冒泡
                 event.cancelBubble = true;
             };
        </script>
    </head>
    <body>
        <div id="s3">
            <div id="s2">
                <div id="s1">
                    
                </div>
            </div>
        </div>
    </body>
</html>
```

#### 事件绑定

```javascript
//方法一：
对象.事件名 = function(){};
btn1.onclick = function(){
	alert("hhhhhh");
};
//方法二：IE8+
	//可以为同一个事件绑定多个函数,顺序执行
	//参数：
		//事件名字符串，不要on
		//回调函数，当事件触发时该函数会被调用
		//是否在捕获阶段触发事件，一个布尔值，一般都为false
对象.addEventListener('事件名'.function(){},false);
btn1.addEventListener('click'.function(){
                      alert("hhhhhh");
                      },false);
//方法三：IE8,可以同时为一个事件绑定多个函数
对象.attachEvent('事件名'.function(){});
btn1.attachEvent('click'.function(){
                      alert("hhhhhh");
                      });
```

#### 定义一个函数，为指定元素绑定响应函数，兼容所有浏览器

```javascript
//需要统一两个方法的this
	//addEventListener()中的this是绑定时间的对象
	//attachEvent()中的this是window
//参数
	//obj要绑定事件的对象
	//eventStr事件的字符串（不要on）
	//callback回调函数
function bind(obj , eventStr , callback){
    
    if(obj.addEventListener){
        //大部分浏览器兼容的方式
    	obj.addEventListener(eventStr,callback,false);
    }else{ 
        //IE+及以下
    	//obj.attachEvent("on"+eventStr,callback);
        //this是谁由调用方式决定，
        //callback.call(obj);可以修改函数的this
        obj.attachEvent("on"+eventStr,function(){
            //在匿名函数中调用回调函数
            callback.call(obj);
        });
    }
 
}
```

#### 事件拖拽

* 拖拽box1

```javascript
window.onload = function(){
    var box1 = document.getElementById('box1');
    //绑定鼠标按下事件
    box1.onmousedown = function(event){
        //设置box1捕获所有鼠标按下事件，仅ie8-
        box1.setCapture && box1.setCapture();
        
        event = event||window.event;
        //计算鼠标点下时的位置，div的偏移量
        //鼠标.clientX - 元素.offsetLeft
        //鼠标.clientY - 元素.offsetTop
        var ol = event.clientX - box1.offsetLeft;
        var ol = event.clientY - box1.offsetTop;
        //绑定鼠标移动事件
        document.onmousemove = function(event){
            event = event||window.event;
            //获取鼠标位置坐标
            var left = event.clientX;
            var top = event.clientY;
            //修改box1的位置
            box1.style.left = left+"px";
            box1.style.top = top+"px";
        };
        //绑定鼠标抬起事件
        document.onmouseup = function(){
            //取消document的onmousemove事件
            document.onmousemove = null;
            //取消document的onmouseup事件
            document.onmouseup = null;
            //当鼠标松开时取消捕获，仅ie8-
            box1.releaseCapture && box1.releaseCapture();
        }; 
        //当我们拖拽页面中的内容时，浏览器会自动去搜索内容
        //这是浏览器的默认行为，可以通过return false;这个只对IE8+起作用
        return false;//IE8+
        //IE8-游览器可以在前面设置setCapture()
    };
};
```

* 定义一个通用的拖拽函数

```javascript
function drag(obj){
    //绑定鼠标按下事件
    obj.onmousedown = function(event){
        //设置obj捕获所有鼠标按下事件，仅ie8-
        obj.setCapture && obj.setCapture();
        
        event = event||window.event;
        //计算鼠标点下时的位置，div的偏移量
        //鼠标.clientX - 元素.offsetLeft
        //鼠标.clientY - 元素.offsetTop
        var ol = event.clientX - obj.offsetLeft;
        var ol = event.clientY - obj.offsetTop;
        //绑定鼠标移动事件
        document.onmousemove = function(event){
            event = event||window.event;
            //获取鼠标位置坐标
            var left = event.clientX;
            var top = event.clientY;
            //修改obj的位置
            obj.style.left = left+"px";
            obj.style.top = top+"px";
        };
        //绑定鼠标抬起事件
        document.onmouseup = function(){
            //取消document的onmousemove事件
            document.onmousemove = null;
            //取消document的onmouseup事件
            document.onmouseup = null;
            //当鼠标松开时取消捕获，仅ie8-
            obj.releaseCapture && obj.releaseCapture();
        }; 
        //当我们拖拽页面中的内容时，浏览器会自动去搜索内容
        //这是浏览器的默认行为，可以通过return false;这个只对IE8+起作用
        return false;//IE8+
        //IE8-游览器可以在前面设置setCapture()
    };
}
```

#### 滚轮事件

* onmousewheel鼠标滚轮滚动事件，鼠标滚动时触发，但是火狐不兼容
  * box1.onmousewheel = function(){};
* DOMMouseScroll火狐中使用的滚轮轮动事件，
  * 该事件需要通过addEvnetListener()函数来绑定 
  * bind(box1,"DOMMouseScroll",function(){});

#### 键盘事件

* 键盘事件一般都会绑定给可以获取焦点的事件

* onkeydown按键按下
* onkeyup按键松开



### BOM

* 浏览器对象模型，BOM可以使我们通过JS操作浏览器
* BOM对象
  * Window
    * 代表整个浏览器的窗口，同时window也是网页中的全局对象
  * Navigator
    * 代表当前浏览器的信息，通过该对象可以识别不同浏览器
  * Location
    * 代表当前浏览器的地址栏，通过Location可以获取地址栏信息，或者操作浏览器跳转页面
  * History
    * 代表浏览器的历史记录，通过该对象来操作浏览器的历史记录
    * 由于隐私原因，该对象不能获取到具体的历史记录，只能操作浏览器向前或向后翻页，
    * 而且该操作只在档次访问时有效
  * Screen
    * 代表用户屏幕的信息，通过该对象可以获取到用户的显示器的相关信息
* 这些对象在浏览器中都是作为window对象的属性保存的，可以通过window对象来使用，也可以直接使用

```javascript
console.log(window);
console.log(navigator);
console.log(window.navigator);
console.log(navigator.userAgent);
console.log(location);
console.log(history);
```

#### Navigator

* 代表当前浏览器的信息，通过该对象可以识别不同浏览器
* 由于历史原因，Navigator对象中的大部分属性已经不能帮助我们识别浏览器了
* 一般我们只会使用userAgent来判断浏览器信息

```javascript
console.log(navigator.appName);//不能识别
var ua = console.log(navigator.userAgent);//可以识别

if(/firefox/i.test(ua)){
   console.log("我是火狐");
}else if(/chrome/i.test(ua)){
   console.log("我是chrome");
}else if(/msie/i.test(ua)){
    console.log("我是IE11-，不包括IE11");
};
//通过ie里的特有属性判断
if("ActiveXObject" in window){
   console.log("我是IE，不包括IE11");
}else{
    console.log("不是IE");
}
```

#### History

* 通过Location可以获取地址栏信息，或者操作浏览器向前向后翻页
* 属性
  * length
    * 返回当前访问的链接数量
* 方法
  * back()
    * 可以用来退回到上一个页面，类似返回按钮
  * forward()
    * 可以跳转到到下一个页面，类似前进按钮
  * go()
    * 可以用来跳转到指定页面，需要一个整数作为参数

```javascript
console.log(history.length);
history.back();
history.forward();
history.go(1);//向前跳转一个页面
history.go(-2);//向后跳转两个页面
```

#### Location

- 该对象中封装了浏览器地址栏信息
- 如果直接打印location，则可以获取地址栏信息
- 如果直接将location属性修改为一个完整的路径，或相对路径，则我们页面会自动跳转到该路径，并且会生成响应的历史记录
- 属性
- 方法
  - assign()
    - 用来跳转到其他页面，作用和直接修改location一样
  - reload()
    - 重新加载当前页面，和刷新按钮一样
    - 如果在方法中传递一个true作为参数，强制清空缓存刷新
  - replace()
    - 可以使用一个新的页面替换当前页面，调用完毕也会跳转页面
    - 不会生成历史记录，不能回退

```javascript
console.log(location);
location = "www.google.com";
location.assign("https://www.google.com");
location.reload();
location.reload(true);
location.replace("www.google.com");
```

#### Screen

```javascript
console.log(screen);
```

#### Window

- 属性
- 方法
  - setInterval()
    - 定时调用，可以将一个函数每隔一段时间执行一次
    - 参数
      1. 回调函数。该函数会每隔一段时间调用一次
      2. 每次间隔的时间，单位毫秒
    - 返回值
      - 返回一个Number类型的数据，这个数字作为定时器的唯一标识
  - clearInterval()
    - 关闭定时器，传入定时器的返回值
  - setTimeout()
  - clearTimeout()

```javascript
console.log(window);
//定时调用
var count = document.getElementById("count");
var num = 1;
var timer = setInterval(function(){
    count.interHTML = num++;
    if(num == 10){
       clearInterval(timer);
       }
},1000);
//console.log(timer);
```









































































