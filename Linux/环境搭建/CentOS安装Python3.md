# CentOS安装Python3

## 安装

- 安装编译 Python 所需依赖

```shell
yum -y install gcc zlib* libffi-devel
```

- 下载 Python3

```shell
wget https://www.python.org/ftp/python/3.8.0/Python-3.8.0.tar.xz
```

![](https://cdn.hurra.ltd/img/20200628164902.png)

- 解压文件到指定路径

```shell
tar -xvf Python-3.8.0.tar.xz -C /usr/bin
```

- 设置环境变量

```shell
cd /usr/bin/Python-3.8.0

./configure --prefix=/usr/bin/python3
```

> - ./configure 用来检测依赖
> - prefix 定义 Python3 安装的位置

- 编译安装

```shell
make && make install
```

最终结果

![](https://cdn.hurra.ltd/img/20200628170422.png)

## 设置

- 查看 python 的默认版本

```shell
python -V
```

![](https://cdn.hurra.ltd/img/20200628170509.png)

- 设置环境变量,修改~/.bash_profile 内容为

```shell
# python3的安装路径

PATH=$PATH:$HOME/bin:/usr/bin/python3/bin

export PATH
```

![](https://cdn.hurra.ltd/img/20200628173314.png)

- 使对配置的修改生效

```shell
source ~/.bash_profile
```

- 查看版本

```py
python3 -V
```

![](https://cdn.hurra.ltd/img/20200628173400.png)

## pip3 换源

- 进入 python3 的 bin 目录

```shell
cd /usr/bin/python3/bin
```

- 创建 `~/.pip` 文件夹,编辑 `~/.pip/pip.conf`

```sh
[global]

index-url = https://pypi.tuna.tsinghua.edu.cn/simple
```

测试

![](https://cdn.hurra.ltd/img/20200628190234.png)

---

![](https://cdn.hurra.ltd/img/收款码.png)
