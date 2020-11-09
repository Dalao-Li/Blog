## 目录

- [目录](#目录)
- [环境](#环境)
- [1.1 拉取 PHP 镜像](#11-拉取php镜像)
- [1.2 拉取 Nginx 镜像](#12-拉取nginx镜像)
- [1.3 文件夹映射](#13-文件夹映射)
- [1.4 实例化容器](#14-实例化容器)

## 环境

> - 系统 : CentOS7
> - Docker 版本 : 18.03.1.ce

## 1.1 拉取 PHP 镜像

```s
docker pull php:7.1.30-fpm
```

## 1.2 拉取 Nginx 镜像

```
docker pull nginx
```

## 1.3 文件夹映射

新建文件夹，用来映射网站根目录、Nginx 配置文件与日志文件

```s
mkdir -p ~/nginx/www ~/nginx/logs ~/nginx/conf
```

进入/nginx/www,新建 index.php,内容为

```php
<?php
   phpinfo();
?>
```

进入/nginx/conf,新建 test-php.conf

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

## 1.4 实例化容器

PHP 容器

```s
docker run -itd --name demo_php -v ~/nginx/www:/www php:7.1.30-fpm
```

Nginx 容器

```s
docker run -itd -p 80:80 -v ~/nginx/www:/usr/share/nginx/html -v ~/nginx/conf:/etc/nginx/conf.d --link demo_php:php nginx
```

![](http://cdn.hurra.ltd/img/20200710113713.png)

访问本机 IP 地址

![](http://cdn.hurra.ltd/img/20200710113759.png)

---

![](http://cdn.hurra.ltd/img/收款码.png)
