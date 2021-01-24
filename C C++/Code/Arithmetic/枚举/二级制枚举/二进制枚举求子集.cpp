#include<iostream>
#include<cstdlib>
using namespace std;
int a[3]= {2,3,4};
int main() {
	//子集的个数
	for(int i = 1; i<=(1<<3); i++) {
		//子集的内容
		for(int j = 0; j<3; j++) {
			if(i&(1<<j)) {
				cout<<a[j]<<" ";
			}

		}
		cout<<endl;
	}
}

