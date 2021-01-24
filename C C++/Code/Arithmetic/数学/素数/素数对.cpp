/*
两个相差为2的素数称为素数对，如5和7，17和19
等，本题目要求找出所有两个数均不大于n的素数对。
输入
一个正整数n。1 <= n <= 10000。
输出
所有小于等于n的素数对。每对素数对输出一行，中
间用单个空格隔开。若没有找到任何素数对，输出empty。
*/
#include<iostream>
#include<math.h>
using namespace std;
int isPrime(int n) {
	int i;
	for(i=2; i<=sqrt(n); i++) {
		if(n%i==0) {
			return 0;
		}
	}
	return 1;
}
int main() {
	int n,i;
	bool a=false;
	cin>>n;
	for(i=2; i<=n-2; i++) {
		if(isPrime(i)&&isPrime(i+2)){
			cout<<i<<" "<<i+2<<endl;
			a=true;
		}
	}
	if(a=false){
		cout<<"empty"<<endl;
	}
	return 0;
}
