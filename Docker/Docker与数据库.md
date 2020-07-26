## 目录

- [一、Docker搭建MySQL](#一docker搭建mysql)
  - [1. 获取镜像](#1-获取镜像)
  - [2. 运行镜像](#2-运行镜像)
    - [2.1 不映射目录](#21-不映射目录)
    - [2.2 映射目录](#22-映射目录)
  - [3. 远程连接](#3-远程连接)
  - [4.常见问题](#4常见问题)
    - [4.1 中文乱码](#41-中文乱码)
    - [4.2 降低占用内存](#42-降低占用内存)

# 一、Docker搭建MySQL

## 1. 获取镜像
```s
docker pull mysql:5.7
```
![](http://cdn.hurra.ltd/img/20200515200648.png)

## 2. 运行镜像

### 2.1 不映射目录
```
docker run -itd -p  主机端口:3306 -e MYSQL_ROOT_PASSWORD= 密码  镜像id
```
![](http://cdn.hurra.ltd/img/20200515200803.png)
> - -p 3306:3306 即将容器的3306端口映射到主机的3306端口上  
> - -e MYSQL_ROOT_PASSWORD=123456 即设置环境变量,用户为root，密码为123456

不映射目录的情况下数据不能持久化保存,容器没了就得跑路了

### 2.2 映射目录
```
docker run -itd -p 主机端口:3306 -v 宿主机目录:/var/lib/mysql -e MYSQL_ROOT_PASSWORD= 密码  镜像id
```

![](http://cdn.hurra.ltd/img/20200515201929.png)

这样容器内的 **/var/lib/mysql** 目录映射到了宿主机的**D:/volume/mysql**目录上,容器没了数据还在

![](http://cdn.hurra.ltd/img/20200515202929.png)

---

## 3. 远程连接

登录MySQL
```shell
docker exec -it <容器id/容器名> bash

mysql -u root -p
```

![](http://cdn.hurra.ltd/img/20200515202434.png)

允许远程登录

```shell
grant all privileges on *.* to 'root'@'%' identified by '刚设置的MYSQL密码';

flush privileges;
```


![](http://cdn.hurra.ltd/img/20200515202734.png)

测试:新建一个数据库Test

![](http://cdn.hurra.ltd/img/20200515234119.png)


如果设置了目录映射的话就能在宿主机中看见了

![](http://cdn.hurra.ltd/img/20200515234144.png)

## 4.常见问题

### 4.1 中文乱码

进入容器内,执行
```sh
echo "character-set-server=utf8" >> /etc/mysql/mysql.conf.d/mysqld.cnf

service mysql restart
```

### 4.2 降低占用内存
进入容器内
```shell
vim /etc/mysql/mysql.conf.d/mysqld.cnf
```
在mysqld.cnf最后追加:

```shell
performance_schema_max_table_instances=400

table_definition_cache=400

table_open_cache=256
```
重启容器或者重启MySQL服务即可
