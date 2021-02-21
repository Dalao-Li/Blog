<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:34
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-01-31 22:06:32
-->

# Docker 搭建 MySQL

# 获取镜像

```shell
docker pull mysql:5.7
```

![](https://cdn.hurra.ltd/img/20200515200648.png)

# 运行镜像

## 不映射目录

```shell
docker run -itd -p  3306:3306 -e MYSQL_ROOT_PASSWORD=123456  mysql:5.7
```

![](https://cdn.hurra.ltd/img/20200515200803.png)

> - -p 3306:3306 即将容器的 3306 端口映射到主机的 3306 端口上
> - -e MYSQL_ROOT_PASSWORD=123456 即设置环境变量,用户为 root,密码为 123456

不映射目录的情况下数据不能持久化保存,容器没了就得跑路了

## 映射目录

```shell
docker run -itd -p 3306:3306 -v $PWD/mysql:/var/lib/mysql -e MYSQL_ROOT_PASSWORD= 123  mysql:5.6
```

![](https://cdn.hurra.ltd/img/20200515201929.png)

容器内的 **/var/lib/mysql** 目录映射到了宿主机的**D:/volume/mysql**目录上,容器没了数据还在

![](https://cdn.hurra.ltd/img/20200515202929.png)

---

## 远程连接

- 进入容器,登录

```shell
mysql -u root -p
```

![](https://cdn.hurra.ltd/img/20200515202434.png)

- 允许远程登录

```shell
grant all privileges on *.* to 'root'@'%' identified by '刚设置的MYSQL密码';

flush privileges;
```

![](https://cdn.hurra.ltd/img/20200515202734.png)

测试:新建一个数据库 Test

![](https://cdn.hurra.ltd/img/20200515234119.png)

如果设置了目录映射的话就能在宿主机中看见了

![](https://cdn.hurra.ltd/img/20200515234144.png)

# 常见问题

## 中文乱码

进入容器内,执行

```sh
echo "character-set-server=utf8" >> /etc/mysql/mysql.conf.d/mysqld.cnf

service mysql restart
```

## 降低占用内存

容器内编辑 /etc/mysql/mysql.conf.d/mysqld.cnf,追加:

```shell
performance_schema_max_table_instances=400

table_definition_cache=400

table_open_cache=256
```

重启容器或者重启 MySQL 服务

![](https://cdn.hurra.ltd/img/收款码.png)
