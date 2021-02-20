<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-20 23:32:58
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-20 23:50:24
-->

sizeof 是**单目运算符**，不是函数。与函数 strlen 不同，它的参数可以是数组、指针、类型、对象、函数等


| 参数类型             | 返回值           | 举例                               |
| -------------------- | ---------------- | ---------------------------------- |
| 数组类型             | 数组的总字节     | int b[5]<br>sizeof(b)=20           |
| 具体的字符串或者数值 | 根据具体类型转化 | sizeof(8)= 4;  //自动转化为int类型 |