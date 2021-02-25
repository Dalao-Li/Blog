<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-07 14:02:02
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-24 22:04:32
-->

> 请确保虚拟机为关闭状态

- 打开命令行,输入
```sh
Get-VM
```
![](https://cdn.hurra.ltd/img/20210207140309.png)

此处虚拟机名为CentOS7
  
输入 Get-VMProcessor -VMName <虚拟机名> | fl
```sh
Get-VMProcessor -VMName CentOS7 | fl
```
![](https://cdn.hurra.ltd/img/20210207140508.png)

这里显示嵌套虚拟化选项值为False

输入 Set-VMProcessor -ExposeVirtualizationExtensions $true -VMName <虚拟机名>
```
Set-VMProcessor -ExposeVirtualizationExtensions $true -VMName CentOS7
```
正常情况没有输出
![](https://cdn.hurra.ltd/img/20210207140853.png)