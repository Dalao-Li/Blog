> - 前文

上文实现了Django对数据库的操作,本篇则为Django视图与模板的教程

访问网站的本质即为访问对应的html文件,后在由浏览器等对其进行渲染,最终展示出页面


# 目的

- 任务一 : 访问http://127.0.0.1:8000/app/index,读取index.html,显示内容

- 任务二 :访问http://127.0.0.1:8000/app/db,在网页上显示数据库中所有元素信息


# 任务一

## 模板

- 新建模板  
在app目录下新建templates文件夹,由于保存html

![](http://cdn.hurra.ltd/img/20200803191147.png)


- 注册模板目录

新建的模板目录需在项目设置文件中进行注册  

打开主目录settings.py文件,找到TEMPLATES,将新增模板的路径添加至'DIRS'项中:
```py
TEMPLATES = [
    {
        ......

        'DIRS': [
            os.path.join(BASE_DIR, 'templates'),

            # 新建的模板目录
            os.path.join(BASE_DIR, 'app/templates')
        ],
        
        ......
    },
]
```

在demo/app/templates目录下新建index.html
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>
    <h1>Hello World!</h1>
</body>
</html>
```

## 路由

第一步中已完成模板目录的新建与html文件的编写,下面需配置路由,以便访问html文件


- 编写视图函数
  
打开app/views.py文件,添加:
```py
from django.shortcuts import render

# Create your views here.

def index(request):
    return render(request, 'index.html')
```

- 绑定子路由

编写好函数后,需将其绑定到对应路由,由于此处是在项目中的应用里配置,故为子路由

在app目录下新建urls.py文件,添加:

```py
from django.urls import path
from app import views

urlpatterns = [
    # 将函数绑定至对应路由
    path('index/', views.index)
]
```

- 注册子路由

绑定还本应用的路由后,还需在项目中进行注册

打开主目录下的urls.py文件,添加:
```py
from django.contrib import admin
from django.urls import path,include

urlpatterns = [
    ......

    # 注册app应用的路由
    path('app/',include('app.urls'))

    ......
]
```
此处include()函数含义为包含app中的所有路由,即实现路由的转发(从主路由分发至子路由)

运行项目,访问http://127.0.0.1:8000/app/index

![](http://cdn.hurra.ltd/img/20200803193631.png)

# 任务二

任务一中已实现访问静态页面,此处将实现对动态页面的渲染与访问


- 建立页面  

在demo/app/templates目录下新建db.html

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Title</title>
</head>
<body>
{% for i in data %}
    <h1>学号 : {{ i.num }} </h1>
    <h2>姓名 : {{ i.name }} </h2>
    <h2>年龄 : {{ i.age }} </h2>
    {% if i.sex == 'M' %}
        <h2>性别 : 男 </h2>
    {% elif i.sex == 'W' %}
        <h2>性别 : 男 </h2>
    {% endif %}
{% endfor %}
</body>
</html>
```
此处data为从数据库中获取的值,读取html作为参数传入

- 编写视图函数

编辑app/views.py,增加:

```py
.....

def db(request):
    # 获取数据中全部信息
    stu_list = [i for i in Stu.objects.all()]

    return render(request,'db.html',{'data':stu_list})

```

- 添加路由  

编辑app/urls.py,增加:
```py
urlpatterns = [
    .....

    path('db/', views.db)
]
```

运行项目,访问http://127.0.0.1:8000/app/db

![](http://cdn.hurra.ltd/img/20200803222027.png)

---

![](http://cdn.hurra.ltd/img/赞赏码.png)
