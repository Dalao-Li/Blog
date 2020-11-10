# \*args

> \*args 用来将参数打包成 tuple 给函数调用

```py
def fun(*args):
    value = args
    print(value)
    print(type(value))


if __name__ == "__main__":
    fun(1)
    fun(1, 'A')
```

![](http://cdn.hurra.ltd/img/20200905193323.png)

```py
def fun(x, *args):
    value = args
    print(x, value)
    print(type(x), type(value))


if __name__ == "__main__":
    fun('d')
    fun('B', 'A', 'MMM')
```

![](http://cdn.hurra.ltd/img/20200905193601.png)

# \*\*kwargs

> \*\*kwargs 将关键字参数打包成 dict 给函数调用

```py
def fun(**kwargs):
    value = kwargs
    print(value)
    print(type(value))


if __name__ == "__main__":
    fun(name='lili')
    fun(num='20209902', name='wang', age=18)
```

![](http://cdn.hurra.ltd/img/20200905193946.png)

> `注意:参数 arg、\*args、\*\*kwargs 三个参数的位置必须是(\*args,**kwargs)顺序,否则程序报错`

![](http://cdn.hurra.ltd/img/收款码.png)
