#include<iostream>
#include<fstream>
#include<ostream>
#include<list>
using namespace std;
int main(){
	//ofstream outfile("a.txt");
	list<int> linklist;
	int item,n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>item;
		linklist.push_back(item);
		//outfile << item<<endl;
	}
	//非迭代器遍历 
	while(!linklist.empty()){
		//返回首元素引用 
		cout<<linklist.front()<<endl;
		//删除首元素 
		linklist.pop_front();
	}
	return 0;
} 
