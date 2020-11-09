## 目录

- [1. 更新 yum 源](#1-更新yum源)
- [2. 安装依赖](#2-安装依赖)
- [3. 设置 yum 源](#3-设置yum源)
- [4. 安装](#4-安装)
- [5. 启动](#5-启动)
- [6. 换源](#6-换源)

# 1. 更新 yum 源

```sh
yum update
```

# 2. 安装依赖

```sh
yum install -y yum-utils

yum install -y device-mapper-persistent-data

yum install -y lvm2
```

# 3. 设置 yum 源

此处使用阿里源

```s
yum-config-manager --add-repo http://mirrors.aliyun.com/docker-ce/linux/centos/docker-ce.repo
```

![](http://cdn.hurra.ltd/img/20200623102055.png)

查看仓库中所有 Docker 版本

```s
yum list docker-ce --showduplicates | sort -r
```

![](http://cdn.hurra.ltd/img/20200623102007.png)

# 4. 安装

```s
yum install docker-ce-18.03.1.ce
```

# 5. 启动

```s
systemctl start docker

#设置开机自启
systemctl enable docker

```

查看 Docker 版本

```
docker info
```

![](http://cdn.hurra.ltd/img/20200623102258.png)

# 6. 换源

```shell
vim /etc/docker/daemon.json
```

添加以下内容

```shell
{
  "registry-mirrors": ["https://docker.mirrors.ustc.edu.cn"]
}

```

重启 docker

```shell
systemctl restart docker
```

---

![](http://cdn.hurra.ltd/img/收款码.png)
