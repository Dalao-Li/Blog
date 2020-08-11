# 一、概念
JSON(JavaScript Object Notation) 是一种轻量级的数据交换格式，采用完全独立于语言的文本格式，是理想的数据交换格式。同时，JSON是 JavaScript 原生格式，这意味着在 JavaScript 中处理 JSON数据不须要任何特殊的 API 或工具包。
在JSON中，有两种结构：对象和数组.

```js
var data = {key1:value1,key2:value2}

//例如
var data = {
    "name":"dalao",
    "pwd":123456
}
```



## 二、类别

在数据传输过程中,JSON以字符串形式传递,JS操作的是JSON对象

JSON字符串:

```js
var data ='{"name":"dalao", "pwd":123}'
```
JSON对象：

```js
var data = {"name":"dalao","pwd":123456}

```

相互转换  
> - JSON字符串转JSON对象  
> var data= jQuery.parseJSON(data)
>
> - JSON对象转JSON字符串  
> var data =JSON.stringify(data)




![](http://cdn.hurra.ltd/img/赞赏码.png)
