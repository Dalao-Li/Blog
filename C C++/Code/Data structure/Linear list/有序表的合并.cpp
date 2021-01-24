#include<stdio.h>
#include<stdlib.h>

//建立顺序表
typedef struct {
	int *elem;
	int length;
} Sqlist;

//顺序表的初始化
void initialize(Sqlist &L,const int n) {
	//动态开辟结构体数组
	L.elem = (int *) malloc (100 * sizeof(Sqlist));
	if(!L.elem) {
		return;
	}
	L.length=0;
	printf("初始化成功\n",L.length);
	//顺序表的输入
	for(int i=0; i<n; i++) {
		scanf("%d",&L.elem[i]);
		L.length++;
	}
}

//实现将s1 s2中的元素按顺序摘取到s3中
void mergeList(Sqlist &S1,Sqlist &S2,Sqlist &S3) {

	int e;
	int start1=0,start2=0,start3=0;
	int end1=S1.length-1;
	int end2=S2.length-1;

	S3.elem=(int *) malloc (200 * sizeof(Sqlist));
	S3.length=S1.length+S2.length;
	//s1 s2均未到末尾时，依次查找两个表的值，把较小的值插入s3中
	while(start1<=end1&&start2<=end2) {
		if(S1.elem[start1]<=S2.elem[start2]) {
			S3.elem[start3++]=S1.elem[start1++];
		} else {
			S3.elem[start3++]=S2.elem[start2++];
		}
	}
	//如果s2先到了末尾，那么将s1中剩余元素插入s3中
	while(start1<=end1) {
		S3.elem[start3++]=S1.elem[start1++];
	}
	while(start2<=end2) {
		S3.elem[start3++]=S2.elem[start2++];
	}
}

//顺序表的输出
void ouputElem(Sqlist &L) {
	for(int i=0; i<L.length; i++) {
		printf("%d ",L.elem[i]);
	}
	printf("\n");
}

int main() {
	Sqlist S1,S2,S3;
	int size1,size2;
	scanf("%d",&size1);
	initialize(S1,size1);
	scanf("%d",&size2);
	initialize(S2,size2);
	mergeList(S1,S2,S3);

	ouputElem(S3);
}

