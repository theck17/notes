# 
# 导出数据库
> 导出数据库用mysqldump命令（注意mysql的安装路径，即此命令的路径）

## 导出数据和表结构

mysqldump -u用户名 -p密码 数据库名 > 数据库名.sql

```mysql
mysqldump -u root -p password abc > abc.sql
#-p后是自己 MySQL 数据库密码，如果>后不指定目录，则导出到当前文件夹内。
```


敲回车后会提示输入密码

## 只导出表结构
mysqldump -u用户名 -p密码 -d 数据库名 > 数据库名.sql
\#/usr/local/mysql/bin/   mysqldump -uroot -p -d abc > abc.sql

注：/usr/local/mysql/bin/  --->  mysql的data目录


# 导入数据库
## 首先建空数据库
mysql>create database abc;

## 导入数据库

* 方法一：
  （1）选择数据库 
  mysql>use abc;
  （2）设置数据库编码
  mysql>set names utf8;
  （3）导入数据（注意sql文件的路径）
  mysql>source /home/abc/abc.sql;
* 方法二：
  mysql -u用户名 -p密码 数据库名 < 数据库名.sql
  \#mysql -uroot -p 123456 < abc.sql

# 作业

```mysql
#项目七: 各部门工资最高的员工
mysql> CREATE TABLE employee(
    -> Id INT(255) PRIMARY KEY,
    -> Name VARCHAR(255) NOT NULL,
    -> Salary INT(255) NOT NULL,
    -> DepartmentId INT(255) NOT NULL
    -> );
Query OK, 0 rows affected (0.86 sec)

mysql> INSERT INTO employee
    -> VALUES('1','Joe','70000','1');
Query OK, 1 row affected (0.17 sec)

mysql> INSERT INTO employee
    -> VALUES('2','Henry','80000','2');
Query OK, 1 row affected (0.05 sec)

mysql> INSERT INTO employee
    -> VALUES('3','Sam','60000','2');
Query OK, 1 row affected (0.03 sec)

mysql> INSERT INTO employee
    -> VALUES('4','Max','90000','1');
Query OK, 1 row affected (0.05 sec)

mysql> select * from employee;
+----+-------+--------+--------------+
| Id | Name  | Salary | DepartmentId |
+----+-------+--------+--------------+
|  1 | Joe   |  70000 |            1 |
|  2 | Henry |  80000 |            2 |
|  3 | Sam   |  60000 |            2 |
|  4 | Max   |  90000 |            1 |
+----+-------+--------+--------------+
4 rows in set (0.00 sec)

mysql> CREATE TABLE department(
    -> Id INT(255) PRIMARY KEY,
    -> Name VARCHAR(255) NOT NULL
    -> );
Query OK, 0 rows affected (0.24 sec)

mysql> INSERT INTO department
    -> VALUES('1','IT');
Query OK, 1 row affected (0.06 sec)

mysql> INSERT INTO department
    -> VALUES('2','Sales');
Query OK, 1 row affected (0.04 sec)

mysql> select * from department;
+----+-------+
| Id | Name  |
+----+-------+
|  1 | IT    |
|  2 | Sales |
+----+-------+
2 rows in set (0.00 sec)

mysql> SELECT e.Name as employee, e.Salary, d.Name as department
    -> FROM employee e join department d on e.DepartmentId=d.Id
    -> WHERE (e.Salary, e.DepartmentId)
    -> IN (SELECT MAX(Salary), DepartmentId FROM employee
    -> GROUP BY DepartmentId);
+----------+--------+------------+
| employee | Salary | department |
+----------+--------+------------+
| Henry    |  80000 | Sales      |
| Max      |  90000 | IT         |
+----------+--------+------------+
2 rows in set (0.20 sec)


#项目八: 换座位
mysql> CREATE TABLE seat(
    -> id INT(255) NOT NULL,
    -> student VARCHAR(255) NOT NULL
    -> );
Query OK, 0 rows affected (0.39 sec)

mysql> INSERT INTO seat
    -> VALUES('1','Abbot');
Query OK, 1 row affected (0.06 sec)

mysql> INSERT INTO seat
    -> VALUES('2','Doris');
Query OK, 1 row affected (0.02 sec)

mysql> INSERT INTO seat
    -> VALUES('3','Emerson');
Query OK, 1 row affected (0.10 sec)

mysql> INSERT INTO seat
    -> VALUES('4','Green');
Query OK, 1 row affected (0.02 sec)

mysql> INSERT INTO seat
    -> VALUES('5','Jeams');
Query OK, 1 row affected (0.04 sec)

mysql> select * from seat;
+----+---------+
| id | student |
+----+---------+
|  1 | Abbot   |
|  2 | Doris   |
|  3 | Emerson |
|  4 | Green   |
|  5 | Jeams   |
+----+---------+
5 rows in set (0.00 sec)

mysql> SELECT id,student FROM
    -> (
    -> SELECT id-1 AS id, student FROM seat WHERE MOD(id,2)=0
    -> UNION
    -> SELECT id+1 AS id, student FROM seat WHERE MOD(id,2)=1
    -> AND id!=(SELECT COUNT(*) FROM seat)
    -> UNION
    -> SELECT id, student FROM seat where mod(id,2)=1
    -> AND id=(SELECT COUNT(*) FROM seat)
    -> ) seat ORDER BY id;
+----+---------+
| id | student |
+----+---------+
|  1 | Doris   |
|  2 | Abbot   |
|  3 | Green   |
|  4 | Emerson |
|  5 | Jeams   |
+----+---------+
5 rows in set (0.07 sec)


#项目九: 分数排名
mysql> CREATE TABLE scores(
    -> Id INT(255) NOT NULL,
    -> Score DECIMAL(3,2)
    -> );
Query OK, 0 rows affected (0.26 sec)

mysql> INSERT INTO scores
    -> VALUES('1','3.5');
Query OK, 1 row affected (0.03 sec)

mysql> INSERT INTO scores
    -> VALUES('2','3.65');
Query OK, 1 row affected (0.02 sec)

mysql> INSERT INTO scores
    -> VALUES('3','4.0');
Query OK, 1 row affected (0.05 sec)

mysql> INSERT INTO scores
    -> VALUES('4','3.85');
Query OK, 1 row affected (0.02 sec)

mysql> INSERT INTO scores
    -> VALUES('5','4.0');
Query OK, 1 row affected (0.02 sec)

mysql> INSERT INTO scores
    -> VALUES('6','3.65');
Query OK, 1 row affected (0.02 sec)

mysql> select * from scores;
+----+-------+
| Id | Score |
+----+-------+
|  1 |  3.50 |
|  2 |  3.65 |
|  3 |  4.00 |
|  4 |  3.85 |
|  5 |  4.00 |
|  6 |  3.65 |
+----+-------+
6 rows in set (0.00 sec)

mysql> SELECT score,
    -> (SELECT COUNT(DISTINCT score)
    -> FROM scores WHERE score>=s.score) RANK
    -> FROM scores s ORDER BY score DESC;
+-------+------+
| score | RANK |
+-------+------+
|  4.00 |    1 |
|  4.00 |    1 |
|  3.85 |    2 |
|  3.65 |    3 |
|  3.65 |    3 |
|  3.50 |    4 |
+-------+------+
6 rows in set (0.05 sec)
```

