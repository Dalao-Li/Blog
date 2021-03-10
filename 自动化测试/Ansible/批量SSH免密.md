<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-10 09:33:44
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-03-10 10:08:53
-->



通过ansible批量给多台远程主机设置SSH免密

| 主机       | IP             |
| ---------- | -------------- |
| 宿主机     | 192.168.43.231 |
| 远程主机_1 | 172.17.0.2     |
| 远程主机_2 | 172.17.0.3     |
| 远程主机_3 | 172.17.0.4     |

修改宿主机/etc/ansible/host文件

```ini
[test]
172.17.0.2

172.17.0.3

172.17.0.4

[test:vars]
ansible_ssh_user="root"

ansible_ssh_pass="[密码]"
```

修改宿主机/etc/ansible/ansible.cfg文件

```ini
[defaults]

hostfile = hosts
remote_user = root
host_key_checking = True
```

将宿主机的id_ras.pub文件发送到远程主机的authorized_key中

```sh
ansible all -m authorized_key -a "user=root key='{{ lookup('file','/root/.ssh/id_rsa.pub') }}'" -k
```

输入宿主机的SSH密码

![](https://cdn.hurra.ltd/img/20210310100805.png)

尝试控制所有主机

![](https://cdn.hurra.ltd/img/20210310100850.png)