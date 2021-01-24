#include<iostream>
using namespace std;
class Time {
	public:
		Time(int,int,int);
		int hour;
		int minute;
		int sec;
		void get_time();
};
Time::Time(int h,int m,int s) {
	hour=h;
	minute=m;
	sec=s;
}

void Time::get_time() {
	cout<<hour<<":"<<minute<<":"<<sec<<endl;
}

int main() {
	Time t1(10,13,56);
	int *p1=&t1.hour;              //定义指向整形数据的指针变量P1，并使其指向t1.hour
	cout<<*p1<<endl;
	t1.get_time();                 //调用对象t1的一个成员函数get_time()
	Time *p2=&t1;                  //定义指向类Time一个对象t1的指针变量，并使p2指向t1
	p2->get_time();                //p2指向t1的成员函数get_time
	void(Time::*p3)();             //定义指向类Time公共成员函数的一个指针变量p3
	p3=&Time::get_time;            //p3->get_time,p3指向get_time
	(t1.*p3)();                    //即t1.get_time
}
