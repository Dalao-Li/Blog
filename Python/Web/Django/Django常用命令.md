<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-28 22:29:34
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-01 17:51:27
-->

# 新建应用

```shell
python manage.py startapp app
```

# 迁移数据库

```shell
# 终端执行,为改动创建迁移记录
python manage.py makemigrations


# 将操作同步到数据库
python manage.py migrate  
```
- 同步到多个数据库

```shell
python manage.py migrate --database=<路由表中应用对应的数据库>
```

# 创建管理员用户

```shell
python manage.py createsuperuser
```