---
title: Mysql
date: 2019-05-13 09:44:26
tags: [Database]
published: true
hideInList: false
feature: /post-images/mysql.jpg
---
[TOC]

Insert into 表名()  values()

Delete from 表名 where 

Update 表名 set … where

Select [字段列表、表达式、函数] from 表名

# 数据库简介

## E-R 模型

- 当前物理的数据库都是按照 E-R 模型进行设计的 
- E 表示 entry，实体 
- R 表示 relationship，关系 

## 三范式

> 经过研究和对使用中问题的总结，对于设计数据库提出了一些规范，这些规范被称为范式，后一个范式，都是在前一个范式的基础上建立的 

- 第一范式（1NF)：列不可拆分
- 第二范式（2NF)：唯一标识
- 第三范式（3NF)：引用主键 

## 字段类型

- 数字：int,decimal 
- 字符串：varchar,text 
- 日期：datetime 
- 布尔：bit 

## 约束

- 主键 primary key 
- 非空 not null 
- 惟一 unique 
- 默认 default 
- 外键 foreign key 

## Mysql注释

```mysql
#注释语句
"--  注释语句"
/*注释语句*/
```



## 数据库一些操作命令

- select - 从数据库提取数据
- update - 更新数据库中的数据
- delete - 从数据j库删除数据
- insert into - 向数据库插入新数据
- create database - 创建新的数据库
- alter database - 修改数据库
- create table - 创建新表
- alter table - 变更数据库表
- drop table - 删除表
- create index - 创建索引
- drop index - 删除索引

# 数据库操作

## 插入数据

```mysql
INSERT INTO table_name 
VALUES (value1,value2,value3,...);

INSERT INTO table_name (column1,column2,column3,...) 
VALUES (value1,value2,value3,...); 
```

## 删除数据

```mysql
#删除某条记录
DELETE FROM table_name 
WHERE some_column=some_value; 

#清空数据表
DELETE FROM table_name; 
DELETE * FROM table_name;
```

## 修改数据

```mysql
UPDATE table_name 
SET column1=value1,column2=value2,... 
WHERE some_column=some_value; 
```

## 查询数据

```mysql
SELECT column_name,column_name 
FROM table_name; 
SELECT * FROM table_name;
```

### DISTINCT 关键词用于返回唯一不同的值

```MYSQL
SELECT DISTINCT column_name,column_name 
FROM table_name; 
```

### WHERE 子句用于过滤记录，用于提取那些满足指定标准的记录。 

```mysql
SELECT column_name,column_name 
FROM table_name 
WHERE column_name operator value;
```

### AND & OR 运算符用于基于一个以上的条件对记录进行过滤。

- 如果第一个条件和第二个条件都成立，则 AND 运算符显示一条记录。
- 如果第一个条件和第二个条件中只要有一个成立，则 OR 运算符显示一条记录

### ORDER BY 关键字用于对结果集进行排序。 

```mysql
SELECT column_name,column_name 
FROM table_name 
ORDER BY column_name,column_name ASC|DESC;
```

# 查询操作

## 条件

```mysql
select * from 表名 where 条件;
```

### 比较运算符

* 等于=
* 大于>
* 大于等于>=
* 小于<
* 小于等于<=
* 不等于!=或<>

### 逻辑运算符

* and
* or
* not

### 模糊查询

* %表示任意多个任意字符
* _表示一个任意字符

```mysql
#查询姓黄的学生
select * from students where sname like '黄%'; 
#查询姓黄并且名字是一个字的学生
select * from students where sname like '黄_';
#查询姓黄或叫靖的学生
select * from students where sname like '黄%' or sname like '%靖%';
```

### 范围查询

* in表示在一个非连续的范围内
* between ... and ...表示在一个连续的范围内

```mysql
#查询编号是 1 或 3 或 8 的学生
select * from students where id in(1,3,8); 
#查询学生是 3 至 8 的学生
select * from students where id between 3 and 8; 
```

### 空判断

* is null
* is not null 

```mysql
#查询没有填写地址的学生
select * from students where hometown is null; 
#查询填写了地址的学生
select * from students where hometown is not null; 
#查询填写了地址的女生
select * from students where hometown is not null and gender=0; 
```

## 聚合

*  count(*)表示计算总行数，括号中写星与列名，结果是相同的 
* max(列)表示求此列的最大值 
* min(列)表示求此列的最小值 
* sum(列)表示求此列的和 
* avg(列)表示求此列的平均值 

```mysql
#查询学生总数: 
select count(*) from students; 
#查询女生的编号最大值: 
select max(id) from students where gender=0; 
#查询未删除的学生最小编号: 
select min(id) from students where isdelete=0; 
#查询男生的编号之后: 
select sum(id) from students where gender=1; 
#查询未删除女生的编号平均值: 
select avg(id) from students where isdelete=0 and gender=0; 
```

## 分组

```mysql
select 列 1,列 2,聚合... 
from 表名 
group by 列 1,列 2,列 3... 
#分组后的数据筛选: 
select 列 1,列 2,聚合... 
from 表名 
group by 列 1,列 2,列 3... 
having 列 1,...聚合..
```

### 对比 where 与 having

* where 是对 from 后面指定的表进行数据筛选，属于对原始数据的筛选
* having 是对 group by 的结果进行筛选

## 排序

```mysql
select * from 表名 
order by 列 1 asc|desc,列 2 asc|desc,... 
```

##  分页 

```mysql
#从 start 开始，获取 count 条数据 start 索引从 0 开始
select * from 表名 
limit start,count

```

## 一条完整的select语句

```mysql
select distinct * 
from 表名 
where .... 
group by ... having ... 
order by ... 
limit start,count

```

* 执行顺序
  * from 表名 
  * where .... 
  * group by ... 
  * select distinct * 
  * having ... 
  * order by ... 
  * limit start,count 

# 函数操作

## 操作

* restrict（限制）：默认值，抛异常 
* cascade（级联）：如果主表的记录删掉，则从表中相关联的记录都将被删除 
* set null：将外键设置为空 
* no action：什么都不做 

## 连接

* 表 A inner join 表 B：表 A 与表 B 匹配的行会出现在结果中 
* 表 A left join 表 B：表 A 与表 B 匹配的行会出现在结果中，外加表 A 中独有的数据，未 对应的数据使用 null 填充 
* 表 A right join 表 B：表 A 与表 B 匹配的行会出现在结果中，外加表 B 中独有的数据， 未对应的数据使用 null 填充 
* 在查询或条件中推荐使用“表名.列名”的语法 如果多个表中列名不重复可以省略“表名.”部分 

```mysql
select students.sname,subjects.stitle,scores.score 
from scores 
inner join students on scores.stuid=students.id 
inner join subjects on scores.subid=subjects.id;
```

## 字符串函数

```mysql
#查看字符的 ascii 码值 ascii(str)，str 是空串时返回 0: 
select ascii('a'); 
 
#查看 ascii 码值对应的字符 char(数字): 
select char(97); 
 
#拼接字符串 concat(str1,str2...): 
select concat(12,34,'ab'); 
 
#包含字符个数 length(str): 
select length('abc');
```

### 截取字符串

* left(str,len)返回字符串 str 的左端 len 个字符
* right(str,len)返回字符串 str 的右端 len 个字符 
* substring(str,pos,len)返回字符串 str 的位置 pos 起 len 个字符 

```mysql
select substring('abc123',2,3);
```



### 去除空格:

* ltrim(str)返回删除了左空格的字符串 str 
* rtrim(str)返回删除了右空格的字符串 str 
* trim([方向 remstr from str)返回从某侧删除 remstr 后的字符串 str，方向词包括 both、 leading、trailing，表示两侧、左、右
* 返回由 n 个空格字符组成的一个字符串 space(n): 

- 替换字符串 replace(str,from_str,to_str): 

```mysql
select trim('  bar   '); 
select trim(leading 'x' FROM 'xxxbarxxx'); 
select trim(both 'x' FROM 'xxxbarxxx'); 
select trim(trailing 'x' FROM 'xxxbarxxx'); 
select space(10);
select replace('abc123','123','def');
```



### 大小写转换 

* lower(str) 
* upper(str)

```mysql
select lower('aBcD');
```

### 数学函数

```mysql
求绝对值 abs(n): 
select abs(-32); 
 
求 m 除以 n 的余数 mod(m,n)，同运算符%: 
select mod(10,3); 
select 10%3; 
 
地板 floor(n)，表示不大于 n 的最大整数: 
select floor(2.3); 
 
天花板 ceiling(n)，表示不小于 n 的最大整数: 
select ceiling(2.3); 
 
求四舍五入值 round(n,d)，n 表示原数，d 表示小数位置，默认为 0: 
select round(1.6);

求 x 的 y 次幂 pow(x,y): 
select pow(2,3); 
 
获取圆周率 PI(): 
select PI(); 
 
随机数 rand()，值为 0-1.0 的浮点数: 
select rand(); 
```

### 日期时间函数: 

* year(date)返回 date 的年份(范围在 1000 到 9999) 
* month(date)返回 date 中的月份数值 
* day(date)返回 date 中的日期数值 
* hour(time)返回 time 的小时数(范围是 0 到 23) 
* minute(time)返回 time 的分钟数(范围是 0 到 59) 
* second(time)返回 time 的秒数(范围是 0 到 59) 

# 视图

# 事务

## 事务四大特性(简称 ACID) 

* 原子性(Atomicity)：事务中的全部操作在数据库中是不可分割的，要么全部完成，要 么均不执行 
* 一致性(Consistency)：几个并行执行的事务，其执行结果必须与按某一顺序串行执行 的结果相一致 
* 隔离性(Isolation)：事务的执行不受其他事务的干扰，事务执行的中间结果对其他事 务必须是透明的 
* 持久性(Durability)：对于任意已提交事务，系统必须保证该事务对数据库的改变不被 丢失，即使数据库出现故障 
* 要求：表的类型必须是 innodb 或 bdb 类型，才可以对此表使用事

```mysql
查看表的创建语句： 
show create table students; 

修改表的类型： 
alter table '表名' engine=innodb; 
 
事务语句： 
开启 begin; 
提交 commit; 
回滚 rollback; 
```



# 与python交互

```python
#在文件中引入模块 
import Mysqldb 

```

## Connection 对象

```python
#Connection 对象： 用于建立与数据库的连接 创建对象：调用 connect()方法 
conn=connect(参数列表) 
```

* 参数 host：连接的 mysql 主机，如果本机是'localhost' 
* 参数 port：连接的 mysql 主机的端口，默认是 3306 
* 参数 db：数据库的名称 
* 参数 user：连接的用户名 
* 参数 password：连接的密码 
* 参数 charset：通信采用的编码方式，默认是'gb2312'，要求与数据库创建时指定的编 码一致，否则中文会乱码 

### 对象的方法：

* close()关闭连接 
* commit()事务，所以需要提交才会生效 
* rollback()事务，放弃之前的操作 
* cursor()返回 Cursor 对象，用于执行 sql 语句并获得结果 

## Cursor 对象： 

执行 sql 语句  

创建对象：调用 Connection 对象的 cursor()方法 

```python
cursor1=conn.cursor()
```

### 对象的方法

* close()关闭 
* execute(operation [, parameters ])执行语句，返回受影响的行数 
* fetchone()执行查询语句时，获取查询结果集的第一个行数据，返回一个元组 
* next()执行查询语句时，获取当前行的下一行 
* fetchall()执行查询时，获取结果集的所有行，一行构成一个元组，再将这些元组装入 一个元组返回 
* scroll(value[,mode])将行指针移动到某个位置 
  * mode 表示移动的方式 
  * mode 的默认值为 relative，表示基于当前行移动到value，value 为正则向下移动， value 为负则向上移动 
  * mode 的值为 absolute，表示基于第一条数据的位置，第一条数据的位置为 0 

### 对象的属性

* rowcount 只读属性，表示最近一次 execute()执行后受影响的行数 
* connection 获得当前连接对象 





 

# 数学函数：

PI()：返回PI的值（圆周率）

Floor()：返回小于x的最大整数

Ceiling()：返回大于x的最小整数

Round(x,y)：返回x四舍五入后有y位小数的值

Truncate(x,y)：返回数字x截短为y位小数的结果

 

 

# 聚合函数（不在聚合函数后的字段必须在group by后面）：

Avg(col)：返回指定列的平均值

Count(col)：返回指定列中非NULL值的个数（当参数为星号*时不会忽略）

Min(col)：返回指定列的最小值

Max(col)：返回指定列的最大值

Sum(col)：返回指定列的所有值之和

 

 

# 字符串函数：

Concat(s1,s2,s3…,sn)：将s1,s2,s3…,sn练成字符串

Ltrim(str)：去掉str开头的空格

Rtrim(str)：去掉str结尾的空格

Trim(str)：去掉str首尾的空格

Substring(str,x,y)：从x开始截取字符串，截取y个

Length(str)：判断str长度

 

 

# 时间日期函数：

Year(date)：返回日期date的年份

Month(date)：返回日期date的月份

Day(date)：返回日期date的天数部分

Hour(time)：返回time的小时值

Minute(time)：返回time的分钟值

Second(time)：返回time的秒值

Date(datetime)：返回datetime的日期值

Time(datetime)：返回datetime的时间值











