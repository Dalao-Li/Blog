/*
unique的作用就是"去除"数组中重复的元素，
但实际上并没有真正的把重复的元素删去了
，而是把重复的元素全部放在了数组末尾
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[10] = { 0, 7, 7, 6, 1, 1, 5, 5, 8, 9 };
	int n = unique(a, a + 10) - a;
	cout << n << endl;  //n==7
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";  //0 7 6 1 5 8 9 5 8 9
	for(int i=0; i<n; i++) {
		cout<<a[i]<<" ";      //0 7 6 1 5 8 9
	}
	return 0;
}
