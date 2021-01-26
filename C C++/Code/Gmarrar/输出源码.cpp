/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2019-07-24 23:20:17
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-01-26 10:50:18
 */

#include <stdio.h>
int main()
{
	FILE *fp;
	char c;
	fp = fopen(__FILE__, "r");
	do
	{
		c = getc(fp);
		putchar(c);
	} while (c != EOF);
	fclose(fp);
	return 0;
}
