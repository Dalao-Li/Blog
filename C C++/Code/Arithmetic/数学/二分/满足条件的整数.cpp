/*
假设a、b、c均为整数，且满足a，b，c 大于1，
并且小于等于100，找出所有符合条件整数组。
注意：
1）为避免重复输出，要求a<=b；
2）加号和等号左右各有一个空格，除此之外无多余空格。
*/
#include<stdio.h>
int main() {
	int a,b,c;
	for(a=2; a<=100; a++) {
		for(b=a; b<=100; b++) {
			int l=b,r=100;
			while(r-1>=l) {
				c=(l+r)/2;
				if(a*a+b*b==c*c) {
					printf("%d*%d + %d*%d = %d*%d\n",a,a,b,b,c,c);
					break;
				} else if(a*a+b*b<c*c) {
					r=c;
				} else {
					l=c+1;
				}
			}
		}
	}
	return 0;
}

