/*
找出正整数 M 和 N 之间（N 不小于 M）的所有真素数。
真素数的定义：如果一个正整数 P 为素数，且其反序也
为素数，那么 P 就为真素数。例如，11，13 均为真素数
，因为11的反序还是为11，13 的反序为 31 也为素数。
*/
#include<iostream>
#include<math.h>
using namespace std;
bool isPrime(int n) {
	int i;
	for(i=2; i<=sqrt(n); i++) {
		if(n%i==0) {
			return false;
		}
	}
	return true;
}

int inverNum(int n) {
	int num=0;
	while(n) {
		num=num*10+n%10;
		n/=10;
	}
	return num;
}

int main() {
	int M,N,i,a[100001],j=0;
	bool b=false;
	cin>>M>>N;
	for(i=M; i<=N; i++) {
		if(isPrime(i)&&isPrime(inverNum(i))) {
			b=true;
			a[j]=i;
			j+=1;
		}
	}
	for(i=0; i<j-1; i++) {
		cout<<a[i]<<",";
	}
	cout<<a[j-1]<<endl;

	if(b=false) {
		cout<<"No"<<endl;
	}
	return 0;
}
