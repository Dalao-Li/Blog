<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-10 12:22:12
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-10 13:55:41
-->
# C++异常处理问题


## 试例
例:规定输入一个字符串,若其为数字且小于10000且为偶数则为合法状态,其他情况为非法状态,试写一程序对输入情况进行判定,若字符串非法则显示其问题.

```c
/*
 * @Description: C++异常处理实例
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-02-09 16:08:16
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-02-09 16:08:16
 */

#include<iostream>
#include<cmath>
using namespace std;


bool judge(string s){
	if(s.size() > 5){
		throw "长度超长";
	}
	int sum = 0;
	for(int i = 0 ,size = s.size(); i < size;i++){
		int v = s[i] - '0';
		if(v < 0 || v >9){
			throw "该字符串非数字";
		}
		sum += (v*pow(10,size - i - 1));
	} 
	if(sum > 10000){
		throw "数字值大于10000";
	}
	if(sum & 1){
		throw "该数字不为偶数";
	} 
	return true; 
}

int main(){
	string s;
	cin >> s;
    try{
        if (judge(s)){
            cout << s << "是一个合法的字符串" << endl;
        }
    }catch (const char *msg){
        cout << s << "不是一个合法的字符串,错误原因:";
        cerr << msg << endl;
    }
} 
```

## 运行结果

![](https://cdn.hurra.ltd/img/20210210135539.png)