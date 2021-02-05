新建文件 demo,原本内容为空

```
touch demo
```

## 1. 内容追加

## 1.1 单行追加

> echo <文本内容> `>>` <文件名>

追加内容

```
echo "追加内容1" >> demo

echo "追加内容2" >> demo
```

![](https://cdn.hurra.ltd/img/20200619212430.png)

## 1.2 多行追加

> echo `-e` .... 输出换行符

```shell
echo -e "第一行内容\n第二行内容" >> <文件名>
```

## 2. 内容覆盖

```shell
echo "文本内容" > 文件名
```

覆盖内容

```shell
echo "覆盖内容" > demo
```

![](https://cdn.hurra.ltd/img/20200619212618.png)
