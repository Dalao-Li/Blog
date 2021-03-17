###
 # @Description: Centos7 安装Docker脚本
 # @Version: v1
 # @Autor: Li Yuanhao
 # @Date: 2021-01-16 17:59:34
 # @LastEditors: Li Yuanhao
 # @LastEditTime: 2021-03-17 00:22:20
### 

#!/bin/sh

yum update -y &&

yum install -y yum-utils device-mapper-persistent-data lvm2 &&

yum-config-manager --add-repo https://mirrors.aliyun.com/docker-ce/linux/centos/docker-ce.repo &&

sed -i 's/download.docker.com/mirrors.aliyun.com\/docker-ce/g' /etc/yum.repos.d/docker-ce.repo &&

yum install docker-ce docker-ce-cli containerd.io


## 修改下这里,加一个判断当前用户是否为root


# 添加docker用户组
sudo groupadd docker 

# 将登陆用户加入到docker用户组中
sudo gpasswd -a $USER docker  

# 更新用户组
newgrp docker 

# 换源
echo -e "{\n \"registry-mirrors\": [\"https://docker.mirrors.ustc.edu.cn\"] \n}" >> /etc/docker/daemon.json 

systemctl restart docker



