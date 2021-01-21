```py
from collections import deque

s = deque()

# 入栈
for i in range(5):
    s.append(i)

# 显示栈顶
print(s[-1])

# 栈顶出栈
s.pop()
print(s)

```
