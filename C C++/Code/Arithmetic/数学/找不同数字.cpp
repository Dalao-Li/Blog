/*输入N个不同数字，找到其中不同数字的个数*/
#include<iostream>
#define N 10
using namespace std;
int main()
{
	int a[N],i,j,n=0;
	for(i=0;i<N;i++){
		cin>>a[i];
	}
	for(i=0;i<N;i++){               //依次读取N个数字的值
		for(j=0;j<i;j++){           //第二遍从头开始到i,查找之前的每个数,j<i避免把自己也当成相同数字
			if(a[i]==a[j]&&i!=j){   //值相同且位置不同，断定为一个数字出现了两次
				n++;                //相同数字数加1
				break;              //跳出查找此轮查找循环，继续查找下一个位置，避免重复计数
			}
		}
	}                               //至此，找出了N个数字里的n个完全相同数字（如1，1 2，2）
	cout<<"不同数字个数为："<<N-n;
	return 0;
}
