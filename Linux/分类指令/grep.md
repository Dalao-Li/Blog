<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-10 17:35:54
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-03-11 08:57:36
-->

## grep指令参数

| 参数 | 说明                                   |
| ---- | -------------------------------------- |
| c    | 只输出匹配行的计数                     |
| i    | 匹配内容不区分大小写                   |
| h    | 查询多文件时不显示文件名               |
| l    | 查询多文件时只输出包含匹配字符的文件名 |
| n    | 显示匹配行及行号                       |
| s    | 不显示不存在或无匹配文本的错误信息     |
| v    | 显示不包含匹配文本的所有行             |


## 匹配

- 单查询

```sh
grep pattern filepath
```
 
查询3月10日16点30时间段内的ssh登录情况

```sh
grep -n 'Mar 10 16:3' /var/log/secure
```
![](https://cdn.hurra.ltd/img/20210310173920.png)

- 与查询

```sh
grep 'pattern1' filepath | grep 'pattern2'
```
查询3月10日16点30时间段内的ssh登录成功的情况

```sh
grep 'Mar 10 16:3' /var/log/secure | grep Accepted
```

![](https://cdn.hurra.ltd/img/20210310175209.png)

- 或查询

```sh
# 方法1
grep 'pattern1\|pattern2' filepath

# 方法2
grep -E 'pattern1|pattern2' filepath
```

- 非查询

```sh
grep -v pattern filepath
```