#include<stdio.h>
struct Date {
	int year;
	int month;
	int day;
};
int main() {
	struct Date num;
	printf("请输入年月日:\n");
	scanf("%d%d%d",&num.year ,&num.month ,&num.day );
	int a[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
	if((num.day <=31)&&(num.month<=12)) {
		for(int i=0; i<num.month-1; i++) {
			num.day+=a[i];
		}
		if((num.year %4==0&&num.year %100!=0)||(num.year %400==0)&&(num.month>2)) {
			printf("这是%d年的第%d天\n",num.year ,num.day+1);
		} else {
			printf("这是%d年的第%d天\n",num.year,num.day);
		}
	} else {
		printf("月份或日期输入错误!\n");
	}
	return 0;

}
