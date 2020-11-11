# 搭建 SQLServer

```shell
docker run -itd -e "ACCEPT_EULA=Y" -e "SA_PASSWORD=Dalao@13546!" -p 1433:1433  --name sqlserver2019   registry.cn-hangzhou.aliyuncs.com/vex/sqlserver:v1
```

- 用户名 : SA
- 密码 : Dalao@13546!

# Navicat 连接

![](http://cdn.hurra.ltd/img/20201012105710.png)

# 命令行交互

进入容器,进入 SQLServer

```s
/opt/mssql-tools/bin/sqlcmd -S localhost -U SA -P "Lyh@199913!"
```

显示所有数据库

![](http://cdn.hurra.ltd/img/20201012110513.png)

显示表

![](http://cdn.hurra.ltd/img/20201012130931.png)

别忘记输入`GO`,那样才会执行命令

# python 交互

![](http://cdn.hurra.ltd/img/20201012130100.png)

```py
import pymssql

conn = pymssql.connect(
    host= <ip>:<端口>,
    user="sa",
    password= <密码>,
    database= <数据库>,
    charset= 'utf8'
)
# 使用cursor()方法获取操作游标
cursor = conn.cursor()

sql = "SELECT * FROM 表"
try:
    # 执行SQL语句
    cursor.execute(sql)
    results = cursor.fetchall()
    print(results)
except:
    print(results)
# 关闭数据库连接
conn.close()
```

![](http://cdn.hurra.ltd/img/20201012180210.png)
