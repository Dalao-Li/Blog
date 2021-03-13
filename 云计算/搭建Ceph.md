<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-12 17:02:33
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-03-13 22:57:59
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
```

## 部署

```sh
cd /etc/ceph/

ceph-deploy install [HOSTNAME]
```

## 初始化mon

```sh
cd /etc/ceph/

ceph-deploy mon create-initial

ceph-deploy admin [HOSTNAME]

```

启动Monitor节点后Ceph集群就可以访问了，通过ceph -s命令可以查看集群的状态

![](https://cdn.hurra.ltd/img/20210313002104.png)

## 部署manager daemon

```sh
cd /etc/ceph/

ceph-deploy mgr create [HOSTNAME]
```

## 安装osd

使用 sdb 创建 OSD 前，需要清空分区（新建的盘无需此操作）

ceph-deploy disk zap $HOSTNAME /dev/sdb
或
wipefs --all --force /dev/sdb


为集群增加 osd（自从luminous版本后，不支持目录挂载了）

```
ceph-deploy osd create --data /dev/sdb [HOSTNAME]
```