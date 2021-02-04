<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-04 21:43:48
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-04 21:52:36
-->

# Django Manager类

## 创建对象

```py
class User(models.Model):
    name = models.CharField(max_length=10)
    pwd = models.CharField(max_length=300)
```

此时,若想对数据库进行操作,需通过以下语句
```py
User.objects.create(name=name,pwd=pwd)

User.objects.filter(name=name)

.....
```
这样若想在操作过程中执行其他操作,则显得异常麻烦,因此,可以自定义管理器
```py
class UserManager(models.Manager):
    def add_user(self, name, pwd):
        # 可执行若干代码
        ...
        user = self.create(name=name, pwd=generate_password_hash(pwd))
        return user

    def get_user(self, name):
        # 可执行若干代码
        ...
        return self.get(name=name)

    def find_name(self, name):
        # 可执行若干代码
        ...
        return self.filter(name=name).exists()

class User(models.Model):
    name = models.CharField(max_length=10)
    pwd = models.CharField(max_length=300)
    
    # 赋值objects
    objects = UserManager()
```

这样,对User类的相关操作可简化为
```py
User.objects.add_user(name,pwd)

User.objects.find_name(name)
```

直观明了