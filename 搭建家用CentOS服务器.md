# 一、目的
搭建一台CentOS系统的家用服务器


# 二、前期准备

## 2.1 硬件部分

![](http://cdn.hurra.ltd/img/IMG_20200531_163807.jpg)

从废品站里20大洋淘来了一台2007年的电脑,配置如下
> - CPU:  Intel(R) Celeron(R) CPU 420  @ 1.60GHz
> - 内存：1GB杂牌
> - 硬盘：500GB希捷

## 2.2 软件部分

安装Centos7系统,没有图形界面,纯命令行操作

## 2.3 网络部分

电脑直连服务器,设置静态IP,通过SSH进行登录

# 三、搭建结果

配置了静态IP为192.168.3.15

![](http://cdn.hurra.ltd/img/20200531165606.png)
<center>SSH登录</center>

---

![](http://cdn.hurra.ltd/img/20200531165639.png)
<center>查看主板信息</center>

---

![](http://cdn.hurra.ltd/img/20200531165807.png)
<center>查看BIOS信息</center>

---

![](http://cdn.hurra.ltd/img/20200531170105.png)
<center>最大支持4GB内存....</center>

---

# 三、搭建过程

## 3.1 镜像制作

### 3.1.1 镜像的选择

使用CentOS的Minimal版本,特点是安装完成后没有图形界面,比较轻量,毕竟服务器只有1G的内存,能省就省了   

[下载地址--阿里源](http://mirrors.aliyun.com/centos/7/isos/x86_64/)

![](http://cdn.hurra.ltd/img/20200531165035.png)

### 3.1.2 启动盘的制作

各显神通了,博主使用的是软碟通,当然使用大白菜,老毛桃也是可以的

### 3.1.3 系统的安装

**注意! 此处为了演示方便,使用了虚拟机再现了安装过程**

![](http://cdn.hurra.ltd/img/20200531172003.png)  

网络选择桥接模式,毕竟服务器是直接连接网络的
![](http://cdn.hurra.ltd/img/20200531172103.png)  

安装页面
![](http://cdn.hurra.ltd/img/20200531172225.png)

![](http://cdn.hurra.ltd/img/20200531172335.png)
设置下网络和硬盘
![](http://cdn.hurra.ltd/img/20200531172403.png)

![](http://cdn.hurra.ltd/img/20200531172302.png)

![](http://cdn.hurra.ltd/img/20200531172448.png)

然后重启等待进入系统即可

## 3.2 系统设置

开机进行登录,无图形界面

![](http://cdn.hurra.ltd/img/20200531172943.png)

## 3.2.1 系统优化

### 1. 换源
~~~shell
vi /etc/yum.repos.d/CentOS-Base.repo
~~~

在 mirrorlist= 开头行前面加 # 注释掉  
将 baseurl= 开头行取消注释,输入vi命令将该行内的mirror.centos.org换掉

~~~shell
%s/mirror.centos.org/mirrors.aliyun.com/g
~~~



![](http://cdn.hurra.ltd/img/20200531180352.png)
### 2. 配置SSH

开放端口,设置允许密码连接,允许root用户连接

[给小白的教程](https://blog.csdn.net/qq_41452937/article/details/106187241)


启动ssh服务
~~~
systemctl start sshd.service
~~~

## 3.2.2 设置静态IP

> 这里我准备将服务器的ip设为192.168.3.20

### 1. 宿主机配置
![](http://cdn.hurra.ltd/img/20200531180759.png)
记下IP地址,子网掩码,默认网关,服务器的ip应该设置为**192.168.3.XXX**,必须和宿主机在一个网段

### 2. 查看网卡
~~~
ifconfig
~~~
![](http://cdn.hurra.ltd/img/20200531181036.png)

我这里的网卡名为ens33,你操作时请以你的实际网卡名为准  

### 3. 修改配置文件
~~~
/etc/sysconfig/network-scripts/ifcfg-ens33
~~~

### 3.1 修改   

BOOTPROTO="static"  
ONBOOT="yes  

### 3.2新增
~~~
#IP地址前三位要和自己宿主机的一养
IPADDR=192.168.3.20

#子网掩码也一致
NETMASK=255.255.255.0

#网关也和宿主机一致
GATEWAY=192.168.3.1

#增加DNS
DNS1=192.168.3.1
DNS2=8.8.8.8
~~~
### 4. 配置文件
![](http://cdn.hurra.ltd/img/20200531183752.png)

### 5. 重启网络
~~~
service network restart
~~~

### 6. 测试

>  **注:**  
>  使用虚拟机模拟的时候可能出现无法ping通的问题  
>  进入虚拟机的虚拟网络编辑器,选择电脑的外部网卡,我这里选择的是连接以太网的网卡
>  搭建物理服务器的时候并没有出现这种情况

![](http://cdn.hurra.ltd/img/20200531194956.png)

---


> 服务器IP 192.168.3.20  
>
> 宿主机IP 192.168.3.10

#### 6.1 宿主机ping服务器


![](http://cdn.hurra.ltd/img/20200531195148.png)


#### 6.2 服务器ping宿主机

![](http://cdn.hurra.ltd/img/20200531195246.png)

#### 6.3 服务器ping百度

![](http://cdn.hurra.ltd/img/20200531195515.png)


## 3.2.3 设置ssh开机自启

~~~shell
systemctl enable sshd
~~~

## 3.2.4 设置开机自动以root用户登录
我这台服务器没外接显示器,所以希望开机后自动以root用户登录,这样我就能以SSH登录它了   



打开文件
~~~
vim /etc/systemd/system/getty.target.wants/getty@tty1.service
~~~
修改配置如下
~~~
[Service]
...
ExecStart=-/sbin/agetty --autologin root --noclear %I
~~~

重启即可
~~~
reboot
~~~

[Centos7 设置开机自动登录](https://blog.csdn.net/qq_41452937/article/details/106447595)


# 五、最终成果

![](http://cdn.hurra.ltd/img/20200531200411.png)

![](http://cdn.hurra.ltd/img/IMG_20200531_200526.jpg)

接下来就可以愉快的玩耍了,嘿嘿！

作者QQ: **1061299112** 有什么问题欢迎来讨论