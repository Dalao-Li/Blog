## 目录

- [一、目的](#一目的)
- [二、过程](#二过程)
  - [2.1 安装](#21-安装)
  - [2.2 设置](#22-设置)
  - [2.3 pip3换源](#23-pip3换源)

# 一、目的

CentOS安装Python3,并对pip3并换源


# 二、过程

## 2.1 安装

安装编译Python所需的依赖
```s
yum -y install gcc zlib* libffi-devel
```
下载Python3

```s
wget https://www.python.org/ftp/python/3.8.0/Python-3.8.0.tar.xz
```

![](http://cdn.hurra.ltd/img/20200628164902.png)


解压文件到指定路径
```s
tar -xvf Python-3.8.0.tar.xz -C /usr/bin
```
进入路径中
```s
cd /usr/bin/Python-3.8.0
```

输入以下命令
```s
./configure --prefix=/usr/bin/python3
```
> -  ./configure用来检测依赖
> -  prefix定义Python3安装的位置

编译安装
```s
make && make install 
```
最终结果

![](http://cdn.hurra.ltd/img/20200628170422.png)

## 2.2 设置

查看python的默认版本

```
python -V 
```

![](http://cdn.hurra.ltd/img/20200628170509.png)
设置环境变量
```shell
vim ~/.bash_profile
```
修改内容为
```shell
# python3的安装路径

PATH=$PATH:$HOME/bin:/usr/bin/python3/bin

export PATH
```
图示

![](http://cdn.hurra.ltd/img/20200628173314.png)

执行以下命令使对配置的修改生效
```shell
source ~/.bash_profile
```
查看版本
```py
python3 -V
```
![](http://cdn.hurra.ltd/img/20200628173400.png)

## 2.3 pip3换源

进入python3的bin目录
```s
cd /usr/bin/python3/bin
```
创建文件夹
```s
mkdir ~/.pip
```
编辑文件
```s
vim ~/.pip/pip.conf
```
写入以下内容
```s
[global]

index-url = https://pypi.tuna.tsinghua.edu.cn/simple
```
测试

![](http://cdn.hurra.ltd/img/20200628190234.png)

---

![](http://cdn.hurra.ltd/img/赞赏码.png)
