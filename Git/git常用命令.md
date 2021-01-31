<!--
 * @Description: 
 * @Version: 1.0
 * @Autor: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-29 11:33:55
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-01-30 13:32:08
-->

# add

# commit

## 合并commit



# push

git push 命用于从将本地的分支版本上传到远程并合并

> git push <远程主机名> <本地分支名>:<远程分支名>


## 上传本地分支到远程分支

```sh
git checkout -b <分支>

#建立本地到上游（远端）仓的链接 --这样代码才能提交上去
git branch --set-upstream-to=origin/<分支>

git push origin <dev>
```
