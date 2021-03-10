<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-10 09:33:44
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-03-10 13:14:41
-->



通过ansible批量给多台远程主机设置SSH免密

| 主机       | IP             | 远程登录用户 |
| ---------- | -------------- | ------------ |
| 宿主机     | 192.168.43.231 |              |
| 远程主机_1 | 172.17.0.2     | docker       |
| 远程主机_2 | 172.17.0.3     | docker       |
| 远程主机_3 | 172.17.0.4     | docker       |


- 修改宿主机/etc/ansible/host

```ini
[test]
172.17.0.2

172.17.0.3

172.17.0.4

[test:vars]
ansible_ssh_user="[远程主机用户名]"

ansible_ssh_pass="[远程主机密码]"
```

![](https://cdn.hurra.ltd/img/20210310120137.png)

- 修改宿主机/etc/ansible/ansible.cfg

```ini
[defaults]

hostfile = hosts

# 远程主机用户名
remote_user = docker
host_key_checking = True
```

![](https://cdn.hurra.ltd/img/20210310120159.png)

将宿主机的id_ras.pub文件发送到远程主机的authorized_key中,注意此处远程登录的用户名为docker,而本地为root用户

```sh
ansible all -m authorized_key -a "user=[远程用户名] key='{{ lookup('file','[本地id_rsa.pub路径]') }}'" -k
```

输入宿主机的SSH密码

![](https://cdn.hurra.ltd/img/20210310115926.png)

尝试控制所有远程主机

![](https://cdn.hurra.ltd/img/20210310100850.png)