
###
 # @Description: 
 # @Version: 
 # @Autor: Li Yuanhao
 # @Date: 2021-01-16 17:59:34
 # @LastEditors: Li Yuanhao
 # @LastEditTime: 2021-02-23 19:26:34
### 

#!/bin/sh

sudo yum update -y 

sudo yum install -y yum-utils device-mapper-persistent-data lvm2

sudo yum-config-manager --add-repo https://mirrors.aliyun.com/docker-ce/linux/centos/docker-ce.repo

sudo sed -i 's/download.docker.com/mirrors.aliyun.com\/docker-ce/g' /etc/yum.repos.d/docker-ce.repo

sudo yum install docker-ce docker-ce-cli containerd.io

# 添加docker用户组
sudo groupadd docker 

# 将登陆用户加入到docker用户组中
sudo gpasswd -a $USER docker  

# 更新用户组
newgrp docker 

# 换源
echo -e "{\n \"registry-mirrors\": [\"https://docker.mirrors.ustc.edu.cn\"] \n}" >> /etc/docker/daemon.json 

systemctl restart docker



