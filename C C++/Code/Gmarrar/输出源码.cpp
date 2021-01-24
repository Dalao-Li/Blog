/*
 * @Descripttion: 
 * @Author: Yuanhao Li
 * @Date: 2019-07-24 23:20:17
 * @LastEditors: Yuanhao Li
 * @LastEditTime: 2019-08-27 20:03:38
 */
#include <stdio.h>
int main() {
	FILE *fp;
	char c;
	fp = fopen(__FILE__,"r");
	do {
		c = getc(fp);
		putchar(c);
	} while(c != EOF);
	fclose(fp);
	return 0;
}
