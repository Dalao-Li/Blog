#include<iostream>
using namespace std;
void quickSort(int arr[],int startIndex,int endIndex) {
	//递归结束条件，startIndex大等于endIndex时
	if(startIndex>=endIndex) {
		return 0;
	}
	//得到基准元素位置
	int pivotIndex = partition(arr,startIndex,endIndex);
	quickSort(arr,startIndex,pivotIndex-1);
	quickSort(arr,pivotIndex+1,endIndex);
}

void partition(int arr[],int startIndex,int endIndex) {
	//取第一个元素作基准元素
	int pivot=arr[startIndex];
	int left=startIndex;
	int right=endIndex;
	//坑的位置，初始等于pivot的位置
	int index=startIndex;
	//大循环在左右指针重合或者交错时结束
	while(right>=left) {
		//right指针从右向左进行比较
		while(right>=left) {
			if(arr[right] < pivot)	{
				arr[left]=arr[right];
				index=right;
				left++;
				break;
			}
			right--;
		}
		//left指针从左向右进行比较
		while(right>=left) {
			if(arr[left]>pivot) {
				arr[right]=arr[left];
				index=left;
				right--;
				break
				;
			}
			left++;
		}
	}
	arr[index]=pivot;

	return index;
}
int main() {
	int arr[8]= {4,7,6,5,3,2,8,1};
	quickSort(arr,0,arr.size()-1);
	for(int i=0; i<8; i++) {
		cout<<arr[i]<<" ";
	}
	return 0;
}


