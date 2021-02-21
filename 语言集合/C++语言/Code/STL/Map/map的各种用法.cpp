#include<iostream>
#include<map>
using namespace std;
int main() {
	//map的输入与输出 
	int temp;
	string str;
	map<int,string> m1;
	//1---one  2--two  3--three
	for(int i=0; i<3; i++) {
		//输入键--值,会按照键的顺序自动排序 
		cin>>temp>>str;
		m1.insert(make_pair(temp,str));
	}
	
	cout<<"输入m1中各键---值"<<endl;
	for(map<int,string>::iterator it=m1.begin(); it!=m1.end(); it++) {
		cout<<it->first<<"------"<<it->second<<endl;
	}
	
	//map的查找与读取
	
	//查找该值是否存在，可以使用函数count(k),返回的是k出现的次数 
	if(m1.count(1)){
		cout<<"yes"<<endl;
	}
	
	//取得取得key对应的值，可以使用函数find(k) 
	map<int,string>::iterator it;
	it=m1.find(1);
	if(it!=m1.end()){
		cout<<"1对应的值为:"<<it->second<<endl;
	}
	
	//map中删除元素
	//删除的是m中键为k的元素
	m1.erase(1);
	for(map<int,string>::iterator it=m1.begin(); it!=m1.end(); it++) {
		cout<<it->first<<"------"<<it->second<<endl;
	}
	return 0;
}
