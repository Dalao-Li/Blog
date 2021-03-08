<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-28 11:28:27
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-01-30 12:28:53
-->

settings.py文件

```s
CACHES = {
    "default": {
        "BACKEND": "django_redis.cache.RedisCache",
        "LOCATION": "redis://101.200.154.83:6379/0",
        "OPTIONS": {
            "CLIENT_CLASS": "django_redis.client.DefaultClient",
            "CONNECTION_POOL_KWARGS": {
                # 最大连接数
                "max_connections": 10,
                # 以字符串的形式写入Redis,为False的话写入字节类型
                "decode_responses": True
            },
            "PASSWORD": "123"
        }
    }
}
```