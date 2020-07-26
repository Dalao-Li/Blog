## 目录
- [一、--link命令](#一--link命令)
  - [1.1 容器互ping](#11-容器互ping)
  - [1.2 跨容器访问](#12-跨容器访问)
- [二、网络互联](#二网络互联)


# 一、--link命令

## 1.1 容器互ping

拉取镜像
```shell
docker pull busybox
```
建立名为box_1的容器
```shell
docker run -itd --name box_1 busybox /bin/sh
```

建立名为box_2的容器,并且link到box_1容器
```shell
docker run -itd --name box_2 --link box_1 busybox /bin/sh
```

获取容器的IP地址

```shell
docker exec -it <container name> ip a|grep 172
```

![](http://cdn.hurra.ltd/img/20200726113742.png)

box_1容器IP : 172.17.0.2  ;  box_2 容器IP : 172.17.0.3  

使用box_1容器ping box_2容器

![](http://cdn.hurra.ltd/img/20200726114146.png)

![](http://cdn.hurra.ltd/img/20200726114219.png)

---

## 1.2 跨容器访问


建立一个ubuntu容器,使用--link命令连接建立的mysql容器,实现从ubuntu容器中访问mysql服务

建立MySQL容器

```shell
docker run -itd --name mysql_server -e MYSQL_ROOT_PASSWORD=123 mysql:5.7

```

建立ubuntu容器

```shell
docker run -itd --name ubuntu_demo --link mysql_server:db ubuntu
```

![](http://cdn.hurra.ltd/img/20200726152144.png)

进入ubuntu容器,安装mysql-client
```shell
docker exec -it uubuntu_demo bash

apt-get update

apt-get install -y mysql-client
```
![](http://cdn.hurra.ltd/img/20200726152910.png)

登录mysql服务

```shell
mysql -h db -u root -p123
```
> - h : 主机地址,db 使用--link命令时为mysql_server设置的别名
> - p : 创建mysql容器时设置的密码


![](http://cdn.hurra.ltd/img/20200726152540.png)


# 二、网络互联

查看当前docker 可使用网络
```
docker network ls
```

![](http://cdn.hurra.ltd/img/20200726153304.png)


创建一个docker网络

```
docker network create -d bridge my_bridge
```
> - d : 指定类型

![](http://cdn.hurra.ltd/img/20200726153641.png)


新建容器box_3,使用my_bridge网络

```shell
docker run -itd --name box_3 --network my_bridge  busybox /bin/sh
```
![](http://cdn.hurra.ltd/img/20200726154102.png)

可看到box_3容器的IP为172.18.0.2,与之前创建的容器网段不同


再建立容器box_4,使用my_bridge网络

![](http://cdn.hurra.ltd/img/20200726154325.png)


box_3 ping box_4

![](http://cdn.hurra.ltd/img/20200726154511.png)

box_4 ping box_3

![](http://cdn.hurra.ltd/img/20200726154622.png)

---![](http://cdn.hurra.ltd/img/20200726154622.png)

![](http://cdn.hurra.ltd/img/赞赏码.png)
