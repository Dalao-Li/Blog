#include<iostream>
using namespace std;
int main(){
	int l = 0;
	int r = 1000;
	int n = 0;
	int goal = 1;
	while(l<=r){
		int mid = (l+r)/2;
		cout<<mid<<endl;
		if(mid == goal){
			break;
		}
		else if(mid < goal){
			l = mid+1;
			n++;
		}
		else if(mid > goal){
			r = mid +1;
			n++;
		}
	} 
	cout<<n<<endl;
} 
