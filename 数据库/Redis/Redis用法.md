<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-24 15:25:28
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-03-09 14:06:03
-->
# Readis操作


## 基础操作

- 建立键

```shell
SET key redis
```

- 删除键

```shell
DEL key
```

- 检查给定 key 是否存在

```shell
EXISTS key
```

- 为给定 key 设置过期时间,以秒计

```shell
EXPIRE key seconds
```

- 以秒为单位,返回给定 key 的剩余生存时间

```shell
TTL key
```

## 安全操作

- 设置密码

```shell
CONFIG set requirepass "pwd"
```

- 查看密码

```shell
CONFIG get requirepass
```

