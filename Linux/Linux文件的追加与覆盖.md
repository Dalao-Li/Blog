# 一、实验目的
通过echo命令实现对文件进行追加内容与覆盖内容

# 二、实验环境
WSL

# 三、实验过程

## 3.1 echo命令

新建文件demo,原本内容为空
```
touch demo
```

1. 对文件进行内容的追加
```
echo "文本内容" >> 文件名
```

追加内容
```
echo "追加内容1" >> demo

echo "追加内容2" >> demo
```
![](http://cdn.hurra.ltd/img/20200619212430.png)

2. 对文件进行内容的覆盖
```
echo "文本内容" > 文件名
```

覆盖内容
```
echo "覆盖内容" > demo
```
![](http://cdn.hurra.ltd/img/20200619212618.png)