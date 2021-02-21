/*给定10个整数的序列，重新排序。排序要求:
1.奇数在前，偶数在后；2.奇数从大到小排序；
3.偶数从小到大排序。
*/
#include<iostream>
using namespace std;
int main() {
	int n,i,b[101]= {0};
	for(i=0; i<10; i++) {
		cin>>n;
		//b[n]的值为该数字出现的次数 
		b[n]++;
	}
	for(i=99; i>=1; i-=2) {
		if(b[i]) {
			//当出现重复数字时 
			while(b[i]--) {
				cout<<i<<" ";
			}
		}
	}
	for(i=0; i<=100; i+=2) {
		if(b[i]) {
			while(b[i]--) {
				cout<<i<<" ";
			}
		}
	}
	cout<<endl;
	return 0;
}
