<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:34
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-10 20:53:36
-->
## 字符型 char

`严格来说,char 其实也是整数类型（int）,因为 char 类型储存的实际上是整数,而不是字符`

## 说明

```c
char a = 'A';

printf("%c",a);
```

对于变量 a 来说,其实它存储的是一个整数 65,即 A 的 ASCII 码值

## 字符数组 char []

```c
char a[] = 'Hello World';

printf("%s",a);
```

- 常用函数

  | 函数     | 说明           |
  | -------- | -------------- |
  | strlen() | 求字符数组长度 |

## 字符指针 char \*

char *s 定义了一个 char 型指针,它只知道所指向的内存单元,并不知道这个内存单元有多大.所以当 char *s = "hello";后,不能使用 s[0]='a'这样的语句进行赋值

- 定义一个 char \* 后不能对其进行下标操作

- char []可以修改其中的字符,char \*不能修改其中的字符

- char \*可以通过加减、自加减改变其值;char []不可以

## 字符与字符串

- `'a'` 和 `"a"` 的区别: 'a' 为字符, "a" 为字符串；单引号只能定义一个字符,双引号可以定义多个字符,即字符串.
