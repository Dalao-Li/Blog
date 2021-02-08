/*求两个数字的最大公约数*/
#include<iostream>
using namespace std;
int number_value(int m,int n) {
	int r;
	while((r=m%n)!=0) {            /*若两个数相除的余数r不为零(例如15%9=6)*/
		m=n;                       /*m=9,n=6.r=3...m=6,n=3..r=0*/
		n=r;
	}
	return n;                      /*n=3*/
}
int main() {
	int a,b;
	cin>>a>>b;
	printf("最大公约数为:%d\n",number_value(a,b));
	return 0;
}

