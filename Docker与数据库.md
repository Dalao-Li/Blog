# 一、Docker搭建MySQL

## 1. 获取镜像
```c++
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

这样就容器内的 **/var/lib/mysql** 目录映射到了宿主机的**D:/volume/mysql**目录上,容器没了数据还在

![](http://cdn.hurra.ltd/img/20200515202929.png)

---

## 3. 远程连接

### 3.1 登录MySQL
```
docker exec -it 容器id bash

mysql -u root -p

```
输入刚才设置的密码

![](http://cdn.hurra.ltd/img/20200515202434.png)
### 3.2 设置允许远程登录

```
grant all privileges on *.* to 'root'@'%' identified by 'MYSQL密码';

flush privileges;
```


![](http://cdn.hurra.ltd/img/20200515202734.png)

### 3.3 使用软件连接
![](http://cdn.hurra.ltd/img/20200515202850.png)

### 3.4 测试

新建一个数据库Test

![](http://cdn.hurra.ltd/img/20200515234119.png)


如果设置了目录映射的话就能在宿主机中看见了

![](http://cdn.hurra.ltd/img/20200515234144.png)
