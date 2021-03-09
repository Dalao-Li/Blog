<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:34
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-03-08 17:26:56
-->
## 环境

> 宿主机环境 : WSL2 Ubuntu18.04  
> 基础容器 : CentOS7

下载 arm-linux-gcc.tar  

[地址](http://112.124.9.243/arm9net/mini2440/linux/arm-linux-gcc-4.4.3-20100728.tar.gz)

将 tar 包复制到新建的 CentOS7 容器

![](https://cdn.hurra.ltd/img/20200919202648.png)

解包到/home 路径

> tar -zxvf [包名] -C [路径]

```sh
tar -zxvf arm-linux-gcc-4.4.3-20100728.tar.gz -C /home
```

![](https://cdn.hurra.ltd/img/20200919202951.png)

移动包中内容

> cp -r [源路径] [目标路径]

```sh
cp -r /home/opt/FriendlyARM/toolschain/4.4.3 /usr/local/bin
```

![](https://cdn.hurra.ltd/img/20200919203033.png)

安装相关依赖

```sh
yum install -y epel-release glibc.i686
```

配置环境变量,编辑/etc/profile,末尾添加

```sh
export PATH=$PATH:/usr/local/arm/bin

source /etc/profile
```

![](https://cdn.hurra.ltd/img/20200919205735.png)

编辑 ~/.bashrc,末尾添加

```sh
if [ -f /etc/profile ]; then
. /etc/profile
fi
```

刷新环境变量

```sh
source /etc/profile
```

查看 arm-linux-gcc 版本

```sh
arm-linux-gcc -v
```

![](https://cdn.hurra.ltd/img/20200919210020.png)

![](https://cdn.hurra.ltd/img/收款码.png)
