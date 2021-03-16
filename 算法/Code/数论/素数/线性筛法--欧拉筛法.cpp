#include<iostream>
#include<cstring>
#include<ctime>
#define MAX 1001
using namespace std;
int main() {
	
	int a[MAX];
	int tot=0;
	bool b[MAX];
	//先开始假设所有数都是素数
	memset(b,true,sizeof(b));
	for(int i=2; i<MAX; i++) {
		//如果这个数是素数的话
		if(b[i]==true) {
			//将这个素数保存到a[]中
			a[tot++]=i;
		}
		//因为a[j]是素数,则它乘上i之后的数一定不是素数
		for(int j=0; j<tot&&i*a[j]<MAX; j++) {
			//将其标记为false
			b[i*a[j]]=false;
			//当i是a[j]的整数倍时跳出循环.因为i=a[j]*某个数,则i*a[j+1]=a[j]*某个数*a[j+1].
			//而a[j]必定小于a[j+1],所以 i*a[j+1]必被a[j]*某个数筛掉，无需再次循环
			if(i%a[j]==0) {
				break;
			}
		}
	}
	return 0;
}
