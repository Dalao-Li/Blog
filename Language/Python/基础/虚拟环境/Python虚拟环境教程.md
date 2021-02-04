# Windows 环境


## 安装 virtualenv

```py
pip install virtualenv
```

![](http://cdn.hurra.ltd/img/20200312224255893.png)

## 创建

创建名为 venv 的虚拟环境

```
virtualenv venv
```

![](http://cdn.hurra.ltd/img/TIM截图20200515113058.png)

![](http://cdn.hurra.ltd/img/20200515113137.png)

## 设置解释器

```sh
# 指令格式为:
virtualenv  -p    python.exe文件的路径  创建的虚拟环境的名字
```

例如,这里用的是 Anaconda,指令为:virtualenv -p D:\App\anaconda\python.exe venv

![](http://cdn.hurra.ltd/img/20200515113404.png)

---

## 激活

进入 venv/Scripts 目录下

```sh
activate
```

![](http://cdn.hurra.ltd/img/20200515113603.png)

路径前出现了`(venv)`,表明当前处在 venv 虚拟环境下

---

## 退出

```sh
deactivate
```

![](http://cdn.hurra.ltd/img/20200515113732.png)

# linux 环境

## 设置

### 指定解释器

查询 linux 环境下 python 解释器的路径

```sh
whereis python
```

此处的路径为/usr/bin/python3.8

![](http://cdn.hurra.ltd/img/20200515114240.png)

```sh
virtualenv venv
```

![](http://cdn.hurra.ltd/img/20200515114449.png)

使用指定的解释器

```sh
virtualenv -p /usr/bin/python3.8  venv
```

![](http://cdn.hurra.ltd/img/20200515114605.png)

### 使用默认配置

```py
python -m virtualenv venv

```

## 激活

```sh
source venv/bin/activate
```

![](http://cdn.hurra.ltd/img/20200515114747.png)

---

## 退出

```sh
deactivate
```
