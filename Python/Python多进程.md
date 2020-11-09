# 多进程

## 普通情况

```py
import time

def cook():
    for i in range(3):
        print("做饭...")
        time.sleep(0.5)

def wash():
    for i in range(3):
        print("洗衣服...")
        time.sleep(0.5)

if __name__ == '__main__':
    cook()
    wash()
```

![](http://cdn.hurra.ltd/img/20201019171128.png)

两个任务先后完成,共花费 3 秒钟

此时,可使用多线程的方式让两个任务同步执行

---

## 多进程执行任务

步骤:

> - 导入进程包
> - 使用进程类创建进程对象
> - 使用进程对象启动进程执行指定任务

```py
import time
# 导入进程包
import multiprocessing

def cook():
    for i in range(3):
        print("做饭...")
        time.sleep(0.5)

def wash():
    for i in range(3):
        print("洗衣服...")
        time.sleep(0.5)

if __name__ == '__main__':
    # 使用进程类创建进程对象
    cook_process = multiprocessing.Process(target=cook)
    wash_process = multiprocessing.Process(target=wash)

    # 使用进程对象启动进程执行指定任务
    cook_process.start()
    wash_process.start()
```

![](http://cdn.hurra.ltd/img/20201019173207.png)

## 进程执行带参任务

### args 传参

args 以元组的形式给线程传递参数

```py
import time
import multiprocessing

def cook(num):
    for i in range(num):
        print("做饭...")
        time.sleep(0.5)

def wash(num):
    for i in range(num):
        print("洗衣服...")
        time.sleep(0.5)

if __name__ == '__main__':
    # 使用进程类创建进程对象
    cook_process = multiprocessing.Process(target=cook, args=(4,))
    wash_process = multiprocessing.Process(target=wash, args=(4,))

    # 使用进程对象启动进程执行指定任务
    cook_process.start()
    wash_process.start()
```

![](http://cdn.hurra.ltd/img/20201019175806.png)

### kwargs 传参

args 以字典的形式给线程传递参数

```py
import time
# 导入进程包
import multiprocessing

def cook(num):
    for i in range(num):
        print("做饭...")
        time.sleep(0.5)

def wash(num):
    for i in range(num):
        print("洗衣服...")
        time.sleep(0.5)

if __name__ == '__main__':
    # 使用进程类创建进程对象
    cook_process = multiprocessing.Process(target=cook, kwargs={"num": 2})
    wash_process = multiprocessing.Process(target=wash, kwargs={"num": 2})

    # 使用进程对象启动进程执行指定任务
    cook_process.start()
    wash_process.start()
```

![](http://cdn.hurra.ltd/img/20201019180329.png)

## 获取进程编号

获取当前进程编号

> os.getpid()

```py
import os
pid = os.getpid()
print(pid)
```

![](http://cdn.hurra.ltd/img/20201019181524.png)

获取当前父进程的编号

> os.getppid()

```py
import time
import os
import multiprocessing

def cook():
    for i in range(2):
        print("做饭进程的pid: ", os.getpid())
        print("做饭进程的父进程pid: ",os.getppid())
        print("做饭...")
        time.sleep(0.5)

def wash():
    for i in range(2):
        print("洗衣服进程的pid: ", os.getpid())
        print("洗衣服进程的父进程pid: ", os.getppid())
        print("洗衣服...")
        time.sleep(0.5)

if __name__ == '__main__':
    print("主进程的pid: ",os.getpid())
    cook_process = multiprocessing.Process(target=cook)
    wash_process = multiprocessing.Process(target=wash)
    cook_process.start()
    wash_process.start()
```

![](http://cdn.hurra.ltd/img/20201019183002.png)

## 守护进程

主进程会等待所有的子进程执行结束再结束

实际开发过程中则希望主进程结束时结束所有子进程

此时需要主进程创建守护进程

> - 守护进程会在主进程代码执行结束后就终止
>
> - 守护进程内无法再开启子进程,否则抛出异常：AssertionError: daemonic processes are not allowed to have children
>
> - 注意：进程之间是互相独立的，主进程代码运行结束，守护进程随即终止

```py
import time
import os
import multiprocessing

def work():
    for i in range(10):
        print("Work in....")
        time.sleep(0.2)

if __name__ == '__main__':
    # 创建子进程
    work_process = multiprocessing.Process(target=work)
    # 设置守护进程,主进程结束后子进程直接销毁
    work_process.daemon = True
    work_process.start()
    time.sleep(1)
    print("主进程结束!")
```

![](http://cdn.hurra.ltd/img/20201019195202.png)

可见,主进程结束时子进程也立即结束

![](http://cdn.hurra.ltd/img/收款码.png)
