# Ndarray 对象

N 维数组对象 ndarray

- 创建 ndarray

```py
numpy.array(object, dtype = None, copy = True, order = None, subok = False, ndmin = 0)
```

参数说明:

| 名称   | 描述                                                    |
| ------ | ------------------------------------------------------- | ---- |
| object | 数组或嵌套的数列                                        |
| dtype  | 数组元素的数据类型,可选                                 |
| copy   | 对象是否需要复制,可选                                   |
| order  | 创建数组的样式,C 为行方向,F 为列方向,A 为任意方向(默认) |
| subok  | 默认返回一个与基类类型一致的                            | 数组 |
| ndmin  | 指定生成数组的最小维度                                  |

例:

- 单维度

```py
import numpy as np
a = np.array([1,2,3,4,5,6])
print(a)
```

> [1 2 3 4 5 6]

- 多维度

```py
import numpy as np
a = np.array([[1, 2, 3],[4, 5, 6]])
print(a)
```

> [[1 2 3]  
[4 5 6]]

- 最小维度

```py
import numpy as np
a = np.array([1, 2, 3, 4, 5], ndmin =  2)
print (a)
```

> [[1 2 3 4 5]]

- dtype 参数

```py
import numpy as np
a = np.array([1,  2,  3], dtype = complex)
print (a)
```

> [1.+0.j 2.+0.j 3.+0.j]
