
## 相关教程
>[uwsgi部署Flask](https://blog.csdn.net/qq_41452937/article/details/107284032)  
>[gunicorn部署Flask](https://blog.csdn.net/qq_41452937/article/details/104660945)


## 目录
- [环境](#环境)
- [一、目的](#一目的)
- [二、过程](#二过程)
  - [2.1 编写Flask应用](#21-编写flask应用)
  - [2.2 编写uwsgi配置文件](#22-编写uwsgi配置文件)
  - [2.3 编写Dockerfile](#23-编写dockerfile)
  - [2.4 构建容器](#24-构建容器)
  - [2.5 启动镜像](#25-启动镜像)
- [三、总结](#三总结)
  

# 环境

> - 运行环境 : CentOS7
> - Python版本 : Python3.7
> - Docker版本 :  Docker 19.03.12
> - 内网IP : 192.168.3.20

# 一、目的

使用Docker将本地Flask应用打包,并完成部署


# 二、过程

## 2.1 编写Flask应用

新建目录demo,进入;新建app.py文件,内容为
```py
from flask import Flask
app = Flask(__name__)
@app.route('/')
def hello():
    return 'Docker deploy Flask'
    
if __name__ == '__main__':
	app.run()
```
## 2.2 编写uwsgi配置文件
新建config.ini文件,内容为:
```sh
[uwsgi]
# 启动主进程，来管理其他进程
master = true
# 地址和端口号
http = :8000 
# app.py路径
wsgi-file =  app.py  
# uwsgi指定的是application，而flask中是app
callable = app
# 开启的进程数量
processes = 2
# 运行线程
threads = 8
# 设置用于uwsgi包解析的内部缓存区大小为64k。默认是4k
buffer-size = 32768
```

## 2.3 编写Dockerfile

新建Dockerfile,内容为:
```docker
# 所采用的基础镜像
FROM python:3.7

# 为镜像添加标签
LABEL version="v1" description="Docker deploy Flask" by="Dalao"

# 配置工作目录
WORKDIR /usr/src/app

# 在镜像容器中执行命令
RUN pip install Flask && pip install uwsgi -i https://pypi.tuna.tsinghua.edu.cn/simple/

# 将主机中目录内容拷贝到镜像目录下
COPY . .

# 容器启动时执行指令,每个Dockerfile只能有一条CMD命令
CMD ["uwsgi","config.ini"]

```

## 2.4 构建容器

进入demo目录,执行:
```shell
docker build -t mydemo .
```

> - -t : 指定镜像名称,此处为mydemo 
> - `.` 指定创建时的目录

![](http://cdn.hurra.ltd/img/20200712113859.png)

## 2.5 启动镜像
```shell
docker run -itd -p 80:8080 mydemo
```
访问http://192.168.3.20

![](http://cdn.hurra.ltd/img/20200712114018.png)


# 三、总结

1. Flask应用的部署方式有gunicorn与uwsgi两种方式

2. 目前windows尚不支持uwsgi包的使用





![](http://cdn.hurra.ltd/img/赞赏码.png)
