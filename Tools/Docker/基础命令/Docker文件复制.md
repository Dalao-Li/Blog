<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-02 23:47:07
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-02 23:49:19
-->
## 宿主机->容器
```shell
docker cp <宿主机目录/文件> <容器id>:<容器内目录/文件>
```

## 容器->宿主机
```shell
docker cp <容器id>:<容器内目录/文件> <宿主机目录/文件>
```