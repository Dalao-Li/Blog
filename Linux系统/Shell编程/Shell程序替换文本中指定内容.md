<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:34
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-19 19:16:39
-->
# 问题

通过 shell 程序将/home/dalao 目录下的 demo.txt 中的

```sh
PATH:/usr/bin
```

替换为:

```sh
PATH:/usr/bin/python3/bin
```

# 程序

```sh
sed -i "s/\<oldStr>/\<newStr>/g" \<filePath>
```

> - g : 全部替换
> - 若字符串中带有路径符号 `/` 则可以用 `#` 做分隔符

示例:

```sh
#!/bin/bash

oldStr='/usr/bin'

newStr='/usr/bin/python3/bin'

sed -i "s#$oldStr#$newStr#g" /home/dalao/demo.txt
```

# 运行

![](https://cdn.hurra.ltd/img/收款码.png)
