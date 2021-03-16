/*有1、2、3、4个数字,组成多少个互不相同且无重复数字的三位数*/
/*循环的嵌套，输出所有可能情况，在进行筛选*/
#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int i,j,k,n;
	for(i=1; i<5; i++) {
		for(j=1; j<5; j++) {
			for(k=1; k<5; k++) {
				if(i!=j&&i!=k&&j!=k) {
					cout<<i<<j<<k<<endl;
					n++;
				}
			}
		}
	}
	printf("一共%d种情况\n",n);
	return 0;
}
