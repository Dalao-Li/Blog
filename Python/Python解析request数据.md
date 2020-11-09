## 目录

- [一、POST 请求](#一post请求)
  - [1.1 普通 JSON](#11-普通json)
  - [1.2 表格](#12-表格)
  - [1.3 文件](#13-文件)
- [二、GET 请求](#二get请求)
  - [2.1 带参数](#21-带参数)

## 环境

> - Python 版本 : Python 3.7.6
> - IDE : Pycharm
> - 测试工具 : Postman

# 一、POST 请求

## 1.1 普通 JSON

测试 JSON

```js
{
    'name' : 'dalao',
    'pwd' : 'FSDjdskfne23',
    'age' :18
}
```

```py

@app.route('/postApi',methods=['POST'])
def hello_world():
    print(request)

    # 原始数据
    print(request.data)

    # 将数据转换为JSON格式
    print(request.json)

    #将接收的数据转换为JSON格式
    data = json.loads(request.data)
    print(data)

    return {'result':200}
```

![](http://cdn.hurra.ltd/img/20200726230918.png)

![](http://cdn.hurra.ltd/img/20200726231736.png)

---

## 1.2 表格

```py
@app.route('/postApi',methods=['POST'])
def hello_world():
    print(request)

    # 原始数据
    print(request.data)

    print(request.form)

    name = request.form.get('name')
    pwd =  request.form.get('pwd')
    age =  request.form.get('age')
    print('用户名:%s 密码:%s  年龄:%s'%(name,pwd,age))

    return {'result':200}
```

![](http://cdn.hurra.ltd/img/20200726232434.png)

![](http://cdn.hurra.ltd/img/20200726232455.png)

---

## 1.3 文件

```py
@app.route('/postApi', methods=['POST'])
def hello_world():
    print(request)

    print(request.data)

    print(request.form)

    # 获取上传的文件
    f = request.files['file']

    # 获取文件名
    name = f.filename

    print('上传文件的用户名为:%s' % name)

    return {'result': 200}
```

![](http://cdn.hurra.ltd/img/20200726233200.png)

![](http://cdn.hurra.ltd/img/20200726233131.png)

> - `注意 : POST请求无法通过request.args.get(<param>)方法获取数据`

# 二、GET 请求

## 2.1 带参数

```py
@app.route('/getApi/', methods=['GET'])
def hello_world():
    print(request)

    print(request.data)

    print(request.json)

    name = request.args.get('name')
    pwd = request.args.get('pwd')
    age = request.args.get('age')
    print('用户名:%s 密码:%s  年龄:%s' % (name, pwd, age))

    return {'result': 200}
```

![](http://cdn.hurra.ltd/img/20200726234429.png)

![](http://cdn.hurra.ltd/img/20200726234454.png)

---

![](http://cdn.hurra.ltd/img/收款码.png)
