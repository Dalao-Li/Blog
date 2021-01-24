#include<bits/stdc++.h>
using namespace std;
class Student {
	public:
		Student() {}
		void inputValue() {
			cin>>name>>num;
		}
		void ouputValue() {
			cout<<name<<" "<<num<<endl;
		}
		~Student() {}
	private:
		string name;
		int  num;
};

void inputValue(vector< Student> &v) {
	class Student stu;
	int temp;
	cout<<"请输入想要增加的人数:";
	cin>>temp;
	for(int i=0; i<temp; i++) {
		cout<<"请输入第"<<i+1<<"个人的信息";
		stu.inputValue();
		v.push_back(stu);
	}
}

void ouputValue(vector< Student> &v) {
	for(vector< Student>::iterator it=v.begin(); it!=v.end(); it++) {
		it->ouputValue();
	}
}


int main() {
	//建立一个结对象
	vector<class Student> value;
	inputValue(value);
	ouputValue(value);
	return 0;
}
