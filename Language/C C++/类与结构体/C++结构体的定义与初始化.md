<!--
 * @Description: 
 * @Version: 1.0
 * @Author: Li Yuanhao
 * @Email: dalao_li@163.com
 * @Date: 2021-01-16 17:59:34
 * @LastEditors: Li Yuanhao
 * @LastEditTime: 2021-01-31 10:38:37
-->

  
# 目的
定义一个结构体,并设立带参与无参的构造函数  

定义一个结构体数组并完成初始化

# 代码

## 结构体定义
```c++
typedef struct Stu {
    string name;
    string num;
    int age;
	//无参构造函数
	Stu(){}
    //含参构造函数
	Stu(string name,string num,int age):name(name),num(num),age(age) {}
} Stu;
```

## 结构体初始化

```c++
Stu s("lili","A-1234",18);
cout<<s.name<<" "<<s.num<<" "<<s.age<<endl;
```

运行结果  
![](https://cdn.hurra.ltd/img/20200618213943.png)

## 2.3 结构体数组
```c++
//定义结构体数组
Stu s[3];
//初始化
s[0] = Stu("WANG","A-234",19);
s[1] = Stu("Han","A-235",19);
s[2] = Stu("Liu","A-236",19);

for(int i = 0;i<3;i++){
    cout<<s[i].name<<" "<<s[i].num<<" "<<s[i].age<<endl;
}
```
运行结果  
![](https://cdn.hurra.ltd/img/20200618214620.png)

# 补充

## 3.1 构造函数
含参构造函数写出如下形式也是可以的
```c++
//含参构造函数
Stu(string name,string num,int age){
	this->name = name;
	this->num = num;
	this->age = age;
}
```