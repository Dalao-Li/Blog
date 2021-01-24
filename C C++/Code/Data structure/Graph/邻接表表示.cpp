#include<stdio.h>
#include<iostream>
#define MAXVERTICES 20
#define MAXWEIGHT 100
using namespace std; 

typedef char TypeElement;
typedef struct Enode{
	int dest; //边的另一顶点位置 
	int weight;
	struct Enode *link; //下一条边链指针
}EdgeNode;

typedef struct {
	TypeElement  data;  //顶点的名字 
	struct Eonde *adj;  //边链表的头指针 
}VertexNode; 

typedef struct {
	VertexNode VerticesList[MAXVERTICES];
	//图中实际总顶点数
	int sumVertices;
	//图中实际总边数
	int sumEdges;
}Algraph;

void creatAlgraph(Algraph &G,int n,int e){
	G.sumVertices = n;
	G.sumEdges = e;
	TypeElemen val,e1,e2;
	//初始化顶点表 
	for(int i = 0 ; i< G.sumVertices ; i++){
		cin>>val;
		G.VerticesList[i].data = val; //更新顶点数据 
		G.VerticesList.adj = NULL; 
	}
	for(int i = 0 ; i < G.sumEdges ;i++){
		
	}
}

