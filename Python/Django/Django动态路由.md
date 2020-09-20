# 正则匹配

## 单关键字  

views.py
```py
def dis(request,value):
    return HttpResponse(value)
```

urls.py
```py
urlpatterns = [
    url(r'^dis/(\w+)$', views.dis),
]
```
- `\w` :匹配字母、数字、下划线,等价于[A-Za-z0-9_]
- `+`:匹配前面的子表达式一次或多次
- `$`:表示结尾
此时可以匹配`127.0.0.1:8000/dis/<字符>`这类url,并且<字符>部分的值将作为dis函数的第二个参数

实现效果
![](http://cdn.hurra.ltd/img/20200903085713.png)

![](http://cdn.hurra.ltd/img/20200903085600.png)

![](http://cdn.hurra.ltd/img/20200903091232.png)


## 多关键字
views.py
```py
from django.http import HttpResponse

def dis(request,v1,v2):
    res = "v1:%s v2:%s"%(v1,v2)
    return HttpResponse(res)
```

urls.py
```py
urlpatterns = [
    url(r'^dis/(?P<v1>\w+)/(?P<v2>\w+)', views.dis),
]
```
- 关键字传参:前面的w+传给v1,后面的w+传给v2
此时可以匹配`127.0.0.1:8000/dis/<字符1>/<字符2>`这类url,并且字符1将传给dis函数的v1参数;字符2将传给dis函数的v2参数


---

# 反射机制


```py
urlpatterns = [
    re_path(r'^dis/(?P<fuc_name>\w+)/$',views.use_fuc_byname),
]
```
反射:通过输入的函数名调用函数

```py
from django.http import HttpResponse

def use_fuc_byname(request,fuc_name):
    return eval(fuc_name)(request)


def hello_world(request):
    return HttpResponse('HELLO WORLD')

def goodbye_world(request):
    return HttpResponse('GOODBYE WORLD')
```

此时输入`http:127.0.0.1:8000/dis/hello_world`时,会自动调用hello_world()函数

![](http://cdn.hurra.ltd/img/20200903103754.png)



![](http://cdn.hurra.ltd/img/赞赏码.png)
