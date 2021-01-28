<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:34
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-01-28 22:17:24
-->
# 拉取镜像

```shell
docker pull truevoly/oracle-12c
```

# 创建容器

```shell
docker run -d -p 8080:8080 -p 1521:1521 truevoly/oracle-12c
```

# 进入容器后,输入

```shell
sqlplus sys as sysdba
```

之后输入 sys 用户的默认密码`oracle`,即可进入 oralce

# 查看表空间

```sql
SELECT tablespace_name FROM dba_tablespaces;
```

# 查看表空间路径

```sql
SELECT * FROM dba_data_files;
```

![](http://cdn.hurra.ltd/img/20201130153639.png)

> path = /u01/app/oracle/oradata/xe/...

# 创建表空间

```sql
CREATE TABLESPACE space_demo DATAFILE '/u01/app/oracle/oradata/xe/space_demo.DBF' SIZE 32M AUTOEXTEND ON NEXT 32M MAXSIZE 20480M EXTENT MANAGEMENT LOCAL;
```

> 上述命令就创建了名为 space_demo,表空间路径为'/u01/app/oracle/oradata/xe/space_demo.DBF'的表空间

# 创建用户

```sql
CREATE USER user_test IDENTIFIED BY 123 ACCOUNT UNLOCK DEFAULT TABLESPACE space_demo;
```

> 上述命令创建了名为 user_test 的用户,其密码是 123,使用的默认表空间为 space_demo

# 赋予用户权限

```sql
GRANT CONNECT,RESOURCE,DBA TO user_test;
```

> connect,resource,dba 权限赋予 test 用户

![](http://cdn.hurra.ltd/img/收款码.png)
