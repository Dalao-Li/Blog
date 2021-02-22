<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:34
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-22 22:44:47
-->


## 配置定时任务

```sh
#!/bin/bash

# 每小时第mintue分钟执行任务
read -p "输入分钟(00‐59):" mintue

# 每天第hour小时执行任务
read -p "输入小时(00‐24):" hour

# 每月第date天执行任务
read -p "输入日期(01‐31):" date

# 每年第month月执行任务
read -p "输入月份(01‐12):" month

# 每周第weak天执行任务
read -p "输入星期(00‐06):" weak

read -p "输入计划任务的命令或脚本:" program

# 追加命令至/etc/crontab文件中
echo "$mintue $hour $date $month $weak $program" >> /etc/crontab
```
例如:
```sh
# 每小时第10分钟ping一次网站
10 * * * * ping www.ip.com 

# 每天12:25ping一次网站
25 12 * * * ping www.ip.com 

```


## 创建文件
```sh
#!/bin/bash

read -p "输入文件路径与文件名:" file_path

if [ ! -f "$file_path" ];then
    touch $file_path
    echo "通过脚本创建该文件" > $file_path
    echo "文件创建完成"
else
    echo "文件已经存在"
fi
```
![](https://cdn.hurra.ltd/img/20200801225712.png)



## 创建文件夹
  
```sh
#!/bin/bash

read -p "输入文件夹路径与文件夹名:" dir_path

if [ ! -f "$dir_path" ];then
    touch $dir_path
    echo "文件夹创建完成"
else
    echo "文件夹已经存在"
fi
```

## 参数说明  
- -e 判断对象是否存在  
- -d 判断目录是否存在
- -f 判断文件是否存在 
- -L 判断符号链接是否存在
- -h 判断软链接是否存在
- -s 判断长度不为0对象是否存在
- -r 判断可读对象是否存在  
- -w 判断可写对象是否存在 
- -x 判断可执行对象是否存在
- -O 判断属于当前用户的对象是否存在 
- -G 判断属于当前用户组的对象是否存在 
