#include<iostream>
using namespace std;
int main(){
	int a[10]={0,0,5,9,3,3,6,6,7,12};
	int max=a[0];
	for(int i=1;i<10;i++){
		if(a[i]>max){
			max=a[i];
		}
	}
	//生成桶,桶的个数为数组中元素的最大值+1,编号对应桶的个数 
	int *b=new int [max];
	//分桶,将不同大小的元素放入对应编号的桶中 
	for(int i=0;i<max+1;i++){
		b[i]=0;
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<max+1;j++){
			//找到了对应的桶 
			if(a[i]==j){
				//桶的容量加一 
				b[j]++;
			}
		}
	} 
	//输出，沥遍每个桶，当桶内还有元素时输出桶的序号，即元素的值 
	for(int i=max;i>=0;i--){
		for(int j=b[i];j>0;j--){
			cout<<i<<endl;
		}
	}
	return 0; 
} 

