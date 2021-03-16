# CentOS安装Python3


安装编译所需依赖

```sh
yum -y install gcc zlib* libffi-devel
```

下载 Python3

```sh
wget https://www.python.org/ftp/python/3.8.0/Python-3.8.0.tar.xz
```

![](https://cdn.hurra.ltd/img/20200628164902.png)

解压文件

```sh
tar -xvf Python-3.8.0.tar.xz -C /usr/bin
```

设置环境变量

```sh
cd /usr/bin/Python-3.8.0

./configure --prefix=/usr/bin/python3
```

> - ./configure 用来检测依赖
> - prefix 定义 Python3 安装的位置

编译安装

```sh
make && make install
```

最终结果

![](https://cdn.hurra.ltd/img/20200628170422.png)



查看 python 的默认版本

```sh
python -V
```

![](https://cdn.hurra.ltd/img/20200628170509.png)

设置环境变量,修改`~/.bash_profile`中对应内容:

```sh
# python3的安装路径

PATH=$PATH:$HOME/bin:/usr/bin/python3/bin
```

![](https://cdn.hurra.ltd/img/20200628173314.png)

使对配置的修改生效

```sh
source ~/.bash_profile
```

查看版本

```py
python3 -V
```

![](https://cdn.hurra.ltd/img/20200628173400.png)

## pip3 换源



创建 `~/.pip` 目录,编辑 `pip.conf`文件

```ini
[global]
index-url=http://mirrors.aliyun.com/pypi/simple/

[install]
trusted-host=mirrors.aliyun.com
```

测试

```py
pip3 install --upgrade pip
```

![](https://cdn.hurra.ltd/img/20200628190234.png)


![](https://cdn.hurra.ltd/img/收款码.png)
