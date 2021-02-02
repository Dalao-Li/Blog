<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:35
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-01 16:50:20
-->

# Django 操作数据库

建立一个应用 app

```py
python3 manage.py startapp app
```

![](http://cdn.hurra.ltd/img/20200802134308.png)

# 连接

编辑主目录下 settings.py文件,找到 DATABASES

![](http://cdn.hurra.ltd/img/20200802140333.png)

此为默认配置,会在项目下建立 sqlite3 数据库

若使用其他数据库,需进行修改,此处以 MySQL 为例:

```sh
DATABASES = {
    'default': {
        # 数据库引擎,此处以MySQL为例
        'ENGINE': 'django.db.backends.mysql',
         #数据库名
        'NAME': <db_name>,
        # 连接用户名
        'USER': <user_name>,
        # 密码
        'PASSWORD':<pwd>,
        #数据库主机的ip地址
        'HOST':<IP>,
        # 默认mysql访问端口
        'PORT':<port>,
    }
}
```

# 建表

编辑 app/models.py

```py
from django.db import models


# Create your models here.
# 学生表
class Stu(models.Model):
    choices=(('M', '男'),('W', '女')),
    num = models.CharField(primary_key=True,verbose_name='学号',help_text='请输入学号',max_length=5)
    name = models.CharField(verbose_name='姓名',help_text='请输入姓名',max_length=5)
    age = models.IntegerField(verbose_name='年龄',help_text='请输入年龄')
    sex = models.CharField(verbose_name='性别',help_text='请选择性别',default='M',max_length=1)

    # 元数据
    class Meta:
        # 按'age'字段升序排列
        ordering = ['age']

    # 显示类信息
    def __str__(self):
        sex = '男' if self.sex == 'M' else '女'
        return '学号:%s  姓名:%s  年龄:%s 性别:%s' % (self.num, self.name, self.age,sex)
```

## 字段

| 类型          | 说明                                                                                                                           |
| ------------- | ------------------------------------------------------------------------------------------------------------------------------ |
| AutoField     | 一个自动增加的整数类型字段.通常不需要自己编写,Django 会自动添加自增字段:id = models.AutoField(primary_key=True),从 1 开始计数 |
| CharField     | 字符串类型.必须接收一个 max_length 参数,表示字符串长度不能超过该值.默认的表单标签是 input text                               |
| TextField     | 大量文本内容,在 HTML 中表现为 Textarea 标签                                                                                    |
| IntegerField  | 整数类型,取值范围-2147483648 到 2147483647                                                                                     |
| DateField     | 日期类型,Python 中的 datetime.date()实例,例如 2020-08-05                                                                       |
| DateTimeField | 日期时间类型,Python datetime.datetime()实例.多了小时、分和秒的显示,例如 2020-08-05 23:08                                      |
| FileField     | 上传文件类型                                                                                                                   |
| ImageField    | 图像类型                                                                                                                       |

## 字段参数

| 类型         | 说明                                                                                                       |
| ------------ | ---------------------------------------------------------------------------------------------------------- |
| default      | 字段的默认值,可以是值或者一个可调用对象                                                                    |
| help_text    | 额外显示在表单部件上的帮助文本                                                                             |
| primary_key  | 若为字段设置了 primary_key=True,则当前字段变为主键; primary_key=True 隐含 null=False 和 unique=True 的意思 |
| verbose_name | 为字段设置可读,直观的别名                                                                                  |
| choices      | 选择框标签,值为一个二维的二元元组;第一个元素表示数据库内的真实值,第二个表示页面上的显示内容                |

编辑完成后终端执行:

```py
# 为改动创建迁移记录
python manage.py makemigrations

# 将操作同步到数据库
python manage.py migrate
```

![](http://cdn.hurra.ltd/img/20200802152633.png)

此时 app/migrations 下生成 0001_initial.py 文件

![](http://cdn.hurra.ltd/img/20200802233105.png)

# 操作

## 管理

Django 自带后台管理页面,使用前需创建管理员用户

在终端执行

```py
python manage.py createsuperuser
```

输入用户名和密码,邮箱地址可选

![](http://cdn.hurra.ltd/img/20200802153640.png)

启动项目,访问http://127.0.0.1:8000/admin/

![](http://cdn.hurra.ltd/img/20200802153902.png)
![](http://cdn.hurra.ltd/img/20200802154127.png)

现在还无法看到建好的表,需在 admin 中注册,将 app 的模型加入站点内,接受站点管理

打开 app/admin.py 文件,修改为:

```py
from django.contrib import admin
from .models import Stu
# Register your models here.

# 注册Stu
admin.site.register(Stu)
```

刷新

![](http://cdn.hurra.ltd/img/20200802213738.png)

## 新增

- 可视化  
  直接使用 Django 管理页面新增数据
  ![](http://cdn.hurra.ltd/img/20200802223956.png)

![](http://cdn.hurra.ltd/img/20200802224031.png)

由于之前设定了 ordering = ['age'],故添加的数据会按从小到大的顺序排列

- 代码实现

在命令行执行

```py
s = Stu(num='D-123',name='阿强',age=19,sex='M')

s.save()
```

上述代码等同于

```py
s = Stu.objects.create(num='D-123',name='阿强',age=19,sex='M')
```

![](http://cdn.hurra.ltd/img/20200802235206.png)

![](http://cdn.hurra.ltd/img/20200802235230.png)

## 查询

- 获取所有对象

```py
stu_list = Stu.objects.all()
```

![](http://cdn.hurra.ltd/img/20200802235655.png)

- 过滤查询

例如查询所有男性同学

```py
stu = Stu.objects.filter(sex='M')
```

![](http://cdn.hurra.ltd/img/20200803001551.png)

- 单一查询

例如查询学号为 A-123 的同学

```py
stu = Stu.objects.get(num='A-123')
```

![](http://cdn.hurra.ltd/img/20200803001831.png)

- 查询是否存在

例如查询学号为 B-456 的同学是否存在

```py
Stu.objects.filter(num='B-456').exists()
```

![](http://cdn.hurra.ltd/img/20200803004453.png)

## 修改

- 可视化  
  直接在管理页面修改

![](http://cdn.hurra.ltd/img/20200803002039.png)

- 代码

所有男性同学年龄改为 18 岁

```py
Stu.objects.filter(sex='M').update(age=18)
```

![](http://cdn.hurra.ltd/img/20200803004011.png)

![](http://cdn.hurra.ltd/img/20200803004052.png)

## 删除

- 可视化

直接在管理页面删除

- 代码

删除学号为 A-123 的同学信息

```py
Stu.objects.filter(num='A-123').delete()
```

![](http://cdn.hurra.ltd/img/20200803004719.png)
![](http://cdn.hurra.ltd/img/20200803004753.png)

---

![](http://cdn.hurra.ltd/img/收款码.png)
