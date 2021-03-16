/*
	Name:人、学生和教师 
	Copyright: 
	Author: 李元昊 
	Date: 21/05/18 22:46
	Description: 
*/
#include<iostream>
#include<string>
using namespace std;
class People 
{
	public:
		People(){}  //建立无参构造函数 
		People(int a,string s)
		{
			age=a;
			name=s;
		}
		void setValue()
		{
			cout<<"please input the age and name"<<endl;
			cin>>age>>name;
		} 
		virtual void display()=0;  //建立纯虚函数 
		~People(){}  //建立午餐析构函数 
	protected:
	    int age;
		string name;  
};
void People::display() 
{
	cout<<"age= "<<age<<"\nname= "<<name<<endl;
}

class Student:public People  //公有继承基类 
{
	public:
		Student(){}
		Student(int a,string s,int b):People(a,s),studentID(b){} //建立有参构造函数 
		void setID1()
		{
			cout<<"please input the studentID"<<endl;
			cin>>studentID;
		}
		void display()
		{
			cout<<"age= "<<age<<"\nname= "<<name<<"\nstudentID= "<<studentID<<endl;	
		}
		~Student(){}
	private:
		int studentID;
}; 

class Teacher:public People //公有继承基类 
{
	public:
		Teacher(){}
		Teacher(int a,string s,int b):People(a,s),teacherID(b){}
		void setID2()
		{
			cout<<"please input the teacherID"<<endl;
			cin>>teacherID;
		}
		void display()
		{
			cout<<"age= "<<age<<"\nname= "<<name<<"\nteacherID= "<<teacherID<<endl;
			cout<<endl; 
		}
		~Teacher(){} 
	private:
	    int teacherID;		
};

int main()
{
	Student *p1,stu;
	Teacher *p2,tea;
	p1=&stu;
	p1->setValue();
	p1->setID1();
	p1->display();
	p2=&tea;
	p2->setValue();
    p2->setID2();
	p2->display();
	return 0;
	   
}
