//输入十个数（0-1000）输出其中的不同数字
#include <stdio.h>
#define M 1000
#define N 3
int main(void) {
	int a[N],i;
	int b[M] = {0};//？为什么这里只能是0 
	for(i = 0; i < N; i++) {
		scanf("%d",&a[i]);
		b[a[i]]++;               //b[i]的下标即输入的数字
	}
	for(i = 0; i < M ; i++) {
		if(b[i]!=0) {
			printf("%d ",i);

		}
	}
}
