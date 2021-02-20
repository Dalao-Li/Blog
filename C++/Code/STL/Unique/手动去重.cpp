/*
从数组中下标为0的元素开始向后比较，遇到重复元素忽略，遇到不同元素，
就把这个不同元素存入 t 数组，同时再从刚才那个不同元素下标处开始继
续向后比较，以此类推。
*/ 
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int i = 0, j = 0;
	const int len = 10;  //数组的长度
	int p[len] = { 0, 7, 7, 6, 1, 1, 5, 5, 8, 9 };
	int t[len] = {0};  //储存排序后的数组
	int counter = 1;  //记录t数组中存了多少元素

	sort(p, p + len);   //排序

	t[0] = p[0];
	//去重
	while (i < len) {
		if (p[i] != p[++j]) {
			i = j;
			t[counter++] = p[i];  //不重复的存入t数组，然后counter加一
		}
	}

	//输出
	for (i = 0; i < (counter-1); i++)  //counter-1就是t数组中存的元素个数
		cout << t[i] << " ";  //0 1 5 6 7 8 9

	return 0;
}
