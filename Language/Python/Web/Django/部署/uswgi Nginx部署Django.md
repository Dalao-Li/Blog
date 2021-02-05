<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-03 13:54:04
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-03 21:59:31
-->

# uswgi部署Django


## Django

- 建立项目mysite

```shell
django-admin.py startproject mysite
```

- 运行
```shell
python manage.py runserver 0.0.0.0:8000
```
![](https://cdn.hurra.ltd/img/20210203191544.png)

![](https://cdn.hurra.ltd/img/20210203191643.png)

## uwsgi文件

- 建立文件config.ini
  
```ini
[uwsgi]

socket = 127.0.0.1:9090
# 启动主进程,来管理其他进程
master = true

# 开启的进程数量
processes = 2

# 运行线程
threads = 8

# 设置用于uwsgi包解析的内部缓存区大小为64k.默认是4k
buffer-size = 32768
```

## nginx配置
```js
# 新增
server {
    listen 80;
    server_name localhost;
    location / {
        include  uwsgi_params;
        //必须和 uwsgi中的设置一致
        uwsgi_pass  127.0.0.1:9090;              
        //入口文件，即wsgi.py相对于项目根目录的位置，“.”相当于一层目录
        uwsgi_param UWSGI_SCRIPT /mysite/mysite.wsgi;  
        //项目根目录
        uwsgi_param UWSGI_CHDIR /mysite;       
        index  index.html index.htm;
        client_max_body_size 35m;
    }
}
```