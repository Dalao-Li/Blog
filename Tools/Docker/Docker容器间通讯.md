# --link 命令(不建议采用)

- 容器互 ping

拉取镜像

```shell
docker pull busybox
```

建立名为 box_1 的容器

```sh
docker run -itd --name box_1 busybox /bin/sh
```

建立名为 box_2 的容器,并且 link 到 box_1 容器

```sh
docker run -itd --name box_2 --link box_1 busybox /bin/sh
```

获取容器的 IP 地址

```sh
docker exec -it <container name> ip a|grep 172
```

![](http://cdn.hurra.ltd/img/20200726113742.png)

box_1 容器 IP : 172.17.0.2  
box_2 容器 IP : 172.17.0.3

使用 box_1 容器 ping box_2 容器

![](http://cdn.hurra.ltd/img/20200726114146.png)

![](http://cdn.hurra.ltd/img/20200726114219.png)

---

- 跨容器访问

> 建立一个 ubuntu 容器,使用--link 命令连接建立的 mysql 容器,实现从 ubuntu 容器中访问 mysql 服务

建立 MySQL 容器

```shell
docker run -itd --name mysql_server -e MYSQL_ROOT_PASSWORD=123 mysql:5.7
```

建立 ubuntu 容器,并与之前创建的 MySQL 容器作链接

```shell
docker run -itd --name ubuntu_demo --link mysql_server:db ubuntu
```

![](http://cdn.hurra.ltd/img/20200726152144.png)

进入 ubuntu 容器,安装 mysql-client

```sh
docker exec -it uubuntu_demo bash

apt-get update

apt-get install -y mysql-client
```

![](http://cdn.hurra.ltd/img/20200726152910.png)

登录 mysql 服务

```shell
mysql -h db -u root -p123
```

> - h : 主机地址,db 使用--link 命令时为 mysql_server 设置的别名
> - p : 创建 mysql 容器时设置的密码

![](http://cdn.hurra.ltd/img/20200726152540.png)

# 网络互联

查看当前 docker 可使用网络

```
docker network ls
```

![](http://cdn.hurra.ltd/img/20200726153304.png)

创建一个 docker 网络

```
docker network create -d bridge my_bridge
```

> - d : 指定类型

![](http://cdn.hurra.ltd/img/20200726153641.png)

新建容器 box_3,使用 my_bridge 网络

```shell
docker run -itd --name box_3 --network my_bridge  busybox /bin/sh
```

![](http://cdn.hurra.ltd/img/20200726154102.png)

可看到 box_3 容器的 IP 为 172.18.0.2,与之前创建的容器网段不同

再建立容器 box_4,使用 my_bridge 网络

![](http://cdn.hurra.ltd/img/20200726154325.png)

box_3 ping box_4

![](http://cdn.hurra.ltd/img/20200726154511.png)

box_4 ping box_3

![](http://cdn.hurra.ltd/img/20200726154622.png)

---![](http://cdn.hurra.ltd/img/20200726154622.png)





![](http://cdn.hurra.ltd/img/收款码.png)
