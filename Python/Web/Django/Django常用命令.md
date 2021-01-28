<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-28 22:29:34
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-01-28 22:31:40
-->
# 新建应用

```sh
python manage.py startapp app
```

# 迁移数据库

```sh
# 终端执行,为改动创建迁移记录
python manage.py makemigrations


# 将操作同步到数据库
python manage.py migrate
```

# 创建管理员用户

```shell
python manage.py createsuperuser
```