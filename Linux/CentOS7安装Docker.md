# 一键 shell 脚本

```c
#!/bin/sh
echo "------更新源与安装依赖------"

yum update -y

yum install -y yum-utils device-mapper-persistent-data lvm2

yum-config-manager --add-repo http://mirrors.aliyun.com/docker-ce/linux/centos/docker-ce.repo

echo "------更新源与安装依赖------"

yum install -y docker-ce-18.03.1.ce

systemctl enable docker

echo "------Docker安装成功------"

# 换源
echo -e "{\n \"registry-mirrors\": [\"https://docker.mirrors.ustc.edu.cn\"] \n}" >> /etc/docker/daemon.json

systemctl restart docker

echo "------已经换源至中科大的docker源------"
```

# 1. 更新 yum 源

```shell
yum update
```

# 2. 安装依赖

```shell
yum install -y yum-utils

yum install -y device-mapper-persistent-data

yum install -y lvm2
```

# 3. 设置 yum 源

此处使用阿里源

```shell
yum-config-manager --add-repo http://mirrors.aliyun.com/docker-ce/linux/centos/docker-ce.repo
```

![](http://cdn.hurra.ltd/img/20200623102055.png)

查看仓库中所有 Docker 版本

```shell
yum list docker-ce --showduplicates | sort -r
```

![](http://cdn.hurra.ltd/img/20200623102007.png)

# 4. 安装

```shell
yum install docker-ce-18.03.1.ce
```

# 5. 启动

```shell
systemctl start docker

# 设置开机自启
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
