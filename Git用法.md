本地新建文件夹demo,进入

## 建立本地仓库

> - 初始化一个文件夹为本地仓库

```
git init
```
![](http://cdn.hurra.ltd/img/20200717225442.png)

![](http://cdn.hurra.ltd/img/20200717225520.png)


## 查看状态

```
git status
```
![](http://cdn.hurra.ltd/img/20200717225623.png)

新建文件new.txt,写入内容"master第一次提交"

![](http://cdn.hurra.ltd/img/20200717225752.png)

再次git status

![](http://cdn.hurra.ltd/img/20200717225908.png)

## 添加到暂存区

```
git add .
```
> - 此处 `.` 指所有文件,也可具体指定文件

![](http://cdn.hurra.ltd/img/20200717230210.png)

## 撤销暂存区修改

例如新建文件了b.txt,并执行了git add . 然后想撤回这次操作,可执行

```shell
# 撤回暂存区所有文件
git reset HEAD

# 撤回暂存区指定的文件
git reset HEAD <filename>
```

![](http://cdn.hurra.ltd/img/20200717231751.png)

## 提交操作

> - 将暂存区里的改动给提交到本地的版本库

```
git commit -m "提交的注释信息"
```
![](http://cdn.hurra.ltd/img/20200717230921.png)

## 查看提交记录

```
git log
```
![](http://cdn.hurra.ltd/img/20200717232555.png)

## 撤销提交

修改new.txt文件内容,并commit

![](http://cdn.hurra.ltd/img/20200717232121.png)

![](http://cdn.hurra.ltd/img/20200717232223.png)

- 现在回到上一次提交,可执行
```shell
git reset --hard HEAD^
```
> - `删除工作空间改动代码，撤销commit,撤销git add .` 

![](http://cdn.hurra.ltd/img/20200717233342.png)

![](http://cdn.hurra.ltd/img/20200717233417.png)

---

- 若想回到上一次提交,且改动的代码不变,可执行
```shell
git reset --soft HEAD^
```
> - `不删除工作空间改动代码，撤销commit,不撤销git add . `

![](http://cdn.hurra.ltd/img/20200717233725.png)

可发现commit已经撤回

![](http://cdn.hurra.ltd/img/20200717233745.png)

并且改动的代码未变

![](http://cdn.hurra.ltd/img/20200717233820.png)

---

- 若想回退到指定commit,可执行
```shell
git reset --<soft/hard> <commit id>
```

## 查看分支
> - 所有分支
```shell
git branch -a
```

> - 当前使用分支
```shell
git branch
```
![](http://cdn.hurra.ltd/img/20200718111415.png)

## 建立分支

```shell
git branch <branch name>
```
建立名为first的分支

![](http://cdn.hurra.ltd/img/20200718111645.png)

## 切换分支

```shell
git checkout <branch name>
```
切换到first分支

![](http://cdn.hurra.ltd/img/20200718111734.png)

> - 创建新分支并切换到新分支
```shell
git checkout -b <branch name>
```
创建second分支并切换

![](http://cdn.hurra.ltd/img/20200718112028.png)

## 删除分支
```shell
git branch -d <branch name>
```
删除second分支

![](http://cdn.hurra.ltd/img/20200718112414.png)

![](http://cdn.hurra.ltd/img/赞赏码.png)
