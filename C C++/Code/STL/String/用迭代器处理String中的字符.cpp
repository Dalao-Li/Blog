#include<bits/stdc++.h>
using namespace std;
int main(){
	string str="Hello World!";
	//使用const_iterator沥遍字符串,这时访问元素时是能读不能写 
	for(string::const_iterator it = str.begin();it!=str.end();++it){
		cout<<*it;
	}
	cout<<endl;
	//用iterator沥遍字符串，并将每个字符换为a,并输出 
	for(string::iterator it = str.begin();it!=str.end();++it){
		*it='a';
		cout<<*it;
	} 
	return 0;
} 
