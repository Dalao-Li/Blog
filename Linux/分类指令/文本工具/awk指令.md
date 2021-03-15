<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-03-10 11:23:08
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-03-10 11:28:22
-->


awk是一个强大的文本分析工具,相对于grep的查找,sed的编辑,awk在其对数据分析并生成报告时,显得尤为强大.简单来说awk就是把文件逐行的读入,以空格为默认分隔符将每行切片,切开的部分再进行各种分析处理


```sh
awk '{pattern + action}' {filenames}
```

尽管操作可能会很复杂,但语法总是这样,其中 pattern 表示 AWK 在数据中查找的内容,而 action 是在找到匹配内容时所执行的一系列命令.花括号({})不需要在程序中始终出现,但它们用于根据特定的模式对一系列指令进行分组. pattern就是要表示的正则表达式,用斜杠括起来

## 举例

last -n 5 输出如下

![](https://cdn.hurra.ltd/img/20210310112632.png)

此时若仅想查看登录的用户名,则可使用

```sh
last -n 5 | awk '{print $1}'
```

![](https://cdn.hurra.ltd/img/20210310112806.png)

awk工作流程是这样的:读入有'\n'换行符分割的一条记录,然后将记录按指定的域分隔符划分域,填充域,$0则表示所有域,$1表示第一个域,$n表示第n个域.默认域分隔符是"空白键" 或 "[tab]键",所以$1表示登录用户,$3表示登录用户ip,以此类推.