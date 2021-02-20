/*
	Name: 关于复数运算符重载的例子
	Copyright: 
	Author: 李元昊 
	Date: 11/05/18 14:55
	Description: 
*/

#include<iostream>
using namespace std;
class Complex
{
	public:
		Complex(){real=0;imag=0;}
		Complex(float r,float i){real=r;imag=i;}
		/*重载输入输出运算符，并将其声明为友元函数*/ 
		friend istream& operator >> (istream&,Complex&);
		friend ostream& operator << (ostream&,Complex&);
		/*重载四则运算运算符，并将其声明为友元函数*/
		friend Complex operator + (Complex &c1,Complex &c2);
		friend Complex operator - (Complex &c1,Complex &c2);
		friend Complex operator * (Complex &c1,Complex &c2);
		friend Complex operator / (Complex &c1,Complex &c2);
	private:
	    float real;
		float imag; 	
};
/*重载 >>运算符*/
istream& operator >> (istream& input,Complex &c)
{
	cout<<"请输入实部和虚部：";
	input>>c.real>>c.imag;
	return input; 
}
/*重载 <<运算符*/
ostream& operator << (ostream& ouput,Complex &c)
{
	ouput<<"("<<c.real<<"+"<<c.imag<<"i)";
	return ouput;
}
/*重载 +运算符*/
Complex operator + (Complex &c1,Complex &c2)
{
	return Complex(c1.real+c2.real,c1.imag+c2.imag);
}
/*重载-运算符*/
Complex operator - (Complex &c1,Complex &c2)
{

	return Complex(c1.real-c2.real,c1.imag-c2.imag);
}
/*重载 *运算符*/
Complex operator * (Complex &c1,Complex &c2)
{	
	return Complex(c1.real*c2.real-c1.imag*c2.imag,c1.imag*c2.real+c1.real*c2.imag);
}
/*重载 /运算符*/
Complex operator / (Complex &c1,Complex &c2)
{
	return Complex((c1.real*c2.real+c1.imag*c2.imag)/(c2.real*c2.real+c2.imag*c2.imag),(c1.imag*c2.real-c1.real*c2.imag)/(c2.real*c2.real+c2.imag*c2.imag));
}

int main()
{
	Complex c1,c2,c[4];
    while(1){
	    cin>>c1>>c2;
	    c[0]=c1+c2;
	    c[1]=c1-c2;
	    c[2]=c1*c2;
	    c[3]=c1/c2;
	    cout<<"两复数相加为结果为："<<c[0]<<endl;
		cout<<"两复数相减为结果为："<<c[1]<<endl;
		cout<<"两复数相乘为结果为："<<c[2]<<endl;
		cout<<"两复数相除为结果为："<<c[3]<<endl; 
		cout<<"                             "<<endl;		  	   	   
    }


}














