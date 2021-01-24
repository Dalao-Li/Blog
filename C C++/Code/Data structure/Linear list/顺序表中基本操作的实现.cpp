#include<stdio.h>
#include<stdlib.h>

//建立顺序表
typedef int ElemType;

typedef struct {
	ElemType *elem;
	int length;
} Sqlist;

//顺序表的初始化
void initialize(Sqlist &L) {
	//动态开辟结构体数组
	//L.elem = (Polynomial *) malloc (MAXSIZE * sizeof(Polynomial)); 
	L.elem=(ElemType *) malloc (6 * sizeof(Sqlist));
	if(!L.elem) {
		return;
	}
	L.length=0;
	printf("初始化成功\n",L.length);
	//顺序表的输入
	for(int i=0; i<5; i++) {
		scanf("%d",&L.elem[i]);
		L.length++;
	}
}

//顺序表的取值,
void getElem(Sqlist &L,const int index) {
	if(index<1||index>L.length) {
		printf("索引错误!");
		return;
	}
	printf("第%d索引的值为:%d\n",index,L.elem[index-1]);
}

//顺序表的查找
int locateElem(Sqlist &L,const int e) {
	for(int i=0; i<L.length; i++) {
		if(L.elem[i]==e) {
			return i+1;
		}
	}
	return 0;
}

//顺序表的插入，前插 
void insertElem(Sqlist &L,int index,int e) {
	if(index<1||index>L.length) {
		return;
	}
	//如果没位置插了 
	/*if(L.length=MAXSIZE) {
		return;
	}*/
	for(int i=L.length-1; i>=index-1; i--) {
		L.elem[i+1]=L.elem[i];
	}
	L.elem[index-1]=e;
	L.length++;
}

//顺序表的输出
void ouputValue(Sqlist &L) {
	for(int i=0; i<L.length; i++) {
		printf("%d\n",L.elem[i]);
	}
}

int main() {
	Sqlist L;
	initialize(L);
	printf("输入你想查找的索引:");
	int index;
	scanf("%d",&index);
	getElem(L,index);
	printf("输入你想查找的值:");
	int e;
	scanf("%d",&e);
	printf("%d的索引为%d\n",e,locateElem(L,e));
	printf("输入你想插入的位置和值:");
	int index,e;


	scanf("%d%d",&index,&e);
	insertElem(L,index,e);
	printf("数组长度为%d\n",L.length);
	ouputValue(L);
	return 0;


}
