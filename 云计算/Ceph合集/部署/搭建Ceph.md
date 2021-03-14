<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-12 17:02:33
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-03-14 20:35:18
-->
## 关闭防火墙

```sh
systemctl stop firewalld

systemctl disable firewalld

sed -i -e  's/^SELINUX=.*/SELINUX=disabled/g' /etc/selinux/config
setenforce 0
```

## 配置源
```sh
rm -rf /etc/yum.repos.d/*

curl -o /etc/yum.repos.d/CentOS-Base.repo https://mirrors.aliyun.com/repo/Centos-7.repo

curl -o /etc/yum.repos.d/epel.repo https://mirrors.aliyun.com/repo/epel-7.repo
```

编辑/etc/yum.repos.d/ceph.repo

```ini
[ceph]
name=ceph
baseurl=http://mirrors.aliyun.com/ceph/rpm-nautilus/el7/x86_64/
gpgcheck=0
priority =1

[ceph-noarch]
name=cephnoarch
baseurl=http://mirrors.aliyun.com/ceph/rpm-nautilus/el7/noarch/
gpgcheck=0
priority =1

[ceph-source]
name=cephsource
baseurl=http://mirrors.aliyun.com/ceph/rpm-nautilus/el7/SRPMS/
gpgcheck=0
priority =1
```


```sh
yum makecache fast
```
![](https://cdn.hurra.ltd/img/20210314133418.png)

## 设置主机名

编辑/etc/hosts文件,增加

```sh
......

[主机IP]  [HOSTNAME]
```

## 安装Ceph包

```sh
yum install -y ceph-deploy-2.0.1 ceph-14.2.4 ceph-radosgw-14.2.4
```

## 部署Ceph集群

```sh
cd /etc/ceph/

ceph-deploy new [HOSTNAME]

ceph-deploy install [HOSTNAME]
```

![](https://cdn.hurra.ltd/img/20210314171016.png)


## 初始化Monitor

```sh
cd /etc/ceph/

ceph-deploy mon create-initial

ceph-deploy admin [HOSTNAME]

```

启动Monitor节点后Ceph集群就可以访问了,通过ceph -s命令可以查看集群的状态

![](https://cdn.hurra.ltd/img/20210313002104.png)

## 部署manager daemon

```sh
cd /etc/ceph/

ceph-deploy mgr create [HOSTNAME]
```

## 安装osd

给主机添加一块1GB和2GB的新硬盘,默认为sdb sdc

![](https://cdn.hurra.ltd/img/20210314172220.png)


创建 OSD 前需要清空分区(新建的盘无需此操作)

```sh
ceph-deploy disk zap [HOSTNAME] [磁盘路径]
```
![](https://cdn.hurra.ltd/img/20210314172331.png)

为集群增加OSD(luminous版本后不支持目录挂载)

```sh
ceph-deploy osd create --data [磁盘路径] [HOSTNAME]
```
![](https://cdn.hurra.ltd/img/20210314172650.png)

- osd 状态

```sh
ceph osd tree
```
## 设置存储池

-  获取存储池列表

```sh
ceph osd lspools
```

![](https://cdn.hurra.ltd/img/20210314174938.png)

-  创建pools

```sh
ceph osd pool create [存储池名称] 64
```

![](https://cdn.hurra.ltd/img/20210314175355.png)

-   删除pools
-   
```sh
ceph osd pool delete [存储池名称] [存储池名称] --yes-i-really-really-mean-it
```

若出现以下错误:

```sh
Error EPERM: pool deletion is disabled; you must first set the mon_allow_pool_delete config option to true before you can destroy a pool
```

则编辑ceph.conf增加:

```sh
......
[mon]
mon allow pool delete = true
```
重启ceph-mon服务
```sh
systemctl restart ceph-mon.target
```
在执行删除指令即可

![](https://cdn.hurra.ltd/img/20210314180155.png)


## 部署元数据服务器

使用CephFS时,必须至少部署一个元数据服务器

```sh
ceph-deploy mds create [HOSTNAME]
```

## 部署对象网关服务实例

```sh
ceph-deploy rgw create [HOSTNAME]
```


## 查看ceph 健康状态

```sh
ceph health

ceph health detail
```

![](https://cdn.hurra.ltd/img/20210314173535.png)

- 问题1:缺少相应库

```sh
Module 'volumes' has failed dependency: No module named typing
```

python缺少相应库,pip安装即可

```sh
# 若没有pip则安装
yum install -y python-pip -i https://pypi.douban.com/simple

pip install typing
```
若未解决则重启机器

- 问题2:

```sh
Reduced data availability: 32 pgs inactive; Degraded data redundancy: 32 pgs undersized; OSD count 2 < osd_pool_default_size 3
```
编辑rec/ceph/ceph.conf

```sh
......增加

osd_pool_default_size = 2
```

## ceph 集群详细状态

```sh
ceph -s

ceph status

```
## 配置ceph的web管理界面

安装

```sh
yum install ceph-mgr-dashboard -y

```

启用dashboard

```sh
ceph mgr module enable dashboard --force
```


创建自签名证书

```sh
ceph dashboard create-self-signed-cert
```


生成密钥,生成两个文件:dashboard.crt dashboard.key

```sh
mkdir mgr-dashboard

cd mgr-dashboard

openssl req -new -nodes -x509   -subj "/O=IT/CN=ceph-mgr-dashboard" -days 3650   -keyout dashboard.key -out dashboard.crt -extensions v3_ca

```

配置服务地址、端口,默认的端口是8443

```sh
ceph config set mgr mgr/dashboard/server_addr 0.0.0.0
ceph config set mgr mgr/dashboard/ssl true
ceph config set mgr mgr/dashboard/ssl_server_port 8443
```


修改完端口后,需要重启服务

```sh
systemctl reset-failed ceph-mgr@[HOSTNAME].service

systemctl restart ceph-mgr@[HOSTNAME]

systemctl status ceph-mgr@[HOSTNAME]
```
![](https://cdn.hurra.ltd/img/20210314203317.png)

创建用户、密码

```sh
ceph dashboard ac-user-create admin -i admin administrator
```
![](https://cdn.hurra.ltd/img/20210314202416.png)

![](https://cdn.hurra.ltd/img/20210314203426.png)

![](https://cdn.hurra.ltd/img/20210314203513.png)

> 官方文档 : https://docs.ceph.com/en/latest/mgr/dashboard/

