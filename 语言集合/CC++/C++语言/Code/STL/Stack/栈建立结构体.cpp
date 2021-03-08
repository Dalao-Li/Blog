#include<iostream>
#include<stack>
typedef int ElemType;

typedef struct {
	ElemType data;
	char alphat;
} Slem;

using namespace std;
int main() {
	stack<Slem> S;
	int n;
	cin>>n;

	for(int i=0; i<n; i++) {
		Slem e;
		cin>>e.data>>e.alphat;
		//ÈëÕ»
		S.push(e);
	}
	while(!S.empty()) {
		//·ÃÎÊÕ»¶¥ÔªËØ
		cout<<S.top().data<<" "<<S.top().alphat<<endl;
		//É¾³ıÕ»¶¥ÔªËØ
		S.pop();
	}
	cout<<endl;
	return 0;
}
