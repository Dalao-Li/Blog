# 一、目的
使用C++采取后插法创建链表

# 二、环境
gcc 4.9.2

# 三、过程

## 3.1 数据定义

```c++
typedef struct Node {
	int data;
	struct Node *next;
} Node,*NodeList;
```
## 3.2 初始化
```c++
NodeList init(){
    NodeList head = (NodeList)malloc(sizeof(Node));
	head->next=NULL;
    return head;
}
```
## 3.3 输入
```c++
//输入n个节点的值
void input(NodeList &head,int n){
    NodeList p,tail;
    //起始头指针与尾指针在一起
	tail = head;
	for(int i = 0; i<n; i++) {
        //创建新节点
		p = (NodeList)malloc(sizeof(Node));
		scanf("%d",&p->data);
		p->next = NULL;
        //新节点位于尾指针的后边
		tail->next = p;
        //更新尾指针的位置
		tail = p;
	}
}
```
## 3.4 输出
```c++
void ouput(NodeList &head){
    NodeList p = head->next;
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
}
```
## 3.5 全部代码
```c++
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef struct Node {
	int data;
	struct Node *next;
} Node,*NodeList;

NodeList init(){
    NodeList head = (NodeList)malloc(sizeof(Node));
	head->next=NULL;
    return head;
}

//输入n个节点的值
void input(NodeList &head,int n){
    NodeList p,tail;
    //起始头指针与尾指针在一起
	tail = head;
	for(int i = 0; i<n; i++) {
        //创建新节点
		p = (NodeList)malloc(sizeof(Node));
		scanf("%d",&p->data);
		p->next = NULL;
        //新节点位于尾指针的后边
		tail->next = p;
        //更新尾指针的位置
		tail = p;
	}
}

void ouput(NodeList &head){
    NodeList p = head->next;
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
}

int main(void){
	const int n = 5;
	NodeList head = init();
	input(head,n);
	ouput(head);
	return 0;
}
```
运行结果

![](http://cdn.hurra.ltd/img/20200620130329.png)

![](http://cdn.hurra.ltd/img/赞赏码.png)