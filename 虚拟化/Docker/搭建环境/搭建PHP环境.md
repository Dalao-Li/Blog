<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:34
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-22 22:51:10
-->
# Docker搭建PHP


## 拉取镜像

拉取 PHP 镜像,Nginx 镜像

```docker
docker pull php:7.1.30-fpm

docker pull nginx
```

## 文件夹映射

新建文件夹,用来映射网站根目录、Nginx 配置文件与日志文件

```docker
mkdir -p ~/nginx/www ~/nginx/logs ~/nginx/conf
```

进入/nginx/www,新建 index.php,内容为

```php
<?php
   phpinfo();
?>
```

进入/nginx/conf,新建 test-php.conf

```docker
server {
    listen  80;
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

## 实例化容器

PHP 容器

```docker
docker run -itd --name demo_php -v ~/nginx/www:/www php:7.1.30-fpm
```

Nginx 容器

```docker
docker run -itd -p 80:80 -v ~/nginx/www:/usr/share/nginx/html -v ~/nginx/conf:/etc/nginx/conf.d --link demo_php:php nginx
```

![](https://cdn.hurra.ltd/img/20200710113713.png)

访问本机 IP 地址

![](https://cdn.hurra.ltd/img/20200710113759.png)


![](https://cdn.hurra.ltd/img/收款码.png)
