#include <stdio.h>
#include <time.h>
#include <iostream>
#include <algorithm>
using namespace std;

int Numberlookups[6] = {0};
int Numbermoves[6] = {0};

//产生五组,每组100个随机数
void generateRandomNumbers(int testData[])
{
	for (int j = 0; j < 500; j++)
	{
		testData[j] = rand() % 100 + 1;
	}
}

//冒泡排序
void bubbleSort3(int testData[], int len)
{
	//一共五组数据
	for (int j = 0; j < len - 1; j++)
	{
		//用来判断是否发生过排序
		bool exchange = false;
		for (int i = 0; i < len - 1; i++)
		{
			if (testData[i] > testData[i + 1])
			{
				Numberlookups[0] += 1;
				//如果还有排序,则exchange为 true
				exchange = true;
				//交换两元素
				swap(testData[i], testData[i + 1]);
				Numbermoves[0] += 3;
			}
		}
		//如果此次扫描没有发生过交换,则说明此轮已经完成排序
		if (exchange == false)
		{
			break;
		}
	}
}

//插入排序
void insertionSorting(int testData[], int len)
{
	for (int i = 1, j; i < len; i++)
	{
		//前一个元素比后一个元素大
		if (testData[i - 1] > testData[i])
		{
			Numberlookups[1] += 1;
			int temp = testData[i];
			//从前一个元素位置开始,若未到表头且当前位置元素大于待插入元素temp
			for (j = i - 1; j >= 0 && temp < testData[j]; j--)
			{
				//所有元素依次向后移动
				testData[j + 1] = testData[j];
				Numbermoves[1] += 1;
			}
			//此处就是为插入留出的空(退出循环时j会多减1)
			testData[j + 1] = temp;
		}
	}
}

//选择排序
void selectionSort(int testData[], int len)
{

	for (int i = 0; i < len - 1; i++)
	{
		//起始基准码为表头元素位置
		int index = i;
		//遍历之后所有元素
		for (int j = i + 1; j <= len - 1; j++)
		{
			//如果某位置元素小于基准位置元素
			if (testData[j] < testData[index])
			{
				Numberlookups[2] += 1;
				//更新基准码
				index = j;
			}
		}
		//如果基准码不是开始的那个,说明现位置的元素最小
		if (index != i)
		{
			//将最小的元素交换到起始位置
			swap(testData[i], testData[index]);
			Numbermoves[2] += 3;
		}
	}
}

//快速排序
void quicksort(int testData[], int left, int right)
{

	//index表示待交换元素的位置
	int index = left;
	//设定基准元素,默认基准位置为最左边位置
	int pivotElement = testData[left];
	//遍历基准位置之后的所有元素
	for (int i = left + 1; i <= right; i++)
	{
		//如果该元素比基准元素小
		if (testData[i] < pivotElement)
		{
			Numberlookups[3]++;
			//待交换位置右移
			index++;
			//如果待交换位置与该位置不重合
			if (index != i)
			{
				swap(testData[i], testData[index]);
				Numbermoves[3] += 3;
			}
		}
	}
	//基准元素就位,基准位位index
	testData[left] = testData[index];
	testData[index] = pivotElement;
	if (left < right)
	{
		//对左侧元素也进行同样处理
		quicksort(testData, left, index - 1);
		//对右侧元素也进行同样处理
		quicksort(testData, index + 1, right);
	}
}

//希尔排序
void shellSort(int testData[], int len)
{
	//控制增量
	for (int gap = len / 2; gap > 0; gap /= 2)
	{
		//这个for循环就是前面的直接插入排序
		for (int i = gap, j; i < len; i++)
		{
			Numberlookups[4]++;
			int temp = testData[i];
			//循环打印数组的每个元素
			for (j = i - gap; j >= 0 && temp < testData[j]; j -= gap)
			{
				testData[j + gap] = testData[j];
				Numbermoves[4]++;
			}
			testData[j + gap] = temp;
			Numbermoves[4]++;
		}
	}
}

//调整为小根堆函数
void siftDown(int testData[], int start, int end)
{
	int parent = start;
	int child = 2 * parent + 1;
	//temp暂存子树根节点
	int temp = testData[parent];
	//如果左儿子编号未到终点
	while (child < end)
	{
		//如果右儿子比左儿子小
		if (child + 1 < end && testData[child] < testData[child + 1])
		{
			//child变为右儿子
			Numberlookups[5]++;
			++child;
		}
		// 如果根节点比儿子节点小,则不需要调整
		if (temp >= testData[child])
		{
			Numberlookups[5]++;
			break;
		}
		//否则需调整儿子和双亲的位置

		Numberlookups[5]++;
		testData[parent] = testData[child];
		//儿子上移变为双亲
		parent = child;
		//更新左儿子
		child = 2 * child + 1;
	}
	//更新双亲的值
	testData[parent] = temp;
}

//堆排序函数
void heapSort(int testData[], int len)
{
	for (int i = (len - 2) / 2; i >= 0; i--)
	{
		//建立一个小根堆
		siftDown(testData, i, len);
	}
	for (int i = len - 1; i > 0; i--)
	{
		//交换根和最后一个元素,
		swap(testData[0], testData[i]);
		Numbermoves[5] += 3;
		siftDown(testData, 0, i);
	}
}

int main()
{
	//测试数据
	int testData[500];
	//用以每次排序完后对元素顺序的恢复,以便循环使用
	int testData1[500], testData2[500], testData3[500], testData4[500], testData5[500];
	//设定随机数种子
	//srand ((unsigned)time(NULL));
	//产生5组共500个随机数
	generateRandomNumbers(testData);
	for (int i = 0; i < 500; i++)
	{
		testData1[i] = testData[i];
		testData2[i] = testData[i];
		testData3[i] = testData[i];
		testData4[i] = testData[i];
		testData5[i] = testData[i];
	}

	bubbleSort3(testData, 500);
	insertionSorting(testData1, 500);
	selectionSort(testData2, 500);
	quicksort(testData3, 0, 500);
	shellSort(testData4, 500);
	heapSort(testData5, 500);

	cout << "冒泡排序查询次数为" << Numberlookups[0] << endl;
	cout << "冒泡排序移动次数为" << Numbermoves[0] << endl;
	cout << "插入排序查询次数为" << Numberlookups[1] << endl;
	cout << "插入排序移动次数为" << Numbermoves[1] << endl;
	cout << "选择排序查询次数为" << Numberlookups[2] << endl;
	cout << "选择排序移动次数为" << Numbermoves[2] << endl;
	cout << "快速排序查询次数为" << Numberlookups[3] << endl;
	cout << "快速排序移动次数为" << Numbermoves[3] << endl;
	cout << "希尔排序查询次数为" << Numberlookups[4] << endl;
	cout << "希尔排序移动次数为" << Numbermoves[4] << endl;
	cout << "堆排序查询次数为" << Numberlookups[5] << endl;
	cout << "堆排序移动次数为" << Numbermoves[5] << endl;
	cout << endl;
}
