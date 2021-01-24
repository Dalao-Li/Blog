#include<iostream>
#include<stack>
typedef double ElemType;
using namespace std;
int main() {
	stack<char> s;
	stack<ElemType> e;
	string str;
	getline(cin,str)
	for(int i=str.size()-1; i>=0; i--) {
		if(str[i]>'0'&&str[i]<='9') {
			e.push(str[i]-'0');
		} else {
			s.push(str[i]);
		}
	}
	while(!s.empty()&&e.size()!=1) {
		ElemType first = e.top();
		e.pop();
		ElemType second = e.top();
		e.pop();
		char mid = s.top();
		s.pop();
		if(mid=='+') {
			e.push(first+second);
		} else if(mid = '-') {
			e.push(first+second);
		} else if(mid = '*') {
			e.push(first*second);
		} else if(mid = '/') {
			e.push(first/second);
		}
	}
	cout<<e.top()<<endl;
}
