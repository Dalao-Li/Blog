# 数组与切片

```go
package main

import "fmt"

func main() {
	var a []int
    b := []int{2, 3, 4}

	//单个添加
    a = append(a, 1)

	//添加数组
	a = append(a, b...)
	for _, v := range a {
		fmt.Println(v)
	}
}
```

# 排序

```go
package main

import (
	"fmt"
	"sort"
)

func main() {
	a := []int{3, 4, 5, 1, 2}
	sort.Ints(a)
	for _, v := range a {
		fmt.Println(v)
	}
}
```

![](https://cdn.hurra.ltd/img/20210110230203.png)

# 通道
