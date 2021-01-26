/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:35
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-01-26 10:44:10
 */

#include <iostream>
using namespace std;
int main()
{
	int l = 0;
	int r = 1000;
	int n = 0;
	int goal = 1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		cout << mid << endl;
		if (mid == goal)
		{
			break;
		}
		else if (mid < goal)
		{
			l = mid + 1;
			n++;
		}
		else if (mid > goal)
		{
			r = mid + 1;
			n++;
		}
	}
	cout << n << endl;
}
