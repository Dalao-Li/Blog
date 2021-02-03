#include<iostream>
#include<string>
#define MAXVERTICES 20
#define MAXWEIGHT 100
using namespace std;

typedef char TypeElement;
typedef struct {
	//图中实际总顶点数
	int sumVertices;
	//图中实际总边数
	int sumEdges;
	//顶点表
	TypeElement verticesList[MAXVERTICES];
	//邻接矩阵
	int adjacentMatrix[MAXVERTICES][MAXVERTICES];
	//用来表示点某个点是否被选过
	bool isExchanged[MAXVERTICES];
} Graph;

//查找某个在顶点表中的位置,不存在则返回-1
int getPositionInVerticesList(Graph & G,TypeElement val) {
	for(int i = 0; i<G.sumVertices ; i++) {
		if(G.verticesList[i] == val) {
			return i;
		}
	}
	return -1;
}

//查找某个顶点的第一个邻接顶点,参数为顶点在顶点表中的位置
int findFirstNeighborVertex(Graph &G , int vertexPosition) {
	//如果位置合法
	if(vertexPosition != -1) {
		//遍历顶点表
		for(int j = 0; j<G.sumVertices ; j++) {
			//找到一个合法的邻接点
			if(G.adjacentMatrix[vertexPosition][j] > 0 && G.adjacentMatrix[vertexPosition][j] <MAXWEIGHT) {
				//返回该邻接点的位置
				return j;
			}
		}
	}
	return -1;
}

//找出一个顶点除一个邻接顶点之外的另一个邻接顶点
int findNextNeighborVertex(Graph &G , int vertexPosition1, int vertexPosition2) {
	if(vertexPosition1 != -1 && vertexPosition2 != -1) {
		//直接从 vertexPosition2 + 1判断, 因为vertexPosition2之前的点肯定不是其邻接点
		for(int j = vertexPosition2 + 1 ; j< G.sumVertices ; j++ ) {
			if(G.adjacentMatrix[vertexPosition1][j] >0 && G.adjacentMatrix[vertexPosition1][j] < MAXWEIGHT ) {
				return j;
			}
		}
	}
	return -1;
}

//初始化图函数,n,e代表顶点数和边数
void createGraph(Graph &G,int n,int e) {
	G.sumVertices = n;
	G.sumEdges = e;
	for(int i = 0 ; i<G.sumVertices ; i++) {
		//标记该点为未选状态
		G.isExchanged[i] == false;
		TypeElement val;
		cout<<"请输入顶点值"<<endl;
		//输入顶点值
		cin>>val;
		//更新顶点表
		G.verticesList[i] = val;
		for(int j = 0 ; j< G.sumVertices ; j++) {
			//对角线值为0
			if(i == j) {
				G.adjacentMatrix[i][j] = 0;
			} else {
				G.adjacentMatrix[i][j]= MAXWEIGHT;
			}
		}
	}
	//初始化每一条边
	for(int i = 0; i< G.sumEdges ; i++) {
		TypeElement e1,e2;
		int weight;
		//输入这个边的两个点和权值
		cout<<"输入这个边的两个点和权值"<<endl;
		cin>>e1>>e2>>weight;
		//获取这两个点在顶点表中的坐标
		int position1 = getPositionInVerticesList(G,e1);
		int position2 = getPositionInVerticesList(G,e2);
		//更新邻接矩阵
		G.adjacentMatrix[position1][position2] = weight;
		G.adjacentMatrix[position2][position1] = weight;
	}
}

//查找节点
TypeElement getTypeElement(Graph &G , int vertexPosition) {
	if(vertexPosition != -1) {
		return G.verticesList[vertexPosition];
	}
}

//遍历图,形参为最开始遍历的节点位置
void dfs(Graph &G,int vertexPosition) {
	cout<<"->"<<getTypeElement(G,vertexPosition);
	//标记该位置为已选
	G.isExchanged[vertexPosition] = true;
	// firstNeighborVertex表示vertexPosition的第一个邻接点
	int neighborPosition = findFirstNeighborVertex(G,vertexPosition);
	//当vertexPosition的邻接点存在时
	while (neighborPosition != -1 ) {
		//如果该点没有被选过
		if(G.isExchanged[neighborPosition] == false) {
			//递归访问 下一个邻接点
			dfs(G,neighborPosition);
		}
		//否则取 vertexPosition 的另一个邻接点 neighborPosition
		neighborPosition =  findNextNeighborVertex(G,vertexPosition,neighborPosition);
	}
}

//求vertexPosition的最短路径
void theShortestPath(Graph &G,int vertexPosition,int distance[],int path[]) {
	//最短路径顶点集合
	int isGetShortestPath[MAXVERTICES];
	for(int i = 0 ; i<G.sumVertices ; i++) {
		//路径长度数组初始化,其值为vertexPosition到其他每个点的距离
		distance[i] = G.adjacentMatrix[vertexPosition][i];
		//表示顶点i是否求得最短路径
		isGetShortestPath[i] =0;
		//如果从vertexPosition到i有边,path[i]为该边始顶点号vertexPosition
		if(i != vertexPosition && distance[i] < MAXWEIGHT) {
			path[i] = vertexPosition;
		}
		//若没有边则path[i]为-1
		else {
			path[i] = -1;
		}
	}
	//顶点vertexPosition加入集合isGetShortestPath
	isGetShortestPath[vertexPosition] = 1;
	distance [vertexPosition] = 0;
	//逐个求得isGetShortestPath到其他顶点的最短路径
	for(int i = 0; i < G.sumVertices -1; i++) {
		int min  = MAXWEIGHT;
		//选不在 isGetShortestPath中具有最短路径的顶点point
		int point = vertexPosition;
		for(int j = 0 ; j< G.sumVertices ; j++) {
			//如果该点j没有被选入且从vertexPosition到该点的距离小于min
			if(!isGetShortestPath[j] && distance[j] < min ) {
				//更新位置
				point = j;
				//更新最短路径
				min = distance[j];
			}
		}
		//将顶点point加入isGetShortestPath集合
		isGetShortestPath[point] = 1;
		//修改经过point到其他顶点的路径长度
		for(int k = 0 ; k< G.sumVertices ; k++) {
			//weight为点point到点k的距离
			int weight = G.adjacentMatrix[point][k];
			/* 如果点k未被选过
			且 点point到点k有边
			且 vertexPosition到点k的距离比vertexPosition经点point到点k的距离长*/
			if(!isGetShortestPath[k] && weight < MAXWEIGHT && distance[point] + weight < distance[k]) {
				//vertexPosition到点k的距离路径可以缩短
				distance[k] = distance[point] + weight;
				// vertexPosition到点k的前一个顶点为point
				path[k] = point;
			}
		}
	}
}

//图的插入(插入一条边)
void insertGraphEdge(Graph &G,int point1,int point2,int weight) {
	if(point1 != -1 && point2 !=- 1) {
		//邻接矩阵中添加该边
		G.adjacentMatrix[point1][point2] = weight;
		G.adjacentMatrix[point2][point1] = weight;
	}
}

//图的插入(插入一个顶点)
void insertGraphVertice(Graph &G,TypeElement val) {
	if(G.sumVertices<MAXVERTICES) {
		//总节点数加1
		G.sumVertices++;
		//更新节点
		G.verticesList[G.sumVertices] = val;
	}

}

//删除一条边
void deleteGraphEdeg(Graph &G,int point1,int point2) {
	//解除边的关系
	if(point1 != -1 && point2 !=- 1) {
		G.adjacentMatrix[point1][point2] = MAXWEIGHT;
		G.adjacentMatrix[point1][point2] = MAXWEIGHT;
	}
}


//删除一个顶点和相应的边
void deleteGraphVetric(Graph &G,TypeElement val) {
	//找到该点的位置
	int position = getPositionInVerticesList(G,val);
	//将它换到顶点表的最后一位上去
	int temp = G.verticesList[G.sumVertices];
	G.verticesList[G.sumVertices] = G.verticesList[position];
	G.verticesList[position] = temp;
	//转化边的关系
	for(int j = 0 ; j< G.sumVertices ; j++) {
		G.adjacentMatrix[position][j] = MAXWEIGHT;
		G.adjacentMatrix[j][position] = MAXWEIGHT;
	}
	G.adjacentMatrix[position][position] = 0;
	//总顶点数减1
	G.sumVertices--;
}



int main() {
	Graph G;
	createGraph(G,4,5);
	for(int i = 0 ; i< G.sumVertices ; i++) {
		for(int j = 0 ; j <G.sumVertices ; j++) {
			printf("%4d ",G.adjacentMatrix[i][j]);
		}
		cout<<endl;
	}
	cout<<endl;
	dfs(G,2);
	cout<<endl;
	for(int i = 0 ; i<G.sumVertices ; i++) {
		G.isExchanged[i] == false;
	}
	int distance[MAXVERTICES],path[MAXVERTICES];
	theShortestPath(G,0,distance,path);
	for(int i = 0; i< G.sumVertices ; i++) {
		cout<<distance[i]<<endl;
	}
}
