//问题:使用cin输入一个字符串时，遇到空格就停止读取
#include<bits/stdc++.h>
using namespace std;
int main() {
	string str;
	int n;
	cin>>n;
	//用getline来获取一整行内容
	for(int i=0; i<n; i++) {
		getline(cin,str);
		cout<<str<<endl;
	}

	return 0;
}
