###
 # @Description: 
 # @Version: 1.0
 # @Author: Li Yuanhao
 # @Email: dalao_li@163.com
 # @Date: 2021-01-16 17:59:34
 # @LastEditors: Li Yuanhao
 # @LastEditTime: 2021-02-22 22:46:15
### 

#!/bin/sh

yum install -y wget

wget -O /etc/yum.repos.d/CentOS-Base.repo http://mirrors.aliyun.com/repo/Centos-7.repo

yum clean all

yum makecache

yum -y update

echo "换源完成"
