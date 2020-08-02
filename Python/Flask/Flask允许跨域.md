# 问题

前端使用XMLHttpRequest发送GET请求时,后端Flask框架已经接收到了请求,但前端无法显示返回值

前端代码
```html
<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
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
                    var v = xmlhttp.responseText
                    console.log(v)
                    alert(v)
                }
            }
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

使用F12进入控制台后发现如下错误

![](http://cdn.hurra.ltd/img/20200722234713.png)

通过查询此为跨域问题,所以需设置Flask允许跨域


# 解决
Flask配Cors跨域,使用flask-cors包,并有两种方式

|  方式   | 范围   | 特点|
|  ----  | ----   |----|
| @cross_origin装饰器  | 单个路由 |适用于配置特定的API接口|
| CORS函数  | 配置全局API接口 |适用于全局的API接口配置|

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

![](http://cdn.hurra.ltd/img/赞赏码.png)
