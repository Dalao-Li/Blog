#include<iostream> 
#include <vector>
#include <string>
#include <fstream>

using namespace std;
int main() {
	ifstream myfile("2.txt");
	ofstream outfile("3.txt", ofstream::app);
	string temp;
	if (!myfile.is_open()) {
		cout << "未成功打开文件" << endl;
	}
	while(getline(myfile,temp)) {
		outfile<<temp;
		cout<<temp<<endl;
	}
	myfile.close();
	return 0;
}
