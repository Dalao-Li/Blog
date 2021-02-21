<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-28 22:24:28
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-05 11:15:48
-->
# 删除所有容器

```docker
docker rm $(docker ps -aq)
```

# 停用并删除容器

```docker
docker stop $(docker ps -q) & docker rm $(docker ps -aq)
```