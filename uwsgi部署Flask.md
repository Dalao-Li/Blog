# 一、实验配置

> - 实验环境 : Ubunttu20.04
> - Python版本 : Python3.7

# 二、实验过程

## 2.1 建立Python虚拟环境
创建demo文件夹并进入
```shell
mkdir demo

cd demo
```

查看Python解释器位置
```shell
whereis python
```
![](http://cdn.hurra.ltd/img/20200711111013.png)
<center>博主此处的位置为/usr/bin/python3.8</center>

建立名为venv的虚拟环境
```shell
virtualenv -p /usr/bin/python3.8  venv
```
![](http://cdn.hurra.ltd/img/20200711111529.png)

激活虚拟环境
```shell
source venv/bin/activate
```
![](http://cdn.hurra.ltd/img/20200711111712.png)

结束后退出虚拟环境
```shell
deactivate
```
## 2.2 安装Flask

```
pip install Flask
```
![](http://cdn.hurra.ltd/img/20200711112400.png)

新建app.py文件
```py
from flask import Flask
app = Flask(__name__)
@app.route('/')
def hello():
    return 'hello world ! '
    
if __name__ == '__main__':
	app.run()
```
运行app.py文件,访问http://127.0.0.1:5000
```py
python app.py
```
![](http://cdn.hurra.ltd/img/20200711112554.png)
![](http://cdn.hurra.ltd/img/20200711112626.png)

## 2.3 安装uswgi
```
pip install uwsgi
```
![](http://cdn.hurra.ltd/img/20200711123350.png)

新建test.py文件,写入
```py
def application(env, start_response):
    start_response('200 OK', [('Content-Type','text/html')])
    return [b"Hello World"]
```
运行以下命令,并访问http://127.0.0.1:8000
```py
uwsgi --http :8080 --plugin python --wsgi-file test.py
```
> - --plugin python是告诉uWSGI在使用python插件  

![](http://cdn.hurra.ltd/img/20200711123744.png)
![](http://cdn.hurra.ltd/img/20200711123908.png)

## 2.4 使用uwsgi部署Flask
新建config.ini文件,并写入以下内容
```ini
[uwsgi]
# 启动主进程，来管理其他进程
master = true
# 地址和端口号
http = :8001 
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
启动
```shell
uwsgi config.ini

```
![](http://cdn.hurra.ltd/img/20200711130654.png)
![](http://cdn.hurra.ltd/img/20200711135506.png)


![](http://cdn.hurra.ltd/img/赞赏码.png)
