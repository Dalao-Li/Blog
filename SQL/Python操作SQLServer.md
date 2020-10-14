# 搭建SQLServer

```s
docker run -itd -e "ACCEPT_EULA=Y" -e "SA_PASSWORD=Lyh@199913!" -p 1433:1433  --name sqlserver2019   registry.cn-hangzhou.aliyuncs.com/mkmk/sqlserver:2019
```

# Navicat连接
![](http://cdn.hurra.ltd/img/20201012105710.png)


# 命令行交互

进入容器,输入命令进入命令行
```s
/opt/msssql-tools/bin/sqlcmd -S localhost -U SA -P "Lyh@199913!"
```

新建数据库data

新建表Stu和Score


显示所有数据库

![](http://cdn.hurra.ltd/img/20201012110513.png)

显示表

![](http://cdn.hurra.ltd/img/20201012130931.png)

别忘记输入"GO",那样才会执行命令

# python交互

![](http://cdn.hurra.ltd/img/20201012130100.png)

```py
import pymssql

conn = pymssql.connect(
    host="172.20.157.168:1433",
    user="sa",
    password="Lyh@199913!",
    database="data",
    charset='utf8'
)
# 使用cursor()方法获取操作游标
cursor = conn.cursor()

sql = "SELECT * FROM Stu"
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