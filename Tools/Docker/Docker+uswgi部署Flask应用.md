# 环境

> - 运行环境 : CentOS7
> - Python : Python3.7
> - Docker: Docker 19.03.12
> - 内网 IP : 192.168.3.20

#  Flask 应用

目录 demo,新建 app.py 文件

```py
from flask import Flask

app = Flask(__name__)

@app.route('/')
def hello():
    return 'Docker deploy Flask'

if __name__ == '__main__':
	app.run()
```

# uwsgi 配置文件

新建 config.ini 文件:

```ini
[uwsgi]
# 启动主进程,来管理其他进程
master = true

# 地址和端口号
http = :8000

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

# Dockerfile

```docker
# 所采用的基础镜像
FROM python:3.7

# 为镜像添加标签
LABEL version="v1" description="Docker deploy Flask" by="Dalao"

# 配置工作目录
WORKDIR /usr/flask/app

# 在镜像容器中执行命令
RUN pip install Flask uwsgi -i https://pypi.tuna.tsinghua.edu.cn/simple/

# 将主机中目录内容拷贝到镜像目录下
COPY . .

# 容器启动时执行指令,每个Dockerfile只能有一条CMD命令
CMD ["uwsgi","config.ini"]
```

# 构建镜像

进入 demo 目录,执行:

```shell
docker build -t mydemo .
```

> - -t : 指定镜像名称,此处为 mydemo
> - `.` 指定创建时的目录

![](http://cdn.hurra.ltd/img/20200712113859.png)

# 建立容器

```shell
docker run -itd -p 80:8080 --name test mydemo
```

访问http://192.168.3.20

![](http://cdn.hurra.ltd/img/20200712114018.png)

# 总结

- Flask 应用的部署方式通常采用 gunicorn 或 uwsgi 两种方式

-  `目前 windows平台 尚不支持 uwsgi 包的使用`

![](http://cdn.hurra.ltd/img/收款码.png)
