# 问题

通过 shell 程序将/home/dalao 目录下的 demo.txt 中的

```s
PATH:/usr/bin
```

替换为:

```s
PATH:/usr/bin/python3/bin
```

# 程序

```s
sed -i "s/\<oldStr>/\<newStr>/g" \<filePath>
```

> - g 的意思是全部替换
> - 若字符串中带有路径符号 `/` 则可以用 `#` 做分隔符

示例:

```shell
#!/bin/bash

oldStr='/usr/bin'

newStr='/usr/bin/python3/bin'

sed -i "s#$oldStr#$newStr#g" /home/dalao/demo.txt
```

# 运行

![](http://cdn.hurra.ltd/img/收款码.png)
