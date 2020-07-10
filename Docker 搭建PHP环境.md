# 一、实验目的
使用Docker搭建PHP开发环境

# 二、实验环境
CentOS7

# 三、实验过程

## 3.1 拉取PHP镜像
```s
docker pull php:7.1.30-fpm
```
## 3.2 拉取Nginx镜像
```
docker pull nginx
```
## 3.3 建立文件夹映射

新建文件夹，用来映射网站根目录、Nginx配置文件与日志文件
```s
mkdir -p ~/nginx/www ~/nginx/logs ~/nginx/conf
```
进入/nginx/www,新建index.php,填入以下内容
```php
<?php
   phpinfo();
?>
```
进入/nginx/conf,新建test-php.conf
```s
server {
    listen       80;
    server_name  localhost;

    location / {
        root   /usr/share/nginx/html;
        index  index.html index.htm index.php;
    }

    error_page   500 502 503 504  /50x.html;
    location = /50x.html {
        root   /usr/share/nginx/html;
    }

    location ~ \.php$ {
        fastcgi_pass   php:9000;
        fastcgi_index  index.php;
        fastcgi_param  SCRIPT_FILENAME  /www/$fastcgi_script_name;
        include        fastcgi_params;
    }
}
```

## 3.4 实例化容器
实例化PHP容器
```
docker run -itd --name demo_php -v ~/nginx/www:/www php:7.1.30-fpm
```
实例化Nginx容器

```
docker run -itd -p 80:80 -v ~/nginx/www:/usr/share/nginx/html -v ~/nginx/conf:/etc/nginx/conf.d --link demo_php:php nginx
```
![](http://cdn.hurra.ltd/img/20200710113713.png)

访问本机IP地址

![](http://cdn.hurra.ltd/img/20200710113759.png)


![](http://cdn.hurra.ltd/img/赞赏码.png)
