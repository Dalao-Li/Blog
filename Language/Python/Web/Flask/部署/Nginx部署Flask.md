<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-02 21:57:06
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-02 23:29:39
-->

# Nginx部署Flask


## Flask
app.py文件
```py
from flask import Flask
app = Flask(__name__)

@app.route('/')
def hello():
    return 'hello world ! '

if __name__ == '__main__':
	app.run()
```

## uwsgi文件
config.ini文件
```ini
[uwsgi]

# socket项
socket = 127.0.0.1:5000

# 启动主进程,来管理其他进程
master = true

# app.py路径
wsgi-file =  app.py

# uwsgi指定的是application,而flask中是app
callable = app

# 开启的进程数量
processes = 2

# 运行线程
threads = 8

# 设置用于uwsgi包解析的内部缓存区大小为64k.默认是4k
buffer-size = 32768
```

## Nginx配置文件

nginx.conf文件
```py
user  nginx;
worker_processes  1;

error_log  /var/log/nginx/error.log warn;
pid        /var/run/nginx.pid;


events {
    worker_connections  1024;
}


http {
    include       /etc/nginx/mime.types;
    default_type  application/octet-stream;

    log_format  main  '$remote_addr - $remote_user [$time_local] "$request" '
                      '$status $body_bytes_sent "$http_referer" '
                      '"$http_user_agent" "$http_x_forwarded_for"';

    access_log  /var/log/nginx/access.log  main;

    sendfile        on;
    #tcp_nopush     on;

    keepalive_timeout  65;

    #gzip  on;

    #include /etc/nginx/conf.d/*.conf;

    # 新增
    server {
        listen 80;
        server_name localhost;
        location / {
            include uwsgi_params;
            uwsgi_pass 127.0.0.1:5000;
        }
    }
}
```


## 运行

```shell
nginx -s reload

service nginx start
```

![](http://cdn.hurra.ltd/img/20210202232938.png)