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

//顺序表的取值,
int getElem(Sqlist &L,const int index) {
	if(index>=L.length||index<0) {
		printf("索引错误!");
		return 0;
	}
	return L.elem[index];
}

//顺序表的查找
bool locateElem(Sqlist &L,int e) {
	for(int i=0; i<L.length; i++) {
		if(L.elem[i]==e) {
			return true;
		}
	}
	return false;

}

//顺序表的插入,到末尾
void insertElem(Sqlist &L,int e) {
	//增长表的长度 
	++L.length;
	//将值插入到末尾 
	L.elem[L.length-1]=e;
}

//实现将s2中在s1中不存在元素摘取到s1中
void mergeList(Sqlist &S1,Sqlist &S2) {
	int size1=S1.length;
	int size2=S2.length;
	int e;
	for(int i=0; i<size2; i++) {
		//沥遍s2中每一个元素,将其赋给e
		e=getElem(S2,i);
		//若e不再S1中，则将它插入s1的末尾
		if(locateElem(S1,e)==false) {
			insertElem(S1,e);
		}
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
	Sqlist S1,S2;
	int size1,size2;
	scanf("%d",&size1);
	initialize(S1,size1);
	scanf("%d",&size2);
	initialize(S2,size2);
	mergeList(S1,S2);
	ouputElem(S1);
}

