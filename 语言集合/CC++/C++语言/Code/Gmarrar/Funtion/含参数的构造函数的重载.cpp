#include<iostream>
using namespace std;
class Box
{
	public:
		Box();                                        //声明一个无参数的构造函数Box()
		//定义一个有默认参数的构造函数用函数的初始化表对数据成员初始化
        Box(int h=10,int w=12,int len=15):height(h),width(w),length(len){}
		int volume();                                //声明成员函数volume
	private:
		int height;
		int width;
		int length;
};

int Box::volume()
{
	return(height*width*length);
}

int main()
{
	Box a[3]={
		Box(10,12,15),
		Box(15,18,20),
		Box(16,20,26)
	};
	cout<<a[0].volume()<<endl;
	cout<<a[1].volume()<<endl;
	cout<<a[2].volume()<<endl;
}
