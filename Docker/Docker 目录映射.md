- docker 删除所有容器

```shell
docker rm $(docker ps -aq)
```

- 停用并删除容器

```shell
docker stop $(docker ps -q) & docker rm $(docker ps -aq)
```

# 目录挂载

- 容器目录不可以为相对路径

> 绝对路径，必须以下斜线“/”开头

将宿主机 python 目录下的 myapp 目录映射到容器内的/usr/src/myapp 目录

![](http://cdn.hurra.ltd/img/20210109220453.png)

- 宿主机目录如果不存在，则会自动生成

将宿主机 demo 目录(不存在) 映射到容器内/demo 目录

![](http://cdn.hurra.ltd/img/20210109223115.png)

# 内容修改
