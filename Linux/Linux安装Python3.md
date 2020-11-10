# 1. 安装

安装编译 Python 所需依赖

```shell
yum -y install gcc zlib* libffi-devel
```

下载 Python3

```shell
wget https://www.python.org/ftp/python/3.8.0/Python-3.8.0.tar.xz
```

![](http://cdn.hurra.ltd/img/20200628164902.png)

解压文件到指定路径

```shell
tar -xvf Python-3.8.0.tar.xz -C /usr/bin
```

进入

```shell
cd /usr/bin/Python-3.8.0
```

输入

```shell
./configure --prefix=/usr/bin/python3
```

> - ./configure 用来检测依赖
> - prefix 定义 Python3 安装的位置

编译安装

```shell
make && make install
```

最终结果

![](http://cdn.hurra.ltd/img/20200628170422.png)

# 2. 设置

查看 python 的默认版本

```shell
python -V
```

![](http://cdn.hurra.ltd/img/20200628170509.png)

设置环境变量,修改~/.bash_profile 内容为

```shell
# python3的安装路径

PATH=$PATH:$HOME/bin:/usr/bin/python3/bin

export PATH
```

![](http://cdn.hurra.ltd/img/20200628173314.png)

使对配置的修改生效

```shell
source ~/.bash_profile
```

查看版本

```py
python3 -V
```

![](http://cdn.hurra.ltd/img/20200628173400.png)

# 3. pip3 换源

进入 python3 的 bin 目录

```shell
cd /usr/bin/python3/bin
```

创建

```shell
mkdir ~/.pip
```

编辑

```shell
vim ~/.pip/pip.conf
```

写入

```shell
[global]

index-url = https://pypi.tuna.tsinghua.edu.cn/simple
```

测试

![](http://cdn.hurra.ltd/img/20200628190234.png)

---

![](http://cdn.hurra.ltd/img/收款码.png)
