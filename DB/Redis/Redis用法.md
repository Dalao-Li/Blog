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
