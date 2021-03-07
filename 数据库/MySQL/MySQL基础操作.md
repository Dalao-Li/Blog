# MySQL基础操作

## 新建用户

```sql
CEEATE user '[用户名]'@'host' identified by '[密码]';
```

> - host = localhost 为本地登录用户
> - host = ip 为运行某个 ip 地址登录
> - host = %" 为允许外网 ip 登录

![](https://cdn.hurra.ltd/img/20200516001447.png)

这样我就创建了一个名为 dalao 的用户,并且它可以从任意 ip 登录

查看用户

```sql
SELECT host,user,authentication_string FROM mysql.user;
```

![](https://cdn.hurra.ltd/img/20200516001828.png)

登录

```sql
mysql -u <用户名> -p
```

![](https://cdn.hurra.ltd/img/20200516001919.png)

## 授权

> 注意:`授权操作只有root用户才有权限操作`

```sql
GRANT ALL PRIVILEGES ON *.* TO '[用户名]'@'%' identified BY '[密码]';
```


| 参数           | 含义                                                                    |
| -------------- | ----------------------------------------------------------------------- |
| ALL PRIVILEGES | 表示所有权限,该参数也可以是:SELECT、UPDATE、CREATE、DELETE、DROP 等权限 |
| ON             | 指定权限针对哪些库和表                                                  |
| 前一个 \*      | 指定数据库名                                                            |
| 后一个 \*      | 指定表名                                                                |
| identified by  | 指定用户登录密码,可省略                                                 |
| TO             | 表示将权限赋予某个用户, 如 dalao@'localhost' 表示 dalao 用户            |
| @              | 跟限制地址,可以是 IP、域名与%(表示任何IP)                               |


![](https://cdn.hurra.ltd/img/20200516003253.png)

<center>授予dalao用户对所有数据库所有表的所有操作权限</center>

查看所有用户权限

```sql
SHOW grant;
```

查看指定用户权限

```sql
SHOW grant FOR '[用户名]'@'%';
```

![](https://cdn.hurra.ltd/img/20200516003557.png)


新建用户 user_test,仅授予 SELECT 权限

```sql
CREATE USER 'user_test'@'%'identified by '999';

GRANT SELECT ON *.* TO 'user_test'@'%';
```

![](https://cdn.hurra.ltd/img/20200516004045.png)

使用 user_test 登录,尝试创建数据库 test_db

```sql
CREATE DATABASE test_db;
```

![](https://cdn.hurra.ltd/img/20200516004259.png)

<center>可以发现被拒绝了</center>

使用 user_test 用户,尝试查询

![](https://cdn.hurra.ltd/img/20200516004447.png)

<center>可以发现查询是没问题的</center>

新建用户 test_4,授予 SELECT,CREATE 权限

```sql
CREATE USER 'test_4'@'%' identified by '999';

GRANT SELECT,CREATE ON *.* TO 'test_4'@'%';
```

![](https://cdn.hurra.ltd/img/20200516084018.png)

使用 test_4 登录,尝试创建数据库 test_db

```sql
CREATE DATABASE test_db;
```

![](https://cdn.hurra.ltd/img/20200516084301.png)

<center>可以发现是没问题的</center>
