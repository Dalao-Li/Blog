#include<iostream>
using namespace std;

//冒泡排序
void bubbleSort3(int testData[],int len) {
	//一共五组数据

	for(int j = 0; j< len-1; j++) {
		//用来判断是否发生过排序
		bool exchange = false;
		for(int i = 0; i<len-1; i++) {
			if(testData[i] > testData[i+1]) {

				//如果还有排序，则exchange为 true
				exchange = true;
				//交换两元素
				swap(testData[i],testData[i+1]);

			}
		}
		//如果此次扫描没有发生过交换，则说明此轮已经完成排序
		if(exchange == false) {
			break;
		}
		cout<<"第"<<j<<"趟 "; 
		for(int i=0; i<10; i++) {
			cout<<testData[i]<<" ";
		}
		cout<<endl;
	}
}


int main() {
	int i;
	int a[10];
	for(i=0; i<10; i++) {
		cin>>a[i];
	}

	bubbleSort3(a,10);
	for(i=0; i<10; i++) {
		cout<<a[i]<<" ";
	}
	return 0;


}
