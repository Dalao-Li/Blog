<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-07 12:48:53
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-07 12:56:03
-->
## 问题

在Vmware中创建虚拟机的时候,VVmware提示:VMware Workstation和Hyper-V不兼容.请先从系统中移除Hyper-V角色,然后再运行VMware Workstation

## 原因

两者都是基于 CPU 等底层硬件的 Hypervisor 机制来实现的,而他们必须独占管理 Hypervisor,因此不能在一台电脑中同时运行

## 解决方案

- 关闭Hyper-v
```sh
bcdedit /set hypervisorlaunchtype off
```

- 开启Hyper-v
```sh
bcdedit /set hypervisorlaunchtype auto
```

