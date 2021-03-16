<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:35
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-05 16:01:11
-->
## JS 封装 ajax

> - type : 请求方式
> - url : 发送的 url
> - parm : 发送的数据
> - callback : 回调函数

```javascript
//发送ajax请求
function send_ajax(type, url, param, callback) {
  $.ajax({
    async: false,
    ache: false,
    type: type,
    url: url,
    //发送的数据
    data: JSON.stringify(param),
    //服务端返回数据的格式
    dataType: "json",
    success: function (data) {
      callback(data.result);
    },
    error: function () {
      //失败处理
    },
  });
}
```

---

## 实例

### 回调函数

```javascript
function login_callback(value) {
  switch (value) {
    case 1:
      alert("登录成功");
      window.location.href = "index.html";
      break;
    case 0:
      alert("密码错误");
      $("#pass").val("");
      break;
    case -1:
      alert("该账号不存在");
      $("#name").val("");
      break;
  }
}
```

### 登录函数

```javascript
function user_login(name, pwd) {
  if (name === "") {
    alert("请输入用户名");
    return;
  }
  if (pwd === "") {
    alert("请输入密码");
    return;
  }
  var data = {
    status: 1,
    name: name,
    pwd: pwd,
  };
  //发送ajax请求
  send_ajax("POST", "/api", data, login_callback);
}
```
