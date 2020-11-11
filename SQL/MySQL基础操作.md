# 1. 新建

## 1.1 新建用户

```sql
CEEATE user '用户名'@'host' identified by '密码';
```

> - host = localhost 为本地登录用户
> - host = ip 为运行某个 ip 地址登录
> - host = %" 为允许外网 ip 登录

![](http://cdn.hurra.ltd/img/20200516001447.png)

这样我就创建了一个名为 dalao 的用户,并且它可以从任意 ip 登录

## 1.2 查看用户

```sql
SELECT host,user,authentication_string FROM mysql.user;
```

![](http://cdn.hurra.ltd/img/20200516001828.png)

## 1.3 登录

```sql
mysql -u <用户名> -p
```

![](http://cdn.hurra.ltd/img/20200516001919.png)

---

# 2. 权限

## 2.1 授权

> 注意:`授权操作只有root用户才有权限操作`

```sql
GRANT ALL PRIVILEGES ON *.* TO '用户名'@'%' identified BY '密码';
```

> - priveleges(权限列表),ALL PRIVILEGES 表示所有权限，也可以是:
>   SELECT、UPDATE、CREATE、DELETE、DROP 等权限，多个权限之间用逗号分开
> - ON 用来指定权限针对哪些库和表。
> - 前面 \* 号用来指定数据库名
> - 后面 \* 号用来指定表名
> - identified by 指定用户登录密码,可省略
> - TO 表示将权限赋予某个用户, 如 dalao@'localhost' 表示 dalao 用户
> - @后跟限制地址，可以是 IP、域名与%(任何地方)
> - identified by 指定用户的登录密码,该项可以省略。

![](http://cdn.hurra.ltd/img/20200516003253.png)

<center>授予dalao用户对所有数据库所有表的所有操作权限</center>

## 2.2 查看

1. 查看所有用户权限

```sql
SHOW grant;
```

2. 查看指定用户权限

```sql
SHOW grant FOR '<用户名>'@'%';
```

![](http://cdn.hurra.ltd/img/20200516003557.png)

# 3. 示例

1. 新建用户 user_test,仅授予 SELECT 权限

```sql
CREATE USER 'user_test'@'%'identified by '999';

GRANT SELECT ON *.* TO 'user_test'@'%';
```

![](http://cdn.hurra.ltd/img/20200516004045.png)

2. 使用 user_test 登录,尝试创建数据库 test_db

```sql
CREATE DATABASE test_db;
```

![](http://cdn.hurra.ltd/img/20200516004259.png)

<center>可以发现被拒绝了</center>

3. 使用 user_test 用户，尝试查询

![](http://cdn.hurra.ltd/img/20200516004447.png)

<center>可以发现查询是没问题的</center>

4. 新建用户 test_4，授予 SELECT,CREATE 权限

```sql
CREATE USER 'test_4'@'%' identified by '999';

GRANT SELECT,CREATE ON *.* TO 'test_4'@'%';
```

![](http://cdn.hurra.ltd/img/20200516084018.png)

5. 使用 test_4 登录,尝试创建数据库 test_db

```sql
CREATE DATABASE test_db;
```

![](http://cdn.hurra.ltd/img/20200516084301.png)

<center>可以发现是没问题的</center>
