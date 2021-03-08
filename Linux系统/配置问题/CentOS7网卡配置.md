<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-07 23:27:49
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-03-08 09:37:44
-->

## 文件位置

>/etc/sysconfig/network-scripts

此处以ifcfg-eth0配置文件为例
```ini  
TYPE="Ethernet"
PROXY_METHOD="none"
BROWSER_ONLY="no"
BOOTPROTO="static"
DEFROUTE="yes"
IPV4_FAILURE_FATAL="no"
IPV6INIT="yes"
IPV6_AUTOCONF="yes"
IPV6_DEFROUTE="yes"
IPV6_FAILURE_FATAL="no"
IPV6_ADDR_GEN_MODE="stable-privacy"
NAME="eth0"
UUID="f1a9eae1-1ec0-4ef5-823a-7d9e9b804194"
DEVICE="eth0"
ONBOOT="yes"
IPADDR=192.168.137.2
GATEWAY=192.168.137.1
DNS1=192.168.137.1
NETMASK=255.255.255.0
```

## TYPE="Ethernet"

网卡类型,一般是Ethernet,还有其他的如bond,bridge


## BOOTPROTO="dhcp"

获取IP地址的方式,启动的协议,获取配置的方式
| 参数        | 含义         |
| ----------- | ------------ |
| dhcp        | 动态获取     |
| static/none | 静态手工配置 |

## DEFROUTE="yes"

是否设置默认路由.若为yes则可以在该文件通过IPADDR和PREFIX两个参数来设置网关

## IP地址相关配置

```ini
IPV4_FAILURE_FATAL="no"

IPV6INIT="yes"

IPV6_AUTOCONF="yes"

IPV6_DEFROUTE="yes"

IPV6_FAILURE_FATAL="no"

IPV6_ADDR_GEN_MODE="stable-privacy"
```

## NAME="eth0"


| 参数      | 含义         |
| --------- | ------------ |
| eth<参数> | 真实物理网卡 |
| ens<参数> | 虚拟网络会话 |

真实物理网卡上可以绑定多个虚拟网络会话

## UUID="......"

通用唯一识别码,若vmware克隆的虚拟机无法启动网卡可以去除此项

## DEVICE=eth0

系统逻辑设备名

## ONBOOT="yes"

开机启动时是否激活网卡设备

## IPADDR

设置网卡对应的IP地址,网络服务启动,网卡激活后会自动将该地址配置到网卡上

## GATEWAY=......

该网卡配置的IP对应的网关(默认路由);若主机是多网卡设备,该参数只能在一个网卡的配置文件里面出现,也就是说一台机只有一个默认路由

## DNS1=......

主DNS,若这里设置了值,则会优先于/etc/resolv.conf中设置的DNS服务器的地址

## NETMASK=......

子网掩码