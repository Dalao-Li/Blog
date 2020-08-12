- [一、Windows环境](#一windows环境)
  - [1. 安装virtualenv](#1-安装virtualenv)
  - [2. 创建](#2-创建)
  - [3.设置解释器](#3设置解释器)
  - [4. 激活](#4-激活)
  - [5. 退出](#5-退出)
- [二、linux环境](#二linux环境)
  - [1.设置](#1设置)
    - [1.1 指定解释器](#11-指定解释器)
    - [1.2 使用默认配置](#12-使用默认配置)
  - [2. 激活](#2-激活)
  - [3. 退出](#3-退出)


# 一、Windows环境

创建一个文件夹demo，进入其目录下

## 1. 安装virtualenv

```py
pip install virtualenv
```
![](http://cdn.hurra.ltd/img/20200312224255893.png)

## 2. 创建

创建名为venv的虚拟环境
```
 virtualenv venv 
 ```
![](http://cdn.hurra.ltd/img/TIM截图20200515113058.png)

![](http://cdn.hurra.ltd/img/20200515113137.png)

## 3.设置解释器

```s
# 指令格式为:
virtualenv  -p    python.exe文件的路径  创建的虚拟环境的名字
```

例如,这里用的是Anaconda,指令为:virtualenv -p D:\App\anaconda\python.exe venv

![](http://cdn.hurra.ltd/img/20200515113404.png)

---

## 4. 激活
进入venv/Scripts目录下

```s
activate
```
![](http://cdn.hurra.ltd/img/20200515113603.png)

路径前出现了`(venv)`，表明当前处在venv虚拟环境下

---

## 5. 退出
```s
deactivate
```
![](http://cdn.hurra.ltd/img/20200515113732.png)



# 二、linux环境

创建一个文件夹,安装 virtualenv与Windows环境下相同

## 1.设置

### 1.1 指定解释器

查询linux环境下python解释器的路径
```
whereis python
```
此处的路径为/usr/bin/python3.8

![](http://cdn.hurra.ltd/img/20200515114240.png)

```
 virtualenv venv 
```
![](http://cdn.hurra.ltd/img/20200515114449.png)

使用指定的解释器

```
virtualenv -p /usr/bin/python3.8  venv
```
![](http://cdn.hurra.ltd/img/20200515114605.png)

### 1.2 使用默认配置
```py
python -m virtualenv venv

```

## 2. 激活
```
source venv/bin/activate
```
![](http://cdn.hurra.ltd/img/20200515114747.png)

---

## 3. 退出
```
 deactivate
```