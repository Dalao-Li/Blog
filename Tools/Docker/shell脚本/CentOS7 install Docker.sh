
###
 # @Description: 
 # @Version: 
 # @Autor: Li Yuanhao
 # @Date: 2021-01-16 17:59:34
 # @LastEditors: Li Yuanhao
 # @LastEditTime: 2021-01-25 21:37:57
### 

#!/bin/sh
echo "------更新源与安装依赖------" 

sudo yum update -y 

sudo yum install -y yum-utils device-mapper-persistent-data lvm2

sudo yum-config-manager --add-repo http://mirrors.aliyun.com/docker-ce/linux/centos/docker-ce.repo

echo "------更新源与安装依赖------" 

sudo yum install -y docker-ce-19.03.1.ce 

systemctl enable docker 

echo "------Docker安装成功------" 

echo "------开始添加用户组------" 

# 添加docker用户组
sudo groupadd docker 

# 将登陆用户加入到docker用户组中
sudo gpasswd -a $USER docker  

# 更新用户组
newgrp docker 

echo "--------添加用户组完成------" 

# 换源
echo -e "{\n \"registry-mirrors\": [\"https://docker.mirrors.ustc.edu.cn\"] \n}" >> /etc/docker/daemon.json 

systemctl restart docker

echo "------已经换源至中科大的docker源------" 

