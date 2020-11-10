## 环境

> - 宿主机环境 WSL2
> - 基础容器 CentOS7

## 下载 arm-linux-gcc.tar

[下载路径](http://112.124.9.243/arm9net/mini2440/linux/arm-linux-gcc-4.4.3-20100728.tar.gz)

## 将 tar 包复制到新建的 CentOS7 容器

![](http://cdn.hurra.ltd/img/20200919202648.png)

## 解包到/home 路径

> tar -zxvf <包名> -C < 路径 >

```s
tar -zxvf arm-linux-gcc-4.4.3-20100728.tar.gz -C /home
```

![](http://cdn.hurra.ltd/img/20200919202951.png)

## 移动包中内容

> cp -r <源路径> <目标路径>

```s
cp -r /home/opt/FriendlyARM/toolschain/4.4.3 /usr/local/bin
```

![](http://cdn.hurra.ltd/img/20200919203033.png)

## 安装相关依赖

```shell
yum install -y epel-release
yum install -y glibc.i686
```

## 配置环境变量

编辑/etc/profile,末尾添加

```shell
export PATH=$PATH:/usr/local/arm/bin
source /etc/profile
```

![](http://cdn.hurra.ltd/img/20200919205735.png)

编辑 ~/.bashrc,末尾添加

```shell
if [ -f /etc/profile ]; then
. /etc/profile
fi
```

## 刷新环境变量

```shell
source /etc/profile
```

## 查看 arm-linux-gcc 版本

```shell
arm-linux-gcc -v
```

![](http://cdn.hurra.ltd/img/20200919210020.png)

![](http://cdn.hurra.ltd/img/收款码.png)
