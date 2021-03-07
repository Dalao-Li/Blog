<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:34
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-03-05 19:13:58
-->

# Centos7 安装Docker

## 卸载旧版本

使用以下命令卸载旧版本Docker:

```sh
sudo yum remove \
                docker \
                docker-client \
                docker-client-latest \
                docker-common \
                docker-latest \
                docker-latest-logrotate \
                docker-logrotate \
                docker-selinux \
                docker-engine-selinux \
                docker-engine
```


## 安装

安装依赖

```sh
yum install -y yum-utils device-mapper-persistent-data lvm2
```
添加 yum 软件源

```sh
sudo yum-config-manager --add-repo https://mirrors.aliyun.com/docker-ce/linux/centos/docker-ce.repo

sudo sed -i 's/download.docker.com/mirrors.aliyun.com\/docker-ce/g' /etc/yum.repos.d/docker-ce.repo
```
更新 yum 软件源缓存，并安装 docker-ce

```sh
sudo yum install docker-ce docker-ce-cli containerd.io
```

启动

```shell
systemctl start docker

# 设置开机自启
systemctl enable docker
```

查看 Docker 版本

```shell
docker info
```

## 注意

若在root权限,则可直接输入docker命令;否则需添加用户组,这样就不必在加sudo进行操作.

```shell
# 添加docker用户组
sudo groupadd docker

# 将登陆用户加入到docker用户组中
sudo gpasswd -a $USER docker

# 更新用户组
newgrp docker
```

![](https://cdn.hurra.ltd/img/20200623102258.png)

## 换源

编辑/etc/docker/daemon.json文件,添加以下内容

```sh
{
  "registry-mirrors": ["https://docker.mirrors.ustc.edu.cn"]
}
```

重启 docker

```shell
systemctl restart docker
```


![](https://cdn.hurra.ltd/img/收款码.png)
