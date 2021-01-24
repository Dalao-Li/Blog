#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ofstream outfile;      //终端输入--》内存--》文本
	outfile.open("2.txt");//(输入流) （变量）（输出文件流）
	if(!outfile) cout<<"error"<<endl;

	string str;
	int t1;
	int i=0;
	while(cin>>t1) {           //按空格读取，遇到空白符结束
		if(i!=0&&i%3==0)
			outfile<<"\n";
		outfile<<t1<<" ";
		i++;
	}

	outfile.close();
	return 0;
}
