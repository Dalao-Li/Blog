#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int main() {
	//定义及初始化
	string s1;

	string s3= "Ich liebe dich!";                 //直接初始化
	string s4(10,'a');                            //s4中存了10个a
	string s5(s4);                                //拷贝初始化，深拷贝字符串
	string s6=string(6,'c');
	string s7=s3+s4;
	string s8="";                                 //s8为空字符串

	/*-------string的操作--------*/

	getline(cin,s1);                              //用getline来获取一整行内容
	string s2=s1;                                 //s2是s1的副本
	int size=s3.size();

	/*当把string对象和字符面值及字符串面值混在一条语句中使用时，
	必须确保+的两侧的运算对象至少有一个是string*/
	string s10 = s2 + ", ";                       //s2的末尾加上 ","
	string s11 = s1 + "hello " + ", ";            //改一下顺序，s1放前头，正确了，注意理解=号右边的运算顺序

	/*--------输出---------------*/
	cout<<"s1:"<<s1<<endl;
	cout<<"s2:"<<s2<<endl;
	cout<<"s3:"<<s3<<" "<<size<<endl;
	cout<<"s4:"<<s4<<endl;
	cout<<"s5:"<<s5<<endl;
	cout<<"s6:"<<s6<<endl;
	cout<<"s7:"<<s7<<endl;
	cout<<s8.empty()?"s8 is empty string":"NO";    //s8为空时返回true
	cout<<"s10:"<<s10<<e-ndl;
	cout<<"s11:"<<s11<<endl;
}
