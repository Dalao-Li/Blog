# 一、目的
使用Jquery获取form中所有控件的值,并封装成JSON

# 二、代码实现

## 2.1 head
```html
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <script src="https://cdn.staticfile.org/jquery/1.10.2/jquery.min.js"></script>
    <title>Document</title>
</head>
```

## 2.2 body
```html
<body>
    <form method="post" action="" id="form">
        用户名: <input type="text" name="username"><br>
        密码: <input type="text" name="pwd"><br>
        <button type="submit" value="" id="submit_demo">提交</button>
    </form>
</body>
```

## 2.3 script
```html
<script>
    function get_form_value(){
        var d = {};
        var t = $('form').serializeArray();
        $.each(t, function () {
            d[this.name] = this.value;
        })
        return JSON.stringify(d)
    }

    $('#submit_demo').click(function () {
        
        alert(get_form_value());
    });
</script>
```
> serializeArray() 方法通过序列化表单值来创建对象（name 和 value）的数组
> .each()  对 jQuery 对象进行迭代，为每个匹配元素执行函数。

## 2.4 运行结果
![](http://cdn.hurra.ltd/img/20200528224751.png)


# 三、 全部代码
```html
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <script src="https://cdn.staticfile.org/jquery/1.10.2/jquery.min.js"></script>
    <title>Document</title>
</head>

<body>
    <form method="post" action="" id="form">
        用户名: <input type="text" name="username"><br>
        密码: <input type="text" name="pwd"><br>
        <button type="submit" value="" id="submit_demo">提交</button>
    </form>
</body>
<script>
    function get_form_value(){
        var d = {};
        var t = $('form').serializeArray();
        $.each(t, function () {
            d[this.name] = this.value;
        })
        return JSON.stringify(d)
    }

    $('#submit_demo').click(function () {
        
        alert(get_form_value());
    });
</script>

</html>
```