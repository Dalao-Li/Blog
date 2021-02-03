使用 Jquery 获取 form 中所有控件的值,并封装成 JSON

## html

```html
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <script src="https://cdn.staticfile.org/jquery/1.10.2/jquery.min.js"></script>
  <title>Document</title>
</head>

<body>
  <form method="post" action="" id="form">
    用户名: <input type="text" name="username" /><br />
    密码: <input type="text" name="pwd" /><br />
    <button type="submit" value="" id="submit_demo">提交</button>
  </form>
</body>

<script>
  function get_form_value() {
    var d = {};
    //serializeArray() 方法通过序列化表单值来创建对象(name 和 value)的数组
    var t = $("form").serializeArray();

    //.each() 对 jQuery 对象进行迭代,为每个匹配元素执行函数
    $.each(t, function () {
      d[this.name] = this.value;
    });
    //转换为JSON字符串
    return JSON.stringify(d);
  }

  $("#submit_demo").click(function () {
    alert(get_form_value());
  });
</script>
```

## 运行结果

![](http://cdn.hurra.ltd/img/20200528224751.png)

## 备注

> \$.each()函数中:
>
> - return false 相当于 break
>
> - return true 相当于 continue
