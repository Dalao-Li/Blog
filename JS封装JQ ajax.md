## 使用原生JS函数封装JQ的ajax方法
>参数说明
> - type : 请求方式
> - url : 发送的位置
> - parm : 发送的数据
> - callback : 回调函数

```javascript
//发送ajax请求
function send_ajax(type,url,param, callback) {
    $.ajax({
        async: false,
        ache: false,
        type: type,
        url: url,
        data: JSON.stringify(param),
        dataType: "text",
        success: function (data) {
            //获取返回值
            var value = $.parseJSON(data).result
            //回调函数
            callback(value)
        },
        error: function () {
            alert("网络异常，请稍后重试")
        }
    });
}
```
---
## 实例：用户登录函数user_login()

### 1. 登录的回调函数
```javascript
function login_callback(value) {
    switch (value) {
        case 1:
            alert("登录成功");
            window.location.href = 'index.html'
            break;
        case 0:
            alert("密码错误");
            $("#pass").val("")
            break;
        case -1 :
            alert("该账号不存在")
            $("#name").val("")
            break;
    }
}
```

### 2. 登录函数
```javascript
function user_login(name, pwd) {
    if (name === "") {
        alert("请输入用户名");
        return
    }
    if (pwd === "") {
        alert("请输入密码");
        return
    }
    var data = {
        "status": 1,
        "name": name,
        "pwd": pwd
    }
    //发送ajax请求
    send_ajax('POST','/api', data, login_callback)
}