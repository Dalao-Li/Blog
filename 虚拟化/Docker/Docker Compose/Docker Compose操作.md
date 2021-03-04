<!--
 * @Description: 
 * @Version: 
 * @Autor: Li Yuanhao
 * @Email: dalao_li@163.com
 * @QQ: 1061299112
 * @Date: 2021-01-24 18:40:12
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-26 00:18:34
-->

# Docker Compose


## 概述

前面我们使用 Docker 的时候,定义 Dockerfile 文件,然后使用 docker build、docker run 等命令操作容器.然而微服务架构的应用系统一般包含若干个微服务,每个微服务一般都会部署多个实例,如果每个微服务都要手动启停,那么效率之低,维护量之大可想而知

使用 Docker Compose 可以轻松、高效的管理容器,它是一个用于定义和运行多容器 Docker 的应用程序工具

## 例1

启动一个 MySQL 容器,再启动一个 Ubuntu 容器,完成在 Ubuntu 容器内访问 MySQL 容器内的服务

建立目录 demo,建立 Dockerfile 文件

```docker
FROM ubuntu

RUN apt-get update && apt-get install -y mysql-client
```

建立 docker-compose.yml 文件

```yml
version:'3'

services:

    db:
        images:"mysql:5.6"
        container_name:db_app
        environment:
            MYSQL_ROOT_PASSWORD:123
    app:
        build: .
        container_name:ubuntu_app
        links:
            -db
```

## 例 2

建立一个能够记录页面访问次数的 web 网站

- web 应用  

新建文件夹,在该目录中编写 app.py 文件

```py
from flask import Flask
from redis import Redis

app = Flask(__name__)
redis = Redis(host='redis', port=6379)

@app.route('/')
def hello():
    # 次数加1
    count = redis.incr('hits')
    return 'Hello World! 该页面已被访问 %d 次\n'%(count)

if __name__ == "__main__":
    app.run(host="0.0.0.0", debug=True)
```

- Dockerfile

编写 Dockerfile 文件,内容为

```dockerfile
FROM python:3.6-alpine
ADD . /code
WORKDIR /code
RUN pip install redis flask
CMD ["python", "app.py"]
```

- docker-compose.yml

编写 docker-compose.yml 文件,这个是 Compose 使用的主模板文件

```yml
version: "3"

services:

  web:
    build: .
    ports:
      - "5000:5000"
  redis:
    image: "redis:alpine"
```

![](https://cdn.hurra.ltd/img/20210125130118.png)

- 运行 compose 项目

```docker
docker-compose up -d
```

![](https://cdn.hurra.ltd/img/20210125130250.png)

![](https://cdn.hurra.ltd/img/20210125130344.png)

![](https://cdn.hurra.ltd/img/20210125130458.png)
