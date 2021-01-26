<!--
 * @Description: 
 * @Version: 
 * @Autor: Li Yuanhao
 * @Email: dalao-li@163.com
 * @QQ: 1061299112
 * @Date: 2021-01-25 23:07:05
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-01-25 23:11:07
-->

# 场景


在使用git时,会出现将一个仓库同事push到多个托管远端,如防止git托管不稳定,起备份作用


假设想要增加2个远程库地址,分别为
```sh
https://github.com/Dalao-Li/Bolg

https://code.aliyun.com/dalao/Bolg
```

解决方法
```sh
git remote add origin https://github.com/Dalao-Li/Bolg.git


# 添加第二个地址
git remote set-url --add origin https://code.aliyun.com/dalao/Bolg
```

![](http://cdn.hurra.ltd/img/20210125231032.png)

以后只要使用`git push origin master` 就可以一次性push到2各库里面