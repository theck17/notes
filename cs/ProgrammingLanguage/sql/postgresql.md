---
title: 'PostgreSql'
date: 2019-07-11 16:21:16
tags: [Database]
published: true
hideInList: false
feature: /post-images/postgresql.jpg
---


[TOC]





# PostgreSql

# 语法

* 启动数据库：

  * windows：psql -U postgres
  * linux：
    * sudo service postgresql start
    * sudo -u postgres psql

* 退出数据库：\q

* 查看所有数据库：\l

* 切换数据库： \c testdb

* 查看表：\d

* 查看表结构：\d tablename

* 创建用户：sudo -u postgres createuser dbuser

* 查看所有用户：\du

* 删除用户：postgres=# drop user dbuser;

* 设置密码：\password

* 查看SQL命令的解释：\h

* 查看psql命令列表：\?

* 打开文本编辑器：\e

* 列出当前数据库和连接的信息：\conninfo

* pg_dump 备份

* pg_dumpall 备份所有数据库

* pg_restore 恢复

* ```sql
  pg_dump --format=t -d db_name -U user_name -W -h 127.0.0.1 > dump.sql
  pg_restore -d db_name -h 127.0.0.1 -U user_name < dump.sql
  注意要加 -U 并且一定要是 db_name 的 owner
  ```

* psql exampledb < exampledb.sql 导入数据

# 常用SQL语句

```sql
# 创建新表
CREATE TABLE user_tbl(name VARCHAR(20), signup_date DATE);

# 插入数据
INSERT INTO user_tbl(name, signup_date) VALUES('张三', '2013-12-22');

# 查询记录
SELECT * FROM user_tbl;

# 更新数据
UPDATE user_tbl set name = '李四' WHERE name = '张三';

# 删除记录
DELETE FROM user_tbl WHERE name = '李四' ;

# 添加字段
ALTER TABLE user_tbl ADD email VARCHAR(40);

# 更改字段类型
ALTER TABLE user_tbl ALTER COLUMN signup_date SET NOT NULL;

# 设置字段默认值（注意字符串使用单引号）
ALTER TABLE user_tbl ALTER COLUMN email SET DEFAULT 'example@example.com';

# 去除字段默认值
ALTER TABLE user_tbl ALTER email DROP DEFAULT;

# 重命名字段
ALTER TABLE user_tbl RENAME COLUMN signup_date TO signup;

# 删除字段
ALTER TABLE user_tbl DROP COLUMN email;

# 表重命名
ALTER TABLE user_tbl RENAME TO backup_tbl;

# 删除表
DROP TABLE IF EXISTS backup_tbl;

# 删除库
\c hello2;
DROP DATABASE IF EXISTS hello;
```

# 数据类型

## 数据类型

数据类型指定要在表字段中存储哪种类型的数据。 在创建表时，对于每列必须使用数据类型。
PotgreSQL中主要有三种类型的数据类型。 此外，用户还可以使用`CREATE TYPE` SQL命令创建自己的自定义数据类型。

以下是PostgreSQL中主要有三种类型的数据类型：

- 数值数据类型
- 字符串数据类型
- 日期/时间数据类型

## 数值数据类型

数字数据类型用于指定表中的数字数据。

| 名称      | 描述                                   | 存储大小 | 范围                                                    |
| --------- | -------------------------------------- | -------- | ------------------------------------------------------- |
| smallint  | 存储整数，小范围                       | 2字节    | -32768 至 +32767                                        |
| integer   | 存储整数。使用这个类型可存储典型的整数 | 4字节    | -2147483648 至 +2147483647                              |
| bigint    | 存储整数，大范围。                     | 8字节    | -9223372036854775808 至 9223372036854775807             |
| decimal   | 用户指定的精度，精确                   | 变量     | 小数点前最多为131072个数字; 小数点后最多为16383个数字。 |
| numeric   | 用户指定的精度，精确                   | 变量     | 小数点前最多为131072个数字; 小数点后最多为16383个数字。 |
| real      | 可变精度，不精确                       | 4字节    | 6位数字精度                                             |
| double    | 可变精度，不精确                       | 8字节    | 15位数字精度                                            |
| serial    | 自动递增整数                           | 4字节    | 1 至 2147483647                                         |
| bigserial | 大的自动递增整数                       | 8字节    | 1 至 9223372036854775807                                |

## 字符串数据类型

String数据类型用于表示字符串类型值。

| 数据类型                | 描述                                                         |
| ----------------------- | ------------------------------------------------------------ |
| char(size)              | 这里`size`是要存储的字符数。固定长度字符串，右边的空格填充到相等大小的字符。 |
| character(size)         | 这里`size`是要存储的字符数。 固定长度字符串。 右边的空格填充到相等大小的字符。 |
| varchar(size)           | 这里`size`是要存储的字符数。 可变长度字符串。                |
| character varying(size) | 这里`size`是要存储的字符数。 可变长度字符串。                |
| text                    | 可变长度字符串。                                             |

## 日期/时间数据类型

日期/时间数据类型用于表示使用日期和时间值的列。

| 名称                          | 描述                   | 存储大小 | 最小值        | 最大值        | 解析度       |
| ----------------------------- | ---------------------- | -------- | ------------- | ------------- | ------------ |
| timestamp [ (p) ] [不带时区 ] | 日期和时间(无时区)     | 8字节    | 4713 bc       | 294276 ad     | 1微秒/14位数 |
| timestamp [ (p) ]带时区       | 包括日期和时间，带时区 | 8字节    | 4713 bc       | 294276 ad     |              |
| date                          | 日期(没有时间)         | 4字节    | 4713 bc       | 5874897 ad    | 1微秒/14位数 |
| time [ (p) ] [ 不带时区 ]     | 时间(无日期)           | 8字节    | 00:00:00      | 24:00:00      | 1微秒/14位数 |
| time [ (p) ] 带时区           | 仅限时间，带时区       | 12字节   | 00:00:00+1459 | 24:00:00-1459 | 1微秒/14位数 |
| interval [ fields ] [ (p) ]   | 时间间隔               | 12字节   | -178000000年  | 178000000年   | 1微秒/14位数 |

## 一些其他数据类型

###布尔类型

| 名称    | 描述                          | 存储大小 |
| ------- | ----------------------------- | -------- |
| boolean | 它指定`true`或`false`的状态。 | 1字节    |

### 货币类型

| 名称  | 描述     | 存储大小 | 范围                                           |
| ----- | -------- | -------- | ---------------------------------------------- |
| money | 货币金额 | 8字节    | -92233720368547758.08 至 +92233720368547758.07 |

### 几何类型

几何数据类型表示二维空间对象。最根本的类型：**点** - 形成所有其他类型的基础。

| 名称    | 存储大小   | 表示                   | 描述                        |
| ------- | ---------- | ---------------------- | --------------------------- |
| point   | 16字节     | 在一个平面上的点       | (x,y)                       |
| line    | 32字节     | 无限线(未完全实现)     | ((x1,y1),(x2,y2))           |
| lseg    | 32字节     | 有限线段               | ((x1,y1),(x2,y2))           |
| box     | 32字节     | 矩形框                 | ((x1,y1),(x2,y2))           |
| path    | 16+16n字节 | 封闭路径(类似于多边形) | ((x1,y1),…)                 |
| polygon | 40+16n字节 | 多边形(类似于封闭路径) | ((x1,y1),…)                 |
| circle  | 24字节     | 圆                     | `<(x，y)，r>`(中心点和半径) |

# 创建和删除数据库

```sql
postgres=# create database testdb;
CREATE DATABASE
postgres=# 
```

```sql
postgres=# drop database testdb;
DROP DATABASE
postgres=#
```

# 创建和删除表

```sql
# 创建表语法
CREATE TABLE 模式名.table_name(  
   column1 datatype,  
   column2 datatype,  
   column3 datatype,  
   .....  
   columnN datatype,  
   PRIMARY KEY( one or more columns )  
);
CREATE TABLE public.students
(
  id integer NOT NULL,
  name character(100),
  subjects character(1),
  CONSTRAINT student2_pkey PRIMARY KEY (id)
)
WITH (
  OIDS=FALSE
);
ALTER TABLE public.students
  OWNER TO postgres;
COMMENT ON TABLE public.students
  IS '这是一个信息表';

```

```sql
# 删除表语法
postgres=# drop table students;
DROP TABLE
```

# 创建、修改和删除模式

>模式(也叫架构)是指定的表集合。 它还可以包含视图，索引，序列，数据类型，运算符和函数。

```sql
# 创建模式，（模式不能嵌套）
CREATE SCHEMA schema_name user_name schema_element;
# 参数
# schema_name：模式名称，缺省使用user_name，且不能以pg_开头
# user_name：模式属于的用户，缺省为执行命令的用户
# schema_element：一条SQL语句，即创建模式后，在该模式下创建一个数据库对象

# 修改模式
alter schema schema_name new_name new_owner;
# 参数
# name：模式名称
# new_name：模式新的名称，同样新名称也不能以pg_开头
# new_owner：模式新用户名称

# 删除模式
drop schema IF EXISTS name RESTRICT;
# 参数
# name模式名称。
# CASCADE自动删除该模式下数据库对象。
# RESTRICT如果该模式下还存在数据库对象，则不允许删除该模式，RESTRICT为缺省值。
```

# 查询

## 插入数据

```sql
INSERT INTO TABLE_NAME (column1, column2, column3,...columnN)  
VALUES (value1, value2, value3,...valueN);
```

## 查询数据

```sql 
SELECT "column1", "column2".."column" FROM "table_name";
```

## 更新数据

```sql
UPDATE table_name  
SET column1 = value1, column2 = value2...., columnN = valueN  
WHERE [condition];
```

## 删除数据

```sql
DELETE FROM table_name  
WHERE [condition];
```

## ORDER BY子句

> `ORDER BY`子句用于按升序或降序对数据进行排序。数据在一列或多列的基础上进行排序。

```sql
SELECT column-list  
FROM table_name  
[WHERE condition]  
[ORDER BY column1, column2, .. columnN] [ASC | DESC];
# column_list：它指定要检索的列或计算。
# table_name：它指定要从中检索记录的表。
# FROM子句中必须至少有一个表。
# WHERE conditions：可选。 它规定必须满足条件才能检索记录。
# ASC：也是可选的。它通过表达式按升序排序结果集(默认，如果没有修饰符是提供者)。
# DESC：也是可选的。 它通过表达式按顺序对结果集进行排序。
```

## 分组

> `GROUP BY`子句用于将具有相同数据的表中的这些行分组在一起。 它与`SELECT`语句一起使用。
>
> `GROUP BY`子句通过多个记录收集数据，并将结果分组到一个或多个列。 它也用于减少输出中的冗余。

```sql
SELECT column-list  
FROM table_name  
WHERE [conditions ]  
GROUP BY column1, column2....columnN  
ORDER BY column1, column2....columnN
```

## Having子句

> HAVING子句与[GROUP BY](http://www.yiibai.com/postgresql/postgresql-group-by-clause.html)子句组合使用，用于选择函数结果满足某些条件的特定行

```sql
SELECT column1, column2  
FROM table1, table2  
WHERE [ conditions ]  
GROUP BY column1, column2  
HAVING [ conditions ]  
ORDER BY column1, column2
```

## 条件查询

>  通常与WHERE子句一起使用。 具有子句的条件就像双层过滤器。

- AND 条件

- ```sql
  SELECT column1, column2, ..... columnN    
  FROM table_name    
  WHERE [search_condition]    
  AND [search_condition];
  ```

- OR 条件

- ```sql
  SELECT column1, column2, ..... columnN    
  FROM table_name    
  WHERE [search_condition]    
  OR [search_condition];
  ```

- AND & OR 条件

- ```sql
  SELECT column1, column2, ..... columnN    
  FROM table_name    
  WHERE [search_condition]  AND [search_condition]     
  OR [search_condition];
  ```

- NOT 条件

- ```sql
  SELECT column1, column2, ..... columnN    
  FROM table_name    
  WHERE [search_condition] NOT [condition];
  ```

- LIKE 条件

- ```sql
  SELECT column1, column2, ..... columnN    
  FROM table_name    
  WHERE [search_condition] LIKE [condition];
  ```

- IN 条件

- ```sql
  SELECT column1, column2, ..... columnN    
  FROM table_name    
  WHERE [search_condition] IN [condition];
  ```

- NOT IN 条件

- ```sql
  SELECT column1, column2, ..... columnN    
  FROM table_name    
  WHERE [search_condition] NOT IN [condition];
  ```

- BETWEEN 条件

* ```sql
  SELECT column1, column2, ..... columnN    
  FROM table_name    
  WHERE [search_condition] BETWEEN [condition];
  ```

# 连接

## 内连接(INNER JOIN)

> 此连接返回满足连接条件的多个表中的所有行

```sql
SELECT table1.columns, table2.columns  
FROM table1  
INNER JOIN table2  
ON table1.common_filed = table2.common_field;
```

## 左外连接(LEFT OUTER JOIN)

> 左外连接返回从“`ON`”条件中指定的左侧表中的所有行，只返回满足条件的另一个表中的行

```sql
SELECT table1.columns, table2.columns  
FROM table1  
LEFT OUTER JOIN table2  
ON table1.common_filed = table2.common_field;
```

## 右外连接(RIGHT OUTER JOIN)

> 右外连接返回从“`ON`”条件中指定的右侧表中的所有行，只返回满足条件的另一个表中的行

```sql
SELECT table1.columns, table2.columns  
FROM table1  
RIGHT OUTER JOIN table2  
ON table1.common_filed = table2.common_field;
```

## 全连接(FULL OUTER JOIN)

> 全外连接从左表和左表中返回所有行。 它将`NULL`置于不满足连接条件的位置

```sql
SELECT table1.columns, table2.columns  
FROM table1  
FULL OUTER JOIN table2  
ON table1.common_filed = table2.common_field;
```



## 跨连接(CROSS JOIN)

> 跨连接(`CROSS JOIN`)将第一个表的每一行与第二个表的每一行相匹配。 它也被称为笛卡尔积。 如果`table1`具有“`x`”行，而`table2`具有“`y`”行，则所得到的表将具有(`x * y`)行

```sql
SELECT coloums   
FROM table1   
CROSS JOIN table2
```

# 高级部分

## 事图

视图(VIEW)是一个伪表。 它不是物理表，而是作为普通表选择查询。
视图也可以表示连接的表。 它可以包含表的所有行或来自一个或多个表的所选行。

**视图便于用户执行以下操作：**

- 它以自然和直观的方式构建数据，并使其易于查找。
- 它限制对数据的访问，使得用户只能看到有限的数据而不是完整的数据。
- 它归总来自各种表中的数据以生成报告。

### 创建视图

```sql
CREATE [TEMP | TEMPORARY] VIEW view_name AS  
SELECT column1, column2.....  
FROM table_name  
WHERE [condition];
```

### 删除视图

```sql
DROP VIEW view_name;
```

## 函数

> 也称为PostgreSQL存储过程

```mysql
CREATE [OR REPLACE] FUNCTION function_name (arguments)   
RETURNS return_datatype AS $variable_name$  
  DECLARE  
    declaration;  
    [...]  
  BEGIN  
    < function_body >  
    [...]  
    RETURN { variable_name | value }  
  END; LANGUAGE plpgsql;
```

* 参数说明
  * `function_name`：指定函数的名称。
  * `[OR REPLACE]`：是可选的，它允许您修改/替换现有函数。
  * `RETURN`：它指定要从函数返回的数据类型。它可以是基础，复合或域类型，或者也可以引用表列的类型。
  * `function_body`：`function_body`包含可执行部分。
  * `plpgsql`：它指定实现该函数的语言的名称。

