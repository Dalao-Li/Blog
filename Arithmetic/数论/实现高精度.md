## 大数加法

> 利用数组**逆序**存储两个数字,来求和与进位  
- 无进位情况

a = "12345" , b = "789"

![](https://cdn.hurra.ltd/img/20200620162302.png)
求和结果为 13134

- 有进位情况
  
a = "99769" , b = "231"
![](https://cdn.hurra.ltd/img/20200620162957.png)



```c
//大数加法
string addNum(string a, string b) {
    int xa[500] = {};
    int xb[500] = {};
    int tot[500] = {};
    for (int i = 0, size = a.size(); i < size; i++) {
        //逆序存储a
        xa[i] = a[size - i - 1] - '0';
    }
    for (int i = 0, size = b.size(); i < size; i++) {
        xb[i] = b[size - i - 1] - '0';
    }
    int len = max(a.size(), b.size());
    for (int i = 0; i < len; i++) {
        tot[i] += (xa[i] + xb[i]);
        //处理进位
        if (tot[i] > 9) {
            tot[i + 1] += 1;
            tot[i] -= 10;
        }
    }
    //保存结果
    string res = "";
    //判断求和结果有无进位的情况
    if (tot[len]) {
        res += (tot[len] + '0');
    }
    for (int i = len - 1; i >= 0; i--) {
        res += (tot[i] + '0');
    }
    return res;
}
```

运行结果
![](https://cdn.hurra.ltd/img/20200620163531.png)

## 大数减法

- 非负情况  
a = "99729" , b = "99231"

![](https://cdn.hurra.ltd/img/20200620164104.png)

运算时确保被减数大于减数,最后判断是否为负数

```C
//大数减法,a为被减数,b为减数
string subNum(string a, string b) {
    int xa[500] = {};
    int xb[500] = {};
    int tot[500] = {};
    for (int i = 0, size = a.size(); i < size; i++) {
        //逆序存储a
        xa[i] = a[size - i - 1] - '0';
    }
    for (int i = 0, size = b.size(); i < size; i++) {
        xb[i] = b[size - i - 1] - '0';
    }
    int len = max(a.size(), b.size());
    for (int i = 0; i < len; i++) {
        if(xa[i] < xb[i]){
            tot[i] -= 1;
            xa[i] += 10;
        }
        tot[i] += (xa[i] - xb[i]);
    }
    string res = "";
    //找到第一个非0的位置,消除前导0
    int index = len - 1;
    while(index >= 0 && tot[index] == 0){
        index--;
    }
    //处理相减结果为0的情况
    if(index < 0 ){
        index = 0;
    }
    for(int i = index ; i>=0 ;i--){
        res += (tot[i] + '0');
    }
    //处理负数情况
    if(a.size() < b.size()){
        res += '-';
    }
    return res;
}
```

运行结果

![](https://cdn.hurra.ltd/img/20200620192640.png)
