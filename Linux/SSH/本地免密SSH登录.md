<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-09 17:54:44
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-03-10 09:19:11
-->

## 生成.ssh目录

```sh
ssh-keygen -t rsa
```

之后会在更目录下生成 .ssh目录,包含的文件如下表

| 文件            | 作用                       |
| --------------- | -------------------------- |
| authorized_keys | 存放多台机器免密登录的公钥 |
| id_rsa          | 生成的私钥文件             |
| id_rsa.pub      | 生成的公钥文件             |
| know_hosts      | 已知的主机公钥清单         |

ssh公钥生效需满足至少下面两个条件:

- .ssh目录的权限必须是700

- .ssh/authorized_keys文件权限必须是600

## 免密登录

| 主机     | IP             |
| -------- | -------------- |
| 本地主机 | 192.168.43.96  |
| 远程主机 | 192.168.43.208 |

在本地主机上生成.ssh目录及其文件,并将其中id_isa.pub内容拷贝到远程主机的./ssh/authorized_keys中

```sh
ssh-copy-id -i ~/.ssh/id_rsa.pub <远程主机IP>
```

![](https://cdn.hurra.ltd/img/20210310091446.png)

查看远程主机上的authorized_keys文件

![](https://cdn.hurra.ltd/img/20210310091640.png)

可以看到本地主机的公钥已经被拷贝到了远程主机的authorized_keys文件中

尝试SSH登录远程主机

![](https://cdn.hurra.ltd/img/20210310091854.png)

此时便可免密登录