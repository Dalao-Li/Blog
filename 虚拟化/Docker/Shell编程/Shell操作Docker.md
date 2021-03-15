<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-15 10:21:24
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-03-15 11:18:49
-->


## 获取单个容器ID

- 方法1:

```sh
con_id=$(docker ps| grep "[容器名]" |awk '{print $1}')
```

![](https://cdn.hurra.ltd/img/20210315102522.png)

- 方法2:

```sh
con_id=$(docker ps -aqf "name=[容器名]")
```
![](https://cdn.hurra.ltd/img/20210315103108.png)

| 参数 | 说明                              |
| ---- | --------------------------------- |
| a    | 所有人,即使容器没运行也能正常工作 |
| q    | 仅输出容器ID                      |
| f    | filter                            |


## 获取所有容器