#include<iostream>
#include<algorithm>
using namespace std;

//调整为小根堆函数
void siftDown(int testData[],int start,int end) {
	int parent = start;
	int child = 2*start+1;
	//temp暂存子树根节点
	int temp = testData[parent];
	//如果左儿子编号未到终点
	while(child < end) {
		//如果右儿子比左儿子小
		if(child+1 < end && testData[child] < testData[child+1]) {
			//child变为右儿子
			++child;
		}
		// 如果根节点比儿子节点小,则不需要调整
		if(temp >= testData[child]) {
			break;
		}
		//否则需调整儿子和双亲的位置
		testData[parent] =  testData[child];
		//儿子上移变为双亲
		parent = child;
		//更新左儿子
		child = 2*child+1;
	}
	//更新双亲的值
	testData[parent] = temp;

}

//堆排序函数
void heapSort(int testData[],int len,int n) {
	for(int i =  (len-2)/2; i>=0 ; i-- ) {
		//建立一个小根堆
		siftDown(testData,i,len);
	}
	for(int i = len-1 ; i>0 ; i--) {
		//交换根和最后一个元素,
		swap(testData[0],testData[i]);
		siftDown(testData,0,i);
	}
}

int a[10000];
int n ,k;
int main() {
	cin>>n>>k;
	for(int i = 0; i<n; i++) {
		cin>>a[i];
	}
	heapSort(a,n,n);
	cout<<a[n-k]<<endl;
}
