# 一、概念

简单说就是可以在不影响已经写好的函数结构上,给函数添加额外功能的另一种函数

# 二、示例

1. 显示每个函数的运行时间

```py
import time

# 定义装饰器
def decorator(func):
    def wrapper(*args, **kwargs):
        start_time = time.time()
        func()
        end_time = time.time()
        print(end_time - start_time)
    return wrapper

@decorator
def func():
    num = 0
    for i in range(1234356):
        num += i
    print(num)

if __name__ == "__main__":
    func()
```

![](http://cdn.hurra.ltd/img/20201024135555.png)

---

2. 显示当前运行函数的函数名

```py
# 装饰器
def decorator(func):
    def wrapper(*args, **kwargs):
        print("装饰器显示函数名:%s" % func.__name__)
        return func(*args, **kwargs)
    return wrapper

@decorator
def func_a():
    print("aaaaaaa\n")

@decorator
def func_b():
    print("bbbbbbb\n")

if __name__ == "__main__":
    func_a()
    func_b()
```

![](http://cdn.hurra.ltd/img/20201024152019.png)

![](http://cdn.hurra.ltd/img/赞赏码.png)
