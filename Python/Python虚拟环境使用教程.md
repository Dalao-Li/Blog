# Python虚拟环境教程

# 一、Windows环境

## 1.创建虚拟环境
### 1.1创建一个空文件夹demo，并进入其目录下
### 1.2安装virtualenv工具
```
pip install virtualenv
```
![](http://cdn.hurra.ltd/img/20200312224255893.png)

### 1.3创建名叫venv的虚拟环境
```
 virtualenv venv 
 ```
 ![](http://cdn.hurra.ltd/img/TIM截图20200515113058.png)

![](http://cdn.hurra.ltd/img/20200515113137.png)

### 1.4设置python解释器,这里用的Anaconda

```
#指令格式为:

virtualenv  -p    python.exe文件的路径  创建的虚拟环境的名字
```
![](http://cdn.hurra.ltd/img/20200515113404.png)

---

## 2、使用虚拟环境
进入venv/Scripts目录下

```
输入activate  敲回车
```
![](http://cdn.hurra.ltd/img/20200515113603.png)

进入虚拟环境后，在路径前出现了(venv)的字符，表明当前处在venv虚拟环境下

---

## 3、退出虚拟环境
```
deactivate
```
![](http://cdn.hurra.ltd/img/20200515113732.png)


<br>
<br>


# 二、linux环境

## 1.创建虚拟环境
前几步与Windows环境下相同，仅设置python解释器的步骤不同  

### 1.1查询linux环境下python解释器的路径
```
whereis python
```
>此处的路径为/usr/bin/python3.8

![](http://cdn.hurra.ltd/img/20200515114240.png)
### 1.2 创建虚拟环境
```
 virtualenv venv 
 ```
![](http://cdn.hurra.ltd/img/20200515114449.png)
### 1.3 设置python解释器
```
virtualenv -p /usr/bin/python3.8  venv
```
![](http://cdn.hurra.ltd/img/20200515114605.png)

---

## 2使用虚拟环境
```
  source venv/bin/activate
```
![](http://cdn.hurra.ltd/img/20200515114747.png)

---

## 3 退出虚拟环境

```
 deactivate
```