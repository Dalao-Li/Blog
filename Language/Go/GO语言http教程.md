# Web Hello World

```go
package main

import (
	"fmt"
	"net/http"
)

func main() {
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprintln(w, "<h1>HELLO WORLD!</h1>")
	})

	http.ListenAndServe(":8888", nil)
}

```

![](https://cdn.hurra.ltd/img/20210110181933.png)

# 并发 Hello World

```go
package main

import (
	"fmt"
	"time"
)

func main() {
	for i := 0; i < 5; i++ {
		go printHello(i)
	}
	time.Sleep(time.Millisecond)
}

func printHello(i int) {
	fmt.Printf("Hello World from goroutine %d!\n", i)
}

```

![](https://cdn.hurra.ltd/img/20210110194117.png)
