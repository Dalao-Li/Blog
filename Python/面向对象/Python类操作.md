<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-01 12:29:16
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-02 15:47:38
-->


# 类定义
```py
class Stu:
    def __init__(self,num,name,age):
        self.num = num
        self.name = name
        self.age = age
```

# self参数

self代表类的实例，而非类;类的方法与普通的函数只有一个特别的区别——它们必须有一个额外的第一个参数名称, 按照惯例它的名称是 self

# 继承
```py
class People:
    def __init__(self,name,age):
        self.name = name
        self.age = age
    def speak(self):
        print(self.name,self.age)


class Student(People):
    def __init__(self,name,age,num):
        People.__init__(self,name,age)
        self.num = num
    
    def speak(self):
        print(self.name,self.age,self.num)
```