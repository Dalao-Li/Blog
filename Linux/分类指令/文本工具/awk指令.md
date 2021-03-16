<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-10 11:23:08
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-03-16 15:21:02
-->
## 概念

awk是一个强大的文本分析工具,相对于grep的查找,sed的编辑,awk在其对数据分析并生成报告时显得尤为强大.简单来说awk就是把文件逐行的读入,以空格为默认分隔符将每行切片,切开的部分再进行各种分析处理

```sh
awk '{pattern + action}' {filenames}
```
| 参数    | 含义                                   |
| ------- | -------------------------------------- |
| pattern | awk 在数据中查找的内容                 |
| action  | 在找到匹配内容时执行的命令             |
| {}      | 用于根据特定的模式对一系列指令进行分组 |

- 示例

```sh
last -n 5
```
![](https://cdn.hurra.ltd/img/20210310112632.png)

若仅想查看登录的用户名,则可使用

```sh
last -n 5 | awk '{print $1}'
```

![](https://cdn.hurra.ltd/img/20210310112806.png)

## awk工作流程

读入有'\n'换行符分割的一条记录,将记录按指定的域分隔符划分域,填充域,$0则表示所有域,$1表示第一个域,$n表示第n个域.默认域分隔符是"空白键" 或 "[tab]键".