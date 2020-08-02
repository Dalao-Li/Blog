#!/bin/sh

echo "------更新源与安装依赖------" &&

yum update -y &&

yum install -y yum-utils &&

yum install -y device-mapper-persistent-data &&

yum install -y lvm2 &&

yum-config-manager --add-repo &&http://mirrors.aliyun.com/docker-ce/linux/centos/docker-ce.repo

yum install -y docker-ce-18.03.1.ce &&

systemctl enable docker &&

systemctl enable docker &&

echo "------Docker安装成功------" 