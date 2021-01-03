# 查询操作

## 条件

```mysql
select * from 表名 where 条件;
```

### 比较运算符

- 等于=
- 大于>
- 大于等于>=
- 小于<
- 小于等于<=
- 不等于!=或<>

### 逻辑运算符

- and
- or
- not

### 模糊查询

- %表示任意多个任意字符
- _表示一个任意字符

```mysql
#查询姓黄的学生
select * from students where sname like '黄%'; 
#查询姓黄并且名字是一个字的学生
select * from students where sname like '黄_';
#查询姓黄或叫靖的学生
select * from students where sname like '黄%' or sname like '%靖%';
```

### 范围查询

- in表示在一个非连续的范围内
- between ... and ...表示在一个连续的范围内

```mysql
#查询编号是 1 或 3 或 8 的学生
select * from students where id in(1,3,8); 
#查询学生是 3 至 8 的学生
select * from students where id between 3 and 8; 
```

### 空判断

- is null
- is not null 

```mysql
#查询没有填写地址的学生
select * from students where hometown is null; 
#查询填写了地址的学生
select * from students where hometown is not null; 
#查询填写了地址的女生
select * from students where hometown is not null and gender=0; 
```

## 聚合

- count(*)表示计算总行数，括号中写星与列名，结果是相同的 
- max(列)表示求此列的最大值 
- min(列)表示求此列的最小值 
- sum(列)表示求此列的和 
- avg(列)表示求此列的平均值 

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

- where 是对 from 后面指定的表进行数据筛选，属于对原始数据的筛选
- having 是对 group by 的结果进行筛选

## 排序

```mysql
select * from 表名 
order by 列 1 asc|desc,列 2 asc|desc,... 
```

## 分页 

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

- 执行顺序
  - from 表名 
  - where .... 
  - group by ... 
  - select distinct * 
  - having ... 
  - order by ... 
  - limit start,count 

# 级联操作

- restrict（限制）：默认值，抛异常 
- cascade（级联）：如果主表的记录删掉，则从表中相关联的记录都将被删除 
- set null：将外键设置为空 
- no action：什么都不做 

# 作业

```mysql
#1
mysql> select * from courses;
+---------+----------+------------+
| student | class    | id         |
+---------+----------+------------+
| A       | Math     | 0000000001 |
| B       | English  | 0000000002 |
| C       | Math     | 0000000003 |
| D       | Biology  | 0000000004 |
| E       | Math     | 0000000005 |
| F       | Computer | 0000000006 |
| G       | Math     | 0000000007 |
| H       | Math     | 0000000008 |
| I       | Math     | 0000000009 |
| A       | Math     | 0000000010 |
+---------+----------+------------+
10 rows in set (0.00 sec)
mysql> select class,count(*) from courses group by class having count(*)>5;
+-------+----------+
| class | count(*) |
+-------+----------+
| Math  |        7 |
+-------+----------+
1 row in set (0.00 sec)
```

```mysql
#2
mysql> select * from salary;
+------------+------+------+--------+
| id         | name | sex  | salary |
+------------+------+------+--------+
| 0000000001 | A    | m    | 2500   |
| 0000000002 | B    | f    | 1500   |
| 0000000003 | C    | m    | 5500   |
| 0000000004 | D    | f    | 500    |
+------------+------+------+--------+
4 rows in set (0.00 sec)

mysql> update salary set Sex = case Sex
    -> when 'f' then 'm'
    -> when 'm' then 'f'
    -> end;
Query OK, 4 rows affected (0.12 sec)
Rows matched: 4  Changed: 4  Warnings: 0

mysql> select * from salary;
+------------+------+------+--------+
| id         | name | sex  | salary |
+------------+------+------+--------+
| 0000000001 | A    | f    | 2500   |
| 0000000002 | B    | m    | 1500   |
| 0000000003 | C    | f    | 5500   |
| 0000000004 | D    | m    | 500    |
+------------+------+------+--------+
4 rows in set (0.00 sec)
```

```mysql
#3
mysql> select * from person;
+----------+-----------+----------+
| PersonId | FirstName | LastName |
+----------+-----------+----------+
|        1 | A         | a        |
|        2 | B         | b        |
|        3 | C         | c        |
+----------+-----------+----------+
3 rows in set (0.00 sec)

mysql> select * from address;
+-----------+----------+---------+---------+
| AddressId | PersonId | City    | State   |
+-----------+----------+---------+---------+
|         1 |        2 | Chengdu | Sichuan |
|         3 |        4 | Beijing | Beijing |
|         5 |        6 | Taibei  | Taiwan  |
+-----------+----------+---------+---------+
3 rows in set (0.00 sec)

mysql> select FirstName, LastName, City, State from Address left join Person on Person.PersonId = Address.PersonId order by Person.PersonId;
+-----------+----------+---------+---------+
| FirstName | LastName | City    | State   |
+-----------+----------+---------+---------+
| NULL      | NULL     | Beijing | Beijing |
| NULL      | NULL     | Taibei  | Taiwan  |
| B         | b        | Chengdu | Sichuan |
+-----------+----------+---------+---------+
3 rows in set (0.00 sec)
```

```mysql
#4
mysql> create table emailtmp as select * from email;
Query OK, 3 rows affected (0.26 sec)
Records: 3  Duplicates: 0  Warnings: 0

mysql> delete emailtmp from emailtmp,email where emailtmp.email = email.email and emailtmp.id>email.id;
Query OK, 1 row affected (0.11 sec)

mysql> select * from email;
+----+---------+
| ID | Email   |
+----+---------+
|  1 | a@b.com |
|  2 | c@d.com |
|  3 | a@b.com |
+----+---------+
3 rows in set (0.00 sec)

mysql> select * from emailtmp;
+----+---------+
| ID | Email   |
+----+---------+
|  1 | a@b.com |
|  2 | c@d.com |
+----+---------+
2 rows in set (0.00 sec)
```

