#include<iostream>
#include<stack>
using namespace std;
int main(){
	stack<int> s;
	int n,item;
	cin>>n;   
	for(int i=0;i<n;i++){
		cin>>item;
		//ÈëÕ»  
		s.push(item);
	}
	while(!s.empty()){
		//·ÃÎÊÕ»¶¥ÔªËØ 
		cout<<s.top()<<" ";
		//É¾³ıÕ»¶¥ÔªËØ 
		s.pop();
	}
	cout<<endl;
	return 0;
} 
