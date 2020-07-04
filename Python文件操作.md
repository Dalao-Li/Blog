# 一、实验目的
掌握Python文件操作

# 二、实验环境

> - 系统环境 : Windows 10 2004
> - IDE : Pycharm
> - Python: Python 3.8

# 三、文件操作

## 问题 : 文件路径问题
在**Windows**中因为 " \ "被当成了转义字符，会导致路径找不到 

例如 : C:\Users\xxx\Desktop\x.txt需改写为以下三种形式之一

> - r'C:\Users\xxx\Desktop\x.txt'  
>
> - 'C:\\Users\xxx\Desktop\\x.txt'  
>
> - 'C:/Users/xxx/Desktop/x.txt'

## 3.1 创建文件

### 3.1.1 当前项目路径
```py
import os

def create_file(file_name):
    # 获取当前路径
    path = os.getcwd()
    # 获得文件的路径
    file_path = os.path.join(path,file_name)
    # 如果该文件存在
    if os.path.exists(file_path):
        print('该文件已经存在')
        return
    # 创建文件
    f = open(file_path,'w',encoding='utf-8')
    if os.path.exists(file_path):
        f.close()
        print('%s 文件创建成功'%file_name)
        return
    print('%s 文件创建失败' % file_name)

```
![](http://cdn.hurra.ltd/img/20200628230114.png)

### 3.1.2 指定路径
仅需将3.1.1中的path变量的值换为指定的路径值即可,需注意文件路径的问题

## 3.2 修改文件

### 3.2.1 写入内容

```py
def write_file(file_name):
    # 获取当前路径
    path = os.getcwd()
    # 获得文件的路径
    file_path = os.path.join(path, file_name)
    with open(file_path, 'w',encoding='utf-8') as f:
        data = input('输入内容:')
        f.write(data)
    f.close()
```
![](http://cdn.hurra.ltd/img/20200628231431.png)

### 3.2.2 追加内容
```py
def add_file_data(file_name):
    # 获取当前路径
    path = os.getcwd()
    # 获得文件的路径
    file_path = os.path.join(path, file_name)

    with open(file_path, 'a', encoding='utf-8') as f:
        data = input('输入追加的内容:')
        f.write('%s\r\n'%data)
    f.close()
```
> - with open中的参数a代表追加内容
> - '\r\n'实现换行

![](http://cdn.hurra.ltd/img/20200628232636.png)

### 3.2.3 覆盖内容
与3.2.1写入文件内容的代码一致

### 3.2.4 重命名
```py
def rename_file(old_name,new_name):
    # 获取当前路径
    path = os.getcwd()
    # 获得文件的路径
    old_path = os.path.join(path, old_name)
    new_path = os.path.join(path, new_name)
    os.rename(old_path, new_path)
```
![](http://cdn.hurra.ltd/img/20200628233529.png)

## 3.3 读取文件
### 3.3.1 整体读取
```py
def read_file(file_name):
    # 获取当前路径
    path = os.getcwd()
    # 获得文件的路径
    file_path = os.path.join(path, file_name)
    with open(file_path, 'r', encoding='utf-8') as f:
        data = f.read()
        print(data)
    f.close()
```
![](http://cdn.hurra.ltd/img/20200628234541.png)

### 3.3.2 逐行读取
修改3.3.1代码为
```py
with open(file_path, 'r', encoding='utf-8') as f:
    data = f.readlines()
    for i in data:
        print(i)
```
## 3.4 移动/复制文件
移动文件
```py
import os
import shutil

def move_file(source_path, target_path):
    if not os.path.isfile(source_path):
        print('待移动文件不存在')
        return
    file_path, file_name = os.path.split(target_path)
    if not os.path.exists(file_path):
        os.makedirs(file_path)
    shutil.move(source_path, target_path)
    print('移动成功')

if __name__ == '__main__':
    source_path = 'D:/Code/Python/File/newFiles.txt'
    target_path = 'D:/Move/file.txt'
    move_file(source_path, target_path)
```
![](http://cdn.hurra.ltd/img/20200629001956.png)

复制文件  
将shutil.move()换为shutil.copyfile()即可
```py
shutil.copyfile(source_path, target_path)
```

## 3.5 删除文件
```py
def delete_file(source_path):
    if  not os.path.exists(source_path):
        print('待删除文件不存在')
        return
    os.remove(source_path)
```


# 四、文件夹操作

## 4.1 读取

### 4.1.1 显示文件夹中所有文件
```py
def display_all_files(folder_path):
    for i in os.listdir(folder_path):
        path = os.path.join(folder_path, i)
        # 如果是文件则显示
        if os.path.isfile(path):
            print(path)
```
![](http://cdn.hurra.ltd/img/20200629221116.png)

### 4.1.2 递归显示文件夹中所有文件
```py
def display_all_folders(folder_path):
    for i in os.listdir(folder_path):
        path = os.path.join(folder_path, i)
        # 如果该对象是文件夹
        if os.path.isdir(path):
            print("--folder : %s"%i)
            display_all_files(path)
```
![](http://cdn.hurra.ltd/img/20200629221628.png)



![](http://cdn.hurra.ltd/img/赞赏码.png)
