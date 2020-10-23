# 问题

通过shell程序将/home/dalao目录下的demo.txt中的
```s
....

PATH:/usr/bin

....
```
替换为:PATH:/usr/bin/python3/bin

# 程序

```s
sed -i "s/\<oldStr>/\<newStr>/g" \<filePath>
```
> - g的意思是全部替换
> - 若字符串中带有路径符号 `/` 则可以用 `#` 做分隔符

示例:
```shell
#!/bin/bash

oldStr='/usr/bin'

newStr='/usr/bin/python3/bin'

sed -i "s#$oldStr#$newStr#g" /home/dalao/demo.txt
```

# 运行



![](http://cdn.hurra.ltd/img/赞赏码.png)
