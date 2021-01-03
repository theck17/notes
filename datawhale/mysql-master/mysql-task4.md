## 项目10

```mysql
mysql> create table Users(
    -> Users_Id int primary key,
    -> Banned enum("yes", "no"),
    -> Role enum("client", "driver", "Role")
    -> );
Query OK, 0 rows affected (0.25 sec)

mysql> insert into Users values
    -> (1 ,"No","client"),
    -> (2 ,"Yes","client"),
    -> (3 ,"No","client"),
    -> (4 ,"No","client"),
    -> (10 ,"No","driver"),
    -> (11 ,"No","driver"),
    -> (12 ,"No","driver"),
    -> (13 ,"No","driver");
Query OK, 8 rows affected (0.15 sec)
Records: 8  Duplicates: 0  Warnings: 0

mysql> select * from Users;
+----------+--------+--------+
| Users_Id | Banned | Role   |
+----------+--------+--------+
|        1 | no     | client |
|        2 | yes    | client |
|        3 | no     | client |
|        4 | no     | client |
|       10 | no     | driver |
|       11 | no     | driver |
|       12 | no     | driver |
|       13 | no     | driver |
+----------+--------+--------+
8 rows in set (0.02 sec)

mysql> create table Trips(
    -> Id int not null primary key,
    -> Client_Id int,
    -> Driver_Id int,
    -> City_Id int,
    -> Status enum("completed", "cancelled_by_driver", "cancelled_by_client"),
    -> Request_at DATE,
    -> foreign key(Client_Id) references Users(Users_Id),
    -> foreign key(Driver_Id) references Users(Users_Id)
    -> );
Query OK, 0 rows affected (0.32 sec)

mysql> insert into Trips values
    -> (1,1,10,1,"completed","2013-10-01"),
    -> (2 , 2 , 11 , 1 , "cancelled_by_driver","2013-10-01"),
    -> (3 , 3 , 12 , 6 , "completed" ,"2013-10-01"),
    -> (4 , 4 , 13 , 6 , "cancelled_by_client","2013-10-01"),
    -> (5 , 1 , 10 , 1 , "completed" ,"2013-10-02"),
    -> (6 , 2 , 11 , 6 , "completed" ,"2013-10-02"),
    -> (7 , 3 , 12 , 6 , "completed" ,"2013-10-02"),
    -> (8 , 2 , 12 , 12 , "completed" ,"2013-10-03"),
    -> (9 , 3 , 10 , 12 , "completed" ,"2013-10-03"),
    -> (10 , 4 , 13 , 12 , "cancelled_by_driver","2013-10-03");
Query OK, 10 rows affected (0.09 sec)
Records: 10  Duplicates: 0  Warnings: 0

mysql> select * from Trips;
+----+-----------+-----------+---------+---------------------+------------+
| Id | Client_Id | Driver_Id | City_Id | Status              | Request_at |
+----+-----------+-----------+---------+---------------------+------------+
|  1 |         1 |        10 |       1 | completed           | 2013-10-01 |
|  2 |         2 |        11 |       1 | cancelled_by_driver | 2013-10-01 |
|  3 |         3 |        12 |       6 | completed           | 2013-10-01 |
|  4 |         4 |        13 |       6 | cancelled_by_client | 2013-10-01 |
|  5 |         1 |        10 |       1 | completed           | 2013-10-02 |
|  6 |         2 |        11 |       6 | completed           | 2013-10-02 |
|  7 |         3 |        12 |       6 | completed           | 2013-10-02 |
|  8 |         2 |        12 |      12 | completed           | 2013-10-03 |
|  9 |         3 |        10 |      12 | completed           | 2013-10-03 |
| 10 |         4 |        13 |      12 | cancelled_by_driver | 2013-10-03 |
+----+-----------+-----------+---------+---------------------+------------+
10 rows in set (0.00 sec)

mysql> select Request_at as Day, ROUND(count(Status != 'completed' OR NULL)/count(*),2) as "Cancellation Rate"
    -> from Trips, users
    -> where Trips.Client_Id = users.Users_Id
    -> and Banned="no" and Request_at BETWEEN "2013-10-1" and "2013-10-3"
    -> group by Request_at;
+------------+-------------------+
| Day        | Cancellation Rate |
+------------+-------------------+
| 2013-10-01 |              0.33 |
| 2013-10-02 |              0.00 |
| 2013-10-03 |              0.50 |
+------------+-------------------+
3 rows in set (0.09 sec)
```



## 项目11

```mysql
mysql> create table Employee2(
    -> Id int not null,
    -> name char(10) not null,
    -> salary long,
    -> departmentId int
    -> );
Query OK, 0 rows affected (0.18 sec)

mysql> insert into Employee2 values
    -> (1,"Joe",70000,1),
    -> (2,"Henry",80000,2),
    -> (3,"Sam",60000,2),
    -> (4,"Max",90000,1),
    -> (5,"Janet",69000,1),
    -> (6,"Randy",85000,1);
Query OK, 6 rows affected (0.02 sec)
Records: 6  Duplicates: 0  Warnings: 0

mysql> select * from employee2;
+----+-------+--------+--------------+
| Id | name  | salary | departmentId |
+----+-------+--------+--------------+
|  1 | Joe   | 70000  |            1 |
|  2 | Henry | 80000  |            2 |
|  3 | Sam   | 60000  |            2 |
|  4 | Max   | 90000  |            1 |
|  5 | Janet | 69000  |            1 |
|  6 | Randy | 85000  |            1 |
+----+-------+--------+--------------+
6 rows in set (0.00 sec)

mysql> select d.Name Department, e.Name Employee2, e.Salary Salary
    -> from Employee2 e inner join Department d
    -> on e.DepartmentId = d.Id
    -> where (
    -> select count(distinct c.Salary)
    -> from Employee2 c
    -> where e.Salary < c.Salary and e.DepartmentId = c.DepartmentId
    -> ) < 3
    -> order by e.DepartmentId, e.Salary desc;
+------------+-----------+--------+
| Department | Employee2 | Salary |
+------------+-----------+--------+
| IT         | Max       | 90000  |
| IT         | Randy     | 85000  |
| IT         | Joe       | 70000  |
| Sales      | Henry     | 80000  |
| Sales      | Sam       | 60000  |
+------------+-----------+--------+
5 rows in set (0.07 sec)
```

## 项目12

```mysql
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

mysql> select score as Score,(
    -> select count(score)+1
    -> from scores s1
    -> where s1.score>s2.score
    -> )as "Rank"
    -> from scores s2
    -> order by score desc;
+-------+------+
| Score | Rank |
+-------+------+
|  4.00 |    1 |
|  4.00 |    1 |
|  3.85 |    3 |
|  3.65 |    4 |
|  3.65 |    4 |
|  3.50 |    6 |
+-------+------+
6 rows in set (0.00 sec)
```

