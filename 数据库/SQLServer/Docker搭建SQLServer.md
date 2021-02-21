<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-04 23:48:41
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-04 23:49:54
-->
## 搭建 SQLServer

```docker
docker run -itd -e "ACCEPT_EULA=Y" -e "SA_PASSWORD=Dalao@13546!" -p 1433:1433  --name sqlserver2019   registry.cn-hangzhou.aliyuncs.com/vex/sqlserver:v1
```

- 用户名 : SA
- 密码 : Dalao@13546!



## 命令行交互

- 进入容器

```docker
/opt/mssql-tools/bin/sqlcmd -S localhost -U SA -P "Lyh@199913!"
```

- 显示所有数据库

![](https://cdn.hurra.ltd/img/20201012110513.png)

- 显示表

![](https://cdn.hurra.ltd/img/20201012130931.png)

>别忘记输入`GO`,那样才会执行命令(反人类的SQLServer)