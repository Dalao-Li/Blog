#!/bin/sh

# 在WSL2上安装Docker
echo "1.--------开始添加Docker源------" 

curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add - 

sudo add-apt-repository "deb [arch=amd64] https://mirrors.tuna.tsinghua.edu.cn/docker-ce/linux/ubuntu $(lsb_release -cs) stable" 

sudo apt-get update -y 

echo "--------添加Docker源完成------" 


echo "2.--------开始安装Docker------" 

sudo apt install -y docker-ce 

sudo service docker start 

echo "3.--------开始添加用户组------" 

# 添加docker用户组
sudo groupadd docker 

# 将登陆用户加入到docker用户组中
sudo gpasswd -a $USER docker  

# 更新用户组
newgrp docker 

echo "--------添加用户组完成------" 

# 换源
sudo vim /etc/docker/daemon.json 

echo - e "{\n \"registry-mirrors\": [\"https://docker.mirrors.ustc.edu.cn\"]\n" >> /etc/docker/daemon.json

sudo service docker restart


# {
#   "registry-mirrors": ["https://997nddro.mirror.aliyuncs.com"]
# }