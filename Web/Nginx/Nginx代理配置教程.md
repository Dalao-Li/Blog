- [环境](#环境)
- [一、目的](#一目的)
- [二、设计](#二设计)
  - [1.端口映射](#1端口映射)
  - [2.新建容器](#2新建容器)
  - [3.修改配置文件](#3修改配置文件)
    - [3.1 默认代理](#31-默认代理)
    - [3.2 自定义代理](#32-自定义代理)
    - [3.3 ip代理](#33-ip代理)
- [三、结果](#三结果)
- [四、问题](#四问题)



# 环境
> - 系统 : winsows10  
> - 软件 : Docker for Desktop

# 一、目的
使用Nginx实现:
> - 对默认页面的代理配置  
> - 对html文件的反向代理配置  
> - 实现对ip地址的反向代理配置



# 二、设计

## 1.端口映射

| `宿主机`端口  | `容器`端口 | 
| :-----:         | :----:   |
| 8080            | 80       | 
| 8081            | 81       | 
| 8082            | 82       | 

>访问`宿主机`的`8080`端口，相当于访问 `容器*`的`80`端口(即Nginx的默认端口);
>其它以此类推。  


## 2.新建容器

```s
docker run -itd -p 8080:80 -p 8081:81 -p 8082:82 nginx
```
![运行结果](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLzIwMjAwNTE0MDkyMjIxMjI4LnBuZw?x-oss-process=image/format,png)
![](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLzIwMjAwNTE0MDkyNDI0Mjg3LnBuZw?x-oss-process=image/format,png)

## 3.修改配置文件
>本容器中nginx.conf的位置为 **/etc/nginx/nginx.conf**

![](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLzIwMjAwNTE0MDkzMDUwNDYxLnBuZw?x-oss-process=image/format,png)
![](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLzIwMjAwNTE0MDk0MDE0MjIwLnBuZw?x-oss-process=image/format,png)

>在配置文件最后一行的意思是使用默认的配置文件，此处将其`注释`掉，以使用自己的配置


### 3.1 默认代理

在nginx.conf文件的**http**块中添加入以下代码


```shell
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
>配置容器80端口，实现访问宿主机 **http://127.0.0.1:8080**访问到Nginx的默认欢迎界面  

### 3.2 自定义代理
在/home目录下新建demo文件夹，创建a.html文件,修改其内容为
```html
<p>Successfully implemented the proxy to the HTML file<p>
```
在nginx.conf文件的http块中加入以下代码

```shell
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
>配置容器81端口，实现访问宿主机 **http://127.0.0.1:8081** 而通过Nginx反向代理访问自定义的页面

### 3.3 ip代理


即实现**127.0.0.1:8082**通过Nginx被**反向代理**到**127.0.0.1:5000**
```shell
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
>将容器82端口反向代理到Flask应用的端口，实现宿主机访问http://127.0.0.1:8082而能访问到默认地址为http://127.0.0.1:5000的Flask应用  

三个Server配置完成后，nginx.conf文件结构
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

重新加载配置文件
```shell
nginx -s reload
```
终端显示 **signal process started**时才表明修改成功，若有问题会提示错误

![](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLzIwMjAwNTE0MTAxMzQxMTM5LnBuZw?x-oss-process=image/format,png)

# 三、结果

![](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLzIwMjAwNTE0MTAyNTMxMjAzLnBuZw?x-oss-process=image/format,png)
<center>成功实现了对默认页面的访问</center>

![](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLzIwMjAwNTE0MTAyOTI1OTQucG5n?x-oss-process=image/format,png)
<center>成功实现了对自定义页面的代理</center>

![](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLzIwMjAwNTE0MTAyMTMzOTMwLnBuZw?x-oss-process=image/format,png)
<center>出现了问题，反向代理失败</center>  


# 四、问题

1.  分析

![](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLzIwMjAwNTE0MTAzMTI4ODE3LnBuZw?x-oss-process=image/format,png)

这路本意是将**http://127.0.0.1:82**转发到宿主机的**http://127.0.0.1:5000**，但Nginx处于Linux环境中，所以此处localhost实际上指的是`容器`内的localhost而并非`宿主机`内的localhost，因此出现错误情况。

2. 解决

在windows环境下可使用`host.docker.internal`指代宿主机的localhost地址  

修改后配置文件为
```shell
server{
    listen 82;    
    server_name localhost;
    location / {
         proxy_pass http://host.docker.internal:5000;  
    }
}
```
重新加载配置文件

![](https://imgconvert.csdnimg.cn/aHR0cDovL2Nkbi5odXJyYS5sdGQvaW1nLzIwMjAwNTE0MTA0MzQ3NDI5LnBuZw?x-oss-process=image/format,png)
<center>成功实现了将http://127.0.0.1:8082通过Nginx代理到http://127.0.0.1:5000</center>  

---

![](http://cdn.hurra.ltd/img/赞赏码.png)