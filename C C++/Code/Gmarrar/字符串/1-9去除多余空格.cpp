#include<stdio.h>
int main() {
	int c;
	int n=0;  //n==1则下次可以出现空格
	while((c=getchar()) != EOF) {
		//如果当前不是空格
		if(c!=' ') {
			//允许下次出现一个空格
			n=1;
			putchar(c);
		}
		//如果是第一次出现的空格
		else if(c==' '&&n==1) {
			putchar(c);
			//下一个不允许是空格
			n=0;
		}
	}
	return 0;
}
