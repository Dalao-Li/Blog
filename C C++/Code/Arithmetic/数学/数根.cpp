#include<iostream>
using namespace std;
int main() {
	long n,num=0;
	cin>>n; 
	//累加该数字各个数位上的和
	while(n!=0) {
		num+=n%10;
		n/=10;
		//如果各数位累加完成且得到的数根不是一位数
		if(num>=10&&n==0) {
			n=num;
			num=0;
		}
	}
	cout<<num<<endl;
	return 0;
}

	
		
