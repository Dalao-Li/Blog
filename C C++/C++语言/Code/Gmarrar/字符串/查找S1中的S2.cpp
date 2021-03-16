/*
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:38
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-03-08 16:17:44
 */
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int sum=0;
	string s1,s2;
	cout<<"输入s1:"<<endl;
	cin>>s1;
	cout<<"输入s2:"<<endl;
	cin>>s2;
	for(int i = 0;i<s1.size();i++){
		if(s1.find(s2,i)!=string::npos){
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}

