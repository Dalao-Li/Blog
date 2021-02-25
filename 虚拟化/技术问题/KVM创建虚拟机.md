<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-07 19:32:11
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-24 22:04:59
-->
## 准备工作

检查宿主机处理器是否支持虚拟化

```sh
egrep -o 'vmx | svm' /proc/cpuinfo | wc -l
```
![](https://cdn.hurra.ltd/img/20210207193309.png)

如果显示数值是 0，则表示该 CPU 不支持虚拟化

关闭 iptables

```sh
service iptables stop

chkconfig iptables off
```

关闭selinux
```sh
setenforce 0
```

编辑 /etc/selinux/config,对应内容改为
```sh
SELINUX=disabled
```
