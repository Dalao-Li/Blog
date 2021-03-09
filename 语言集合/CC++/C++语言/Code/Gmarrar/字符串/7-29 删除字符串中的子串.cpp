/*
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:38
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-03-09 11:33:41
 */
#include<iostream>
#include<string>
using namespace std;
int main() {
	string s1,s2;
	getline(cin,s1);
	cin>>s2;
	int indexS1;
	int lengthS2;
	while(s1.find(s2, 0) != string::npos) {
		//找到字串的位置 
		indexS1 =s1.find(s2,0);
		lengthS2 =s2.size();
		s1.erase(indexS1,lengthS2);
	}

	cout<<s1;
	return 0;
}
