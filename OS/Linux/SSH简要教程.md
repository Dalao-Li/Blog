# 目的

> - 设置**密码**通过 SSH 登录
>
> - 设置**密钥**通过 SSH 登录

# 环境

> - 客户端 : Windows
> - 服务端 : Ubuntu16.04
> - SSH 工具 : Xshell;Xftp

# 密码登录

首先直接登录 Linux 主机进行配置

## 配置文件

```shell
vim /etc/ssh/sshd_config
```

![](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLzIwMjAwNTE4MDkyNjU0LnBuZw?x-oss-process=image/format,png)
![](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLzIwMjAwNTE4MDkyOTI1LnBuZw?x-oss-process=image/format,png)

```shell
编辑完成后按Esc键,输入 wq! 敲回车,保存退出
```

## 添加密码

由于此处使用的是 docker 容器,所以默认是 root 用户,得给它设个密码

```shell
passwd
```

![](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLzIwMjAwNTE4MDkzMjIxLnBuZw?x-oss-process=image/format,png)
或者可以新建一个用户

```shell
useradd -m 用户名
```

设置密码

```shell
passwd 用户名
```

## 重启服务

```shell
service ssh restart
```

![](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLzIwMjAwNTE4MDkzMzA3LnBuZw?x-oss-process=image/format,png)

## 测试

使用 ssh 工具进行连接

```shell
ssh (-p 端口) <用户名>@<ip地址>
```

输入对应用户的密码,连接即可

![](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLzIwMjAwNTE4MDkzNzUwLnBuZw?x-oss-process=image/format,png)

> - -p 指定端口连接；容器的 22 端口映射到了宿主机的 2222 端口,所以此处的 ssh 应指定端口
> - root 即连接的用户名
> - ip 地址,连接的地址,此处指宿主机地址

例 : 连接默认 22 端口,用户为 dalao,IP 地址为 192.168.0.104 的子系统

![](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLzIwMjAwNTE4MDk0MjEzLnBuZw?x-oss-process=image/format,png)

如果出现提示输入 yes 就行

---

# 密钥登录

## 制作密钥对

```shell
ssh-keygen
```

![](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLzIwMjAwNTE4MDk0OTQzLnBuZw?x-oss-process=image/format,png)
成功生成了公钥和私钥,其保存地址为

```shell
公钥 : /root/.ssh/id_rsa.pub

私钥 : /root/.ssh/id_rsa
```

## 安装公钥

在服务端安装公钥并完成授权

```shell
cd .ssh

cat id_rsa.pub >> authorized_keys

chmod 600 authorized_keys

chmod 700 ~/.ssh
```

## 配置文件

```shell
vim /etc/ssh/sshd_config

将RSAAuthentication与RSAAuthentication修改为yes

将PasswordAuthentication修改为no,以禁用密码登录
```

![](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLzIwMjAwNTE4MDk1NTMzLnBuZw?x-oss-process=image/format,png)
重启 ssh 服务

```shell
service ssh restart
```

## 下载私钥

将 5.1 生成的私钥文件 id_rsa 下载到客户端
![](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLzIwMjAwNTE4MTAwMDUwLnBuZw?x-oss-process=image/format,png)

在建立 ssh 连接时使用该私钥

![](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLzIwMjAwNTE4MTAwNTA2LnBuZw?x-oss-process=image/format,png)

选择刚才生成的私钥,点击连接

![](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLzIwMjAwNTE4MTAwNTU3LnBuZw?x-oss-process=image/format,png)

![](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLzIwMjAwNTE4MTAwNjM3LnBuZw?x-oss-process=image/format,png)

输入登录的用户名
![](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLzIwMjAwNTE4MTAwNzA5LnBuZw?x-oss-process=image/format,png)

<center>登录成功</center>

![](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLyVFOCVCNSU5RSVFOCVCNSU4RiVFNyVBMCU4MS5wbmc?x-oss-process=image/format,png)
