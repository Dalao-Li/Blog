# Docker+Nginx操作简要教程

# 一、目的
使用Nginx进行最基本的反向代理操作,实现  
> - 对默认页面的代理配置  
> - 对任意html文件的反向代理配置  
> - 实现对任意ip地址的反向代理配置



# 二、实验环境
> - 系统 : winsows10  
> - 软件 : Docker for Desktop

# 三、操作流程
## 1.拉取Nginx镜像  
```
docker pull nginx
```  
## 2.配置nginx.conf文件  
    
## 3.重新加载配置文件
```
nginx - s reload
```
## 4.运行查看结果  


# 四、详细设计
## 1.端口映射规则
>| 宿主机端口  | 容器端口 | 
>| :-----:    | :----:   |
>| 8080       | 80       | 
>| 8081       | 81       | 
>| 8082       | 82       | 
>即访问**宿主机**的8080端口，相当于访问**容器**的80端口(即Nginx的默认端口);  
>其它以此类推。
## 2.新建容器，查看运行结果
```
docker run -itd -p 8080:80 -p 8081:81 -p 8082:82 nginx
```
运行结果：
![运行结果](http://cdn.hurra.ltd/img/20200514092221228.png)
![](http://cdn.hurra.ltd/img/20200514092424287.png)

## 3.修改配置文件

>本容器环境下nginx.conf的位置为 **/etc/nginx/nginx.conf**

![](http://cdn.hurra.ltd/img/20200514093050461.png)
![](http://cdn.hurra.ltd/img/20200514094014220.png)

>在配置文件最后一行的意思是使用默认的配置文件，此处我们将其**注释**掉，以使用自己的配置


在nginx.conf文件的**http**块中添加入以下代码进行反向代理配置
## 3.1Nginx的默认代理配置
>配置容器80端口，实现访问宿主机http://127.0.0.1:8080访问到Nginx的默认欢迎界面  
```
#1.配置80端口的反向代理
server{
 
    #监听Nginx80端口
    listen 80;    
 
    #配置服务名,若无特殊配置,localhost即指代宿主机的127.0.0.1
    server_name localhost;
 
    #设置转发
    location / {
         #首页文件的目录
         root /usr/share/nginx.html;
         #默认的首页文件
         index index.html index.htm;
       
    }
}
```
## 3.2自定义的html页面的代理配置
>配置容器81端口，实现访问宿主机http://127.0.0.1:8081而访问自定义的页面

在/home 目录下新建demo文件夹，创建a.html文件
![](http://cdn.hurra.ltd/img/20200514095406966.png)
修改a.html的内容为
```
<p>Successfully implemented the proxy to the HTML file<p>
```
在nginx.conf文件的http块中加入以下代码
```
#2.配置81端口的反向代理
server{
 
    #监听Nginx的81端口
    listen 81;    
 
    #配置服务名,若无特殊配置localhost,即指代本机的127.0.0.1
    server_name localhost;
 
    #设置转发
    location / {
         #设置我们自定义文件的目录
         root /home/demo;
         #设置我们自定义的首页文件
         index a.html a.htm;
    }
}
```

## 3.3对ip的代理配置
>将容器82端口反向代理到Flask应用的端口，实现宿主机访问http://127.0.0.1:8082而能访问到默认地址为http://127.0.0.1:5000的Flask应用  
即实现**127.0.0.1:8082**通过Nginx被**反向代理**到**127.0.0.1:5000**
```
#3.配置82端口的反向代理
server{
 
    #监听Nginx的82端口
    listen 82;    
 
    #配置服务名,若无特殊配置localhost即指代本机的127.0.0.1地址
    server_name localhost;
 
    #设置转发,将127.0.0.1:82转发到127.0.0.1:5000
    location / {
         proxy_pass 127.0.0.1:5000;
    }
}
```
三个Server配置完成后，nginx.conf文件的示例
```
http{
    #配置1
    server{
       ...
    }
    #配置2
    server{
       ...
    }
    #配置3
    server{
      ...
    }
    ...
}
```
## 4、重新加载配置文件
```
nginx -s reload
```
>终端signal process started时才表明修改成功，若有问题会提示错误
![](http://cdn.hurra.ltd/img/20200514101341139.png)

## 5、运行结果
![](http://cdn.hurra.ltd/img/20200514102531203.png)
<center>成功实现了对默认页面的访问</center>

![](http://cdn.hurra.ltd/img/2020051410292594.png)
<center>成功实现了对自定义页面的代理</center>

![](http://cdn.hurra.ltd/img/20200514102133930.png)
<center>出现了问题，反向代理失败</center>  


## 6、分析问题
>未能成功实现将http://127.0.0.1:8082通过Nginx代理到http://127.0.0.1:5000

![](http://cdn.hurra.ltd/img/20200514103128817.png)

这里的本意是将**http://127.0.0.1:82**转发到宿主机的**http://127.0.0.1:5000**，但此处的Nginx是运行在Docker中，本身所处于虚拟的Linux环境，所以此处的localhost实际上指的是**容器**内localhost而并非**宿主机**内的localhost，因此出现错误情况。

## 7、解决方法
>在windows环境下可使用**host.docker.internal**指代宿主机的localhost地址  

修改后配置文件为
```
server{
 
    listen 82;    
    server_name localhost;
    location / {
         proxy_pass http://host.docker.internal:5000;  
    }
}
```
重新加载配置文件
![](http://cdn.hurra.ltd/img/20200514104347429.png)
<center>成功实现了将http://127.0.0.1:8082通过Nginx代理到http://127.0.0.1:5000</center>  