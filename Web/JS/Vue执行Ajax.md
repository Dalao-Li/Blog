## 目录

- [环境](#环境)
- [GET 请求](#get请求)
- [POST 请求](#post请求)

# 环境

> - 系统 : Windows10 2004
> - Web 框架 : Flask
> - Vue 版本 : 2.4.2

# GET 请求

获取后端 JSON 数据并显示

前端

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <title>Title</title>
    <script src="https://cdn.staticfile.org/vue/2.4.2/vue.min.js"></script>
    <script src="https://cdn.staticfile.org/axios/0.18.0/axios.min.js"></script>
  </head>

  <body>
    <div id="app">
      <h1>GET请求获取数据</h1>
      <div v-for="i in info">{{ i.name }},{{i.age}}</div>
    </div>
    <script type="text/javascript">
      new Vue({
        el: "#app",
        data() {
          return {
            info: null,
          };
        },
        mounted() {
          axios
            .get("http://127.0.0.1:5000/getApi")
            .then((response) => (this.info = response.data))
            .catch(function (error) {
              console.log(error);
            });
        },
      });
    </script>
  </body>
</html>
```

数据

```js
data = [
  { name: "LI_LI", age: 18 },
  { name: "WAN_MIN", age: 20 },
  { name: "QIN_XI", age: 20 },
];
```

结果

![](http://cdn.hurra.ltd/img/20200725123717.png)

# POST 请求

```html
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <title>Title</title>
    <script src="https://cdn.staticfile.org/vue/2.4.2/vue.min.js"></script>
    <script src="https://cdn.staticfile.org/axios/0.18.0/axios.min.js"></script>
</head>

<body>

    <div id="app">
        <h1>
            POST请求获取数据
        </h1>
        输入用户名<input type="text" name="name" id="name" v-model="name"></input>
        <br>
        <button @click="submitName">提交</button>
    </div>
    <script type="text/javascript">
        var data = {
            'name': document.getElementById('name').value
        }
        var vm = new Vue({
            el: '#app',
            data() {
                return {
                    name: '',
                    info: ''
                }
            },
            methods: {
                submitName() {
                    axios
                        .post('http://127.0.0.1:5000/postApi', {
                            'name': this.name
                        })
                        .then(function (response) {
                            this.info = response.data
                            alert(JSON.stringify(this.info))
                        })
                        .catch(function (error) {
                            console.log(error)
                        })
                },
            }
        })
    </script>
</body>

</html>
```

后端

```py
@app.route('/postApi', methods=['POST'])
def post_api():
    data = json.loads(request.get_data())
    print(data)
    return json.dumps(data)
```

运行结果
![](http://cdn.hurra.ltd/img/20200725151620.png)

![](http://cdn.hurra.ltd/img/20200725151641.png)

---

![](http://cdn.hurra.ltd/img/收款码.png)
