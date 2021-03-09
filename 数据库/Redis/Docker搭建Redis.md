<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-04 23:46:06
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-03-09 14:05:43
-->

# Docker建立Redis 

## 建立

Docker 拉取 Redis 镜像 

```sh
docker run -itd --name redis-test -p 6379:6379 redis
```

连接

```sh
docker exec -it redis-test /bin/bash

redis-cli
```

## Docker部署允许远程访问


建立redis.conf

```c
//关闭保护模式
protected-mode no  

//密码
requirepass 123456   
```

建立容器时挂载
```sh
docker run -itd \
    -p 6379:6379 \
    -v $PWD/redis.conf:/etc/redis/redis.conf \
    --name redis-server \
    redis 
```