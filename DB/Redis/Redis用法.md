<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-24 15:25:28
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-01-28 22:15:39
-->
# 连接

- Docker 拉取 Redis 镜像

```
docker run -itd --name redis-test -p 6379:6379 redis

docker exec -it redis-test /bin/bash
```

连接

```
redis-cli
```

# 基础操作

- 建立键

```
SET key redis
```

- 删除键

```
DEL key
```

- 检查给定 key 是否存在

```
EXISTS key
```

- 为给定 key 设置过期时间,以秒计

```
EXPIRE key seconds
```

- 以秒为单位,返回给定 key 的剩余生存时间

```
TTL key
```

# 安全操作

- 设置密码

```
CONFIG set requirepass "pwd"
```

- 查看密码

```
CONFIG get requirepass
```

# Docker部署允许远程访问


建立redis.conf

```s
protected-mode no  //关闭保护模式

requirepass 123456   //密码
```

```s
docker run -itd -p 6379:6379 -v $PWD/redis.conf:/etc/redis/redis.conf --privileged=true --name redis redis redis-server /etc/redis/redis.conf
```