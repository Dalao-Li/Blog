/*有一个已经排好序的数组,现输入一个数,要求按原来的规律将它插入数组中*/
#include<iostream>
using namespace std;
int main() {
	int a[10]= {12,23,45,66,78,89,97,99,100,154};
	int i,j,n,number,temp1,temp2;
	for(i=0; i<10; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cin>>n;
	if(n>a[9]) {                                   /*如果插入的数字比数组中最大的数还大*/
		a[10]=n;                                   /*将这个数直接编为最后一个数字*/
	} else {                                       /*如果不是，则插入数组中*/
		for(i=0; i<10; i++) {                      /*沥遍每一个元素*/
			if(number<a[i]) {                      /*如果number比其中一个元素小，那么就插入这个元素的位置之前*/
				temp1=a[i];
				a[i]=number;                       /*number取代原a[i]，成为新a[i]*/
				for(j=i+1; j<11; j++) {            /*从插入位置开始，将后面的元素依次向后移动一位*/
					temp2=a[j];
					a[j]=temp1;                    /*原本的前一个元素，变为后一个元素*/
					temp1=temp2;
				}
			}
			break;                                 /*移动完成之后直接跳出循环*/
		}
	}
	for(i=0; i<11; i++) {
		cout<<a[i]<<" ";
	}
	return 0;
}
