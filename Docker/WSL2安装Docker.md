
## 更新 Win10 到2004版本


## 启用Linux子系统

打开 控制面板 -> 程序 -> 启用或关闭Windows功能。找到"适用于Linux的Windows子系统"和"虚拟机平台",勾选这两项,并重新启动计算机。

## 切换到WSL2

使用管理员用户打开CMD，运行:

```shell
wsl --set-default-version 2
```

## 添加Docker源

```shell
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -

sudo add-apt-repository \
   "deb [arch=amd64] https://mirrors.tuna.tsinghua.edu.cn/docker-ce/linux/ubuntu \
   $(lsb_release -cs) \
   stable"

sudo apt update
```

## 安装Docker
```shell
sudo apt install -y docker-ce
```

## 启动Docker daemon
```shell
sudo service docker start
```

## 权限
使用docker info 命令出现问题

![](http://cdn.hurra.ltd/img/20200721210505.png)

这是权限不足的原因,可使用以下命令解决



```shell
# 添加docker用户组
sudo groupadd docker

# 将登陆用户加入到docker用户组中
sudo gpasswd -a $USER docker   

# 更新用户组
newgrp docker     
```

现在就没问题了

![](http://cdn.hurra.ltd/img/20200721210744.png)


## 关闭虚拟机

![](http://cdn.hurra.ltd/img/20200721211633.png)

该进程是虚拟机的进程。它比较占内存。不使用WSL2的时候我们可以关闭它以节省内存。关闭WSL2 Linux的方法如下。使用管理员打开CMD，运行：

```shell
wsl --shutdown
```

![](http://cdn.hurra.ltd/img/赞赏码.png)
