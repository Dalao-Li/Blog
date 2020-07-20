# 一、目的
在CentOS7上安装Docker并换源

# 二、过程

## 2.1 更新源
```
yum update
```
## 2.2 安装依赖
```
yum install -y yum-utils 

yum install -y device-mapper-persistent-data 

yum install -y lvm2 
```

## 2.3 设置yum源

这里是阿里源
```
yum-config-manager --add-repo http://mirrors.aliyun.com/docker-ce/linux/centos/docker-ce.repo
```
![](http://cdn.hurra.ltd/img/20200623102055.png)
查看仓库中所有Docker版本
```
yum list docker-ce --showduplicates | sort -r
```
![](http://cdn.hurra.ltd/img/20200623102007.png)
## 2.4 安装
```
yum install docker-ce-18.03.1.ce
```

## 2.5 启动
```
systemctl start docker

#设置开机自启
systemctl enable docker

```
查看Docker版本
```
docker info
```
![](http://cdn.hurra.ltd/img/20200623102258.png)

## 2.6 换源
```
vim /etc/docker/daemon.json
```
添加以下内容
```
{
  "registry-mirrors": ["https://docker.mirrors.ustc.edu.cn"]
}

```
重启docker
```
systemctl restart docker
```