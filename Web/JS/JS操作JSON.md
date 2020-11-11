# 一、概念

JSON(JavaScript Object Notation) 是一种轻量级的数据交换格式,是 JavaScript 原生格式;在 JavaScript 中处理 JSON 数据不须要任何特殊的 API 或工具包.
在 JSON 中，有两种结构:对象和数组.

```js
var data = { key1: value1, key2: value2 };

//例如
var data = {
  name: "dalao",
  pwd: 123456,
};
```

## 二、类别

在数据传输过程中,JSON 以字符串形式传递,JS 操作的是 JSON 对象

JSON 字符串:

```js
var data = '{"name":"dalao", "pwd":123}';
```

JSON 对象：

```js
var data = { name: "dalao", pwd: 123456 };
```

相互转换

- JSON 字符串转 JSON 对象  
  var data= jQuery.parseJSON(data)

- JSON 对象转 JSON 字符串  
  var data =JSON.stringify(data)

![](http://cdn.hurra.ltd/img/收款码.png)
