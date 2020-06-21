# 一、实验目的
使用C++实现几种常用的排序方法

# 二、实验环境
GCC 4.9.2

# 三、实验过程

## 3.1 冒泡排序
```c++
//冒泡排序,len为数组长度
void bubbleSort(int data[],int len) {
	for(int i = 0; i< len-1; i++) {
		//用来记录是否发生过交换
		bool exchange = false;
		for(int j = 0; j<len-1; j++) {
			if(data[j] > data[j+1]) {
				//如果有交换,则exchange为 true
				exchange = true;
				swap(data[j],data[j+1]);
			}
		}
		//如果此轮没有发生交换，则说明已完成排序
		if(exchange == false) {
			break;
		}
	}
}
```
## 3.2 插入排序
```c++
void insertSort(int data[],int len) {
	for(int i = 1; i<len; i++) {
		if(data[i-1] > data[i]) {
            //temp为待插入元素
			int temp = data[i];
            int j = i - 1;
			//从前一个元素位置开始,若未到表头且当前位置元素大于temp
            whlie(j >= 0 && temp < data[j]){
                //所有元素依次向后移动
				data[j+1] = data[j];
                j--;
            }
			//此处就是为插入temp留出的空(退出循环时j会多减1)
			data[j+1] = temp;
		}
	}

}
```

## 3.3 选择排序
```c++
void selectSort (int data[],int len) {
	for(int i=0; i < len-1; i++) {
		//基准码最开始为表头元素下标
		int index = i;
		for(int j = i+1; j <= len-1; j++) {
			//如果某位置元素小于基准位置元素
			if(data[j] < data[index]) {
				//更新基准码
				index = j;
			}
		}
		//如果基准码不是开始的那个,说明现位置的元素最小
		if(index != i) {
			//将最小的元素交换到起始位置
			swap(data[i],data[index]);
		}
	}
}
```

## 3.4 快速排序
```c++
//left,reight代表数组左右区间大小
void quickSort(int data[],int left,int right) {
	//index表示基准下标,index左侧值均比data[index]小;右侧值均比data[index]大
	int index = left;
	//设定基准元素,默认基准位置为最左边位置
	int pivot = data[left];
	for(int i = left+1 ; i<= right ; i++) {
		if(data[i]< pivot) {
			//基准下标右移
			index++;
			//如果待交换位置与该位置不重合
			if(index != i) {
				swap(data[i],data[index]);
			}
		}
	}
	//基准元素就位,基准位为index
	data[left] = data[index];
	data[index] = pivot;
	if(left < right) {
		//对左侧元素也进行同样处理
		quicksort(data,left,index-1);
		//对右侧元素也进行同样处理
		quicksort(data,index+1 ,right);
	}
}
```

## 3.5 堆排序
```c++
//调整为小根堆函数;start,end 表示待建堆区间
void siftDown(int data[],int start,int end) {
	int parent = start;
	int child = 2*parent+1;
	//temp暂存子树根节点
	int temp = data[parent];
	//如果左儿子编号未到终点
	while(child < end) {
		//如果右儿子比左儿子小
		if(child+1 < end && data[child] < data[child+1]) {
			//child变为右儿子
			child++;
		}
		// 如果根节点比儿子节点小,则不需要调整
		if(temp >= data[child]) {
			break;
		}
		//否则需调整儿子和双亲的位置
		data[parent] =  data[child];
		//儿子上移变为双亲
		parent = child;
		child = 2*child+1;
	}
	data[parent] = temp;

}

//堆排序函数
void heapSort(int data[],int len) {
	for(int i =  (len-2)/2; i>=0 ; i-- ) {
		//建立一个小根堆
		siftDown(data,i,len);
	}
	for(int i = len-1 ; i>0 ; i--) {
		//交换根和最后一个元素,
		swap(data[0],data[i]);
		siftDown(data,0,i);
	}
}
```