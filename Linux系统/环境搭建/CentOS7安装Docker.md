<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:34
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-19 15:46:11
-->

# Centos7 安装Docker

## 准备

- 更新 yum 源

```shell
yum update
```

- 安装依赖

```sh
yum install -y yum-utils device-mapper-persistent-data lvm2
```

## 设置 yum 源

此处使用阿里源

```shell
yum-config-manager --add-repo http://mirrors.aliyun.com/docker-ce/linux/centos/docker-ce.repo
```

![](https://cdn.hurra.ltd/img/20200623102055.png)

查看仓库中所有 Docker 版本

```shell
yum list docker-ce --showduplicates | sort -r
```

![](https://cdn.hurra.ltd/img/20200623102007.png)

- 安装

```shell
yum install -y docker-ce
```

- 启动

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

若在root权限,则可直接输入docker命令;否则需添加用户组,这样就不必在加sudo进行操作了.

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

编辑/etc/docker/daemon.json文件

添加以下内容

```sh
{
  "registry-mirrors": ["https://docker.mirrors.ustc.edu.cn"]
}
```

重启 docker

```shell
systemctl restart docker
```

---

![](https://cdn.hurra.ltd/img/收款码.png)
