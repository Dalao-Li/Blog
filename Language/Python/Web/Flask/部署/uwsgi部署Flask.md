<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:35
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-02 21:55:41
-->

# Flask文件

建立app.py文件
```py
from flask import Flask
app = Flask(__name__)

@app.route('/')
def hello():
    return 'hello world ! '

if __name__ == '__main__':
	app.run()
```

运行

```py
python app.py
```

![](https://cdn.hurra.ltd/img/20200711112554.png)
![](https://cdn.hurra.ltd/img/20200711112626.png)

# uswgi.ini文件

安装uwsgi
```py
pip install uwsgi
```

![](https://cdn.hurra.ltd/img/20200711123350.png)

新建 test.py文件:

```py
def application(env, start_response):
    start_response('200 OK', [('Content-Type','text/html')])
    return [b"Hello World"]
```

运行

```py
uwsgi --http :8080 --plugin python --wsgi-file test.py
```

> - --plugin python 是告诉 uWSGI 在使用 python 插件

访问http://127.0.0.1:8080

![](https://cdn.hurra.ltd/img/20200711123744.png)
![](https://cdn.hurra.ltd/img/20200711123908.png)

# uwsgi部署Flask

新建 config.ini文件:

```ini
[uwsgi]
# 启动主进程,来管理其他进程
master = true

# 地址和端口号
http = :8001

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

启动

```shell
uwsgi config.ini
```

![](https://cdn.hurra.ltd/img/20200711130654.png)
![](https://cdn.hurra.ltd/img/20200711135506.png)

---

![](https://cdn.hurra.ltd/img/收款码.png)
