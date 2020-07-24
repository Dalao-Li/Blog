
- [1. 新建](#1-新建)
  - [1.1 新建用户](#11-新建用户)
  - [1.2 查看用户](#12-查看用户)
  - [1.3 登录](#13-登录)
- [2. 权限操作](#2-权限操作)
  - [2.1 授权](#21-授权)
  - [2.2 查看](#22-查看)
- [3. 示例](#3-示例)


# 1. 新建

## 1.1 新建用户
```sql
create user '用户名'@'host' identified by '密码';
```
> - host = localhost 为本地登录用户  
> - host = ip  为运行某个ip地址登录  
> - host = %"  为允许外网ip登录

![](http://cdn.hurra.ltd/img/20200516001447.png)

这样我就创建了一个名为dalao的用户,并且它可以从任意ip登录

## 1.2 查看用户

```sql
 select host,user,authentication_string from mysql.user;

```
![](http://cdn.hurra.ltd/img/20200516001828.png)

## 1.3 登录
```sql
mysql -u 用户名 -p
```
![](http://cdn.hurra.ltd/img/20200516001919.png)

---

# 2. 权限操作

## 2.1 授权

```sql
grant all privileges on *.* to '用户名'@'%' identified by '密码';
```
> - priveleges(权限列表),all priveleges表示所有权限，也可以是:  
    - select、update、create、delete、drop等权限，多个权限之间用逗号分开  
> - on用来指定权限针对哪些库和表。
> - 前面的 * 号用来指定数据库名  
> - 后面的 * 号用来指定表名
> - identified by指定用户登录密码,可省略
> - to 表示将权限赋予某个用户, 如 dalao@'localhost' 表示dalao用户  
> - @后跟限制地址，可以是IP、域名与%(任何地方)
> - identified by指定用户的登录密码,该项可以省略。

授权操作只有root用户才有权限操作

![](http://cdn.hurra.ltd/img/20200516003253.png)
<center>授予dalao用户对所有数据库所有表的所有操作权限</center>

## 2.2 查看

1. 查看所有用户权限
```sql
show grants;
```
2. 查看指定用户权限

```sql
show grants for '用户名'@'%';
```
![](http://cdn.hurra.ltd/img/20200516003557.png)

# 3. 示例

1. 新建用户user_test,仅授予select权限
```sql
create user 'user_test'@'%'identified by '999';

grant select on *.* to 'user_test'@'%';

```
![](http://cdn.hurra.ltd/img/20200516004045.png)

2. 使用user_test登录,尝试创建数据库test_db
```sql
create database test_db;
```
![](http://cdn.hurra.ltd/img/20200516004259.png)
<center>可以发现被拒绝了</center>


3. 使用user_test用户，尝试查询

![](http://cdn.hurra.ltd/img/20200516004447.png)
<center>可以发现查询是没问题的</center>

4. 新建用户test_4，授予select,create权限

```sql
create user 'test_4'@'%' identified by '999';

grant select,create on *.* to 'test_4'@'%';

```
![](http://cdn.hurra.ltd/img/20200516084018.png)

5. 使用test_4登录,尝试创建数据库test_db
```sql
create database test_db;
```
![](http://cdn.hurra.ltd/img/20200516084301.png)
<center>可以发现是没问题的</center>

