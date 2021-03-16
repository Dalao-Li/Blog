//十阶楼梯,要么走一步要么走两步,一共几种方法 
#include<iostream>
using namespace std;

int main(){
    int a = 1,b =2;
    int temp;
	for(int i = 3;i<=10;i++){
		temp = a+b;
		cout<<"temp="<<temp<<" "<<"a="<<a<<" "<<"b="<<b<<endl;
		a=b;
		b= temp;
	}
	cout<<temp<<endl;
	return 0;
}
