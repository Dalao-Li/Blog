# 问题

前端使用 XMLHttpRequest 发送 GET 请求时,后端 Flask 框架已经接收到了请求,但前端无法显示返回值

前端代码

```html
<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8" />
    <script>
      function loadXMLDoc() {
        var xmlhttp;
        if (window.XMLHttpRequest) {
          //  IE7+, Firefox, Chrome, Opera, Safari 浏览器执行代码
          xmlhttp = new XMLHttpRequest();
        } else {
          // IE6, IE5 浏览器执行代码
          xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
        }
        xmlhttp.onreadystatechange = function () {
          if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
            var v = xmlhttp.responseText;
            console.log(v);
            alert(v);
          }
        };
        xmlhttp.open("GET", "http://127.0.0.1:5000/", true);
        xmlhttp.send();
      }
    </script>
  </head>

  <body>
    <button type="button" onclick="loadXMLDoc()">获取内容</button>
  </body>
</html>
```

后端代码

```py
from flask import Flask

app = Flask(__name__)


@app.route('/', methods=['GET', 'POST'])
def hello_world():
    return 'HELLO'


if __name__ == '__main__':
    app.run()

```

# 分析

使用 F12 进入控制台后发现如下错误

![](http://cdn.hurra.ltd/img/20200722234713.png)

通过查询此为跨域问题,所以需设置 Flask 允许跨域

# 解决

Flask 配 Cors 跨域,使用 flask-cors 包,并有两种方式

| 方式                 | 范围              | 特点                      |
| -------------------- | ----------------- | ------------------------- |
| @cross_origin 装饰器 | 单个路由          | 适用于配置特定的 API 接口 |
| CORS 函数            | 配置全局 API 接口 | 适用于全局的 API 接口配置 |

```shell
pip install flask-cors

```

将后端代码修改为:

```py
from flask import Flask
from flask_cors import cross_origin

app = Flask(__name__)


@app.route('/', methods=['GET', 'POST'])
@cross_origin()
def hello_world():
    return 'HELLO'


if __name__ == '__main__':
    app.run()

```

运行结果
![](http://cdn.hurra.ltd/img/20200722235455.png)

![](http://cdn.hurra.ltd/img/20200722235514.png)

![](http://cdn.hurra.ltd/img/收款码.png)
