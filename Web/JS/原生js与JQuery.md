# 1.差异

例如:

```html
<input type="text" id="name" />

<button type="button" id="addBtn"></button>
```

## 获取控件

document.getElementById("id")可以直接获取当前对象  
jQuery 利用\$("#id")获取的是一个[object Object]，需用\$("#id")[0]或\$("#id").get(0)获取真实对象

```js
const name = document.getElementById("name");

const name = $("#name")[0];
```

## 获取值

```js
//js
document.getElementById("name").value();

//Jquery
$("#name").val();
```

## 事件

点击按钮时弹出弹窗

```js
//js
const addBtn = document.getElementById("addBtn");
addBtn.addEventListener("click", ()=>{
    alert("666")
})

//JQuery
$("#addBtn").click(functon(){
    alert("666")
})
```

# 2.匿名函数

js 中为 ()=>

jQuery 中为 function(){}

![](http://cdn.hurra.ltd/img/收款码.png)
