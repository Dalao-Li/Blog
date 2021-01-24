#include<bits\stdc++.h>
using namespace std;
int main() {
	string str("heoolo sdaa ss");
	/*返回的是子串位置。第二个参数是查找的起始位置，
	如果找不到，就返回string::npos*/
	
	if (str.find("as", 0) == string::npos) {
		cout << "找不到该子串！" << endl;
	}
	else{
		cout << str.find("as", 0) << endl;
	}
}
