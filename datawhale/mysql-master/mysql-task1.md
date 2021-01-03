
[TOC]



# 数据库简介

## E-R 模型

* 当前物理的数据库都是按照 E-R 模型进行设计的 

* E 表示 entry，实体 

* R 表示 relationship，关系 

## 三范式

> 经过研究和对使用中问题的总结，对于设计数据库提出了一些规范，这些规范被称为范式，后一个范式，都是在前一个范式的基础上建立的 

* 第一范式（1NF)：列不可拆分

* 第二范式（2NF)：唯一标识

* 第三范式（3NF)：引用主键 

## 字段类型

* 数字：int,decimal 
* 字符串：varchar,text 
* 日期：datetime 
* 布尔：bit 

## 约束

* 主键 primary key 
* 非空 not null 
* 惟一 unique 
* 默认 default 
* 外键 foreign key 

## Mysql注释

```mysql
#注释语句
"--  注释语句"
/*注释语句*/
```



## 数据库一些操作命令

* select - 从数据库提取数据
* update - 更新数据库中的数据
* delete - 从数据j库删除数据
* insert into - 向数据库插入新数据
* create database - 创建新的数据库
* alter database - 修改数据库
* create table - 创建新表
* alter table - 变更数据库表
* drop table - 删除表
* create index - 创建索引
* drop index - 删除索引

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

* 如果第一个条件和第二个条件都成立，则 AND 运算符显示一条记录。
* 如果第一个条件和第二个条件中只要有一个成立，则 OR 运算符显示一条记录

### ORDER BY 关键字用于对结果集进行排序。 

```mysql
SELECT column_name,column_name 
FROM table_name 
ORDER BY column_name,column_name ASC|DESC;
```

# 作业

```mysql
#创建email表
CREATE TABLE email (
ID INT NOT NULL PRIMARY KEY,
Email VARCHAR(255)
);
#插入数据
INSERT INTO email VALUES('1','a@b.com');
INSERT INTO email VALUES('2','c@d.com');
INSERT INTO email VALUES('3','a@b.com');
#查找重复电子邮箱
mysql> select * from email where email in (select email from email group by email having Count(*)>1);
+----+---------+
| ID | Email   |
+----+---------+
|  1 | a@b.com |
|  3 | a@b.com |
+----+---------+
2 rows in set (0.07 sec)
#创建world表
CREATE TABLE World (
name VARCHAR(50) NOT NULL,
continent VARCHAR(50) NOT NULL,
area INT NOT NULL,
population INT NOT NULL,
gdp INT NOT NULL
);
#插入数据
INSERT INTO World
  VALUES('Afghanistan','Asia',652230,25500100,20343000);
INSERT INTO World 
  VALUES('Albania','Europe',28748,2831741,12960000);
INSERT INTO World 
  VALUES('Algeria','Africa',2381741,37100000,188681000);
INSERT INTO World
  VALUES('Andorra','Europe',468,78115,3712000);
INSERT INTO World
  VALUES('Angola','Africa',1246700,20609294,100990000);
#查找国家
  #如果一个国家的面积超过300万平方公里，或者(人口超过2500万并且gdp超过2000万)，那么这个国家就是大国家
mysql> select name, population,area from World where area > 3000000 or (population > 25000000 and gdp > 20000000);
+-------------+------------+---------+
| name        | population | area    |
+-------------+------------+---------+
| Afghanistan |   25500100 |  652230 |
| Algeria     |   37100000 | 2381741 |
+-------------+------------+---------+
2 rows in set (0.01 sec)
```

