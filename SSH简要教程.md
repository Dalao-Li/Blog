# 一、教程目的
使用docker中的Ubuntu镜像模拟Linux服务端，实现在windows平台上

> 1.设置**密码**进行SSH的登录  
> 2.设置**密钥**进行SSH的登录

# 二、教程环境

> 客户端 : Windows  
> 服务端 : Ubuntu  
> SSH工具 : Windows Terminal

# 三、环境搭建

## 3.1 拉取镜像

```
docker pull ubuntu
```
![](http://cdn.hurra.ltd/img/20200518091750.png)
<center>这里我拉取的是我自己搭建的镜像</center>

## 3.2 创建容器，进入
```
docker run -itd -p 2222:22 my_ubuntu  
```
![](http://cdn.hurra.ltd/img/20200518091958.png)

```
docker exec -it 3c8 bash
```
将容器的22端口映射到宿主机的2222端口

## 3.2 更新软件源,安装ssh工具
```
vi /etc/apt/sources.list 将源换为国内源

apt-get update -y

apt-get install vim -y 

```

# 四、密码登录

## 4.1 编辑SSH配置文件

```
vim /etc/ssh/sshd_config

```
![](http://cdn.hurra.ltd/img/20200518092654.png)
![](http://cdn.hurra.ltd/img/20200518092925.png)

```
编辑完成后按Esc键,输入 wq! 敲回车，保存退出
```

## 4.2 添加登录密码

由于此处使用的是docker容器,所以还得给root用户设个密码
```
passwd
```
![](http://cdn.hurra.ltd/img/20200518093221.png)

## 4.3 开启ssh服务

```
service ssh start
```
![](http://cdn.hurra.ltd/img/20200518093307.png)

## 4.4 连接测试

使用ssh工具进行连接
```
ssh (-p 端口) 用户名@ip地址
```
输入对应用户的密码,连接即可

![](http://cdn.hurra.ltd/img/20200518093750.png)
> - -p 指定端口连接；容器的22端口映射到了宿主机的2222端口,所以此处的ssh应指定端口
> - root 即连接的用户名
> - ip地址,连接的地址,此处指宿主机地址  

例 : 连接默认22端口,用户为dalao,IP地址为192.168.0.104的子系统

![](http://cdn.hurra.ltd/img/20200518094213.png)

如果出现提示输入yes就行

---


# 五、密钥登录

## 5.1 制作密钥对
```
ssh-keygen
```
![](http://cdn.hurra.ltd/img/20200518094943.png)
成功生成了公钥和私钥,其保存地址为
```
公钥 : /root/.ssh/id_rsa.pub

私钥 : /root/.ssh/id_rsa

```
## 5.2 在服务端安装公钥并完成授权

```
cd .ssh

cat id_rsa.pub >> authorized_keys

chmod 600 authorized_keys

chmod 700 ~/.ssh

```

## 5.3 修改配置文件
```
vim /etc/ssh/sshd_config

将RSAAuthentication与RSAAuthentication修改为yes

将PasswordAuthentication修改为no，以禁用密码登录
```

![](http://cdn.hurra.ltd/img/20200518095533.png)

## 5.4 重启ssh

```
service ssh restart
```

## 5.5 下载私钥文件

将5.1生成的私钥文件id_rsa下载到客户端
![](http://cdn.hurra.ltd/img/20200518100050.png)

## 5.6 建立ssh连接时使用该私钥

![](http://cdn.hurra.ltd/img/20200518100506.png)

选择刚才生成的私钥,点击连接

![](http://cdn.hurra.ltd/img/20200518100557.png)

![](http://cdn.hurra.ltd/img/20200518100637.png)

输入登录的用户名
![](http://cdn.hurra.ltd/img/20200518100709.png)

<center>登录成功</center>