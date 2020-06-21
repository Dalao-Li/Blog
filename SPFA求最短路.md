# 一、实验目的
通过SFPA算法求出某个点到其余点的最短路径

# 二、实验环境
gcc 4.9.2

# 三、实验过程

![](http://cdn.hurra.ltd/img/20200621204434.png)

## 3.1 理论方法

1.建立一个队列,存入开始节点
2.队列不为空时:
   
   取出队头节点X,X出队   
   遍历与X节点相通的节点Y,若X到Y的距离可缩小(松弛),且Y不在队列中
   则将Y入队,继续操作2



为求A节点到其余节点的最短路.设定 p[i]为A到i节点的路径

---

初始状态，建立点A到其余各点的最短路径
|     |A    |B |C |D |E |
|---- |---- |--|--|--|--|
|p[i] | 0   |∞ |∞ |∞ |∞ |

点A进入队列，若队列非空时:

队头点A出队,对以A为起点的所有边的终点进行松弛操作(涉及点B,E)
|     |A    |B  |C |D |E |
|---- |---- |-- |--|--|--|
|p[i] | 0   |**13** |∞ |∞ |**70**|

---

点B,E的最短路径变小,且点B,E未在队列中,故点B,E入队,队列中结点为B,E

队头点B出队,对以B为起点的所有边的终点进行松弛操作(涉及点C,D)
|     |A    |B  |C  |D  |E |
|---- |---- |-- |-- |-- |--|
|p[i] | 0   |13 |**41** |**17** |70 |

点C,D的最短路径变小,且点C,D未在队列中,故点C,D入队,队列中结点为E,C,D

---

队头元素E出队,对以E为起点的所有边的终点进行松弛操作

队头元素C出队,对以C为起点的所有边的终点进行松弛操作(D,E)
|     |A    |B  |C  |D  |E |
|---- |---- |-- |-- |-- |--|
|p[i] | 0   |13 |41 |17 |**56**|

---

点E的最短路径改变了,且点E未在队列中,故点E入队,队列中结点为D,E

队头元素D出队,对以D为起点的所有边的终点进行松弛操作

队头元素E出队,对以E为起点的所有边的终点进行松弛操作

队列为空,结束

点A到其他点的最短路径为

|     |A    |B  |C  |D  |E |
|---- |---- |-- |-- |-- |--|
|p[i] | 0   |13 |41 |17 |56|

---

## 3.2 代码实现
```c
//记录边的起点、终点、两点间权值
typedef struct E {
	//起点
	char sp;
	//终点
	char ep;
	//权值
	int w;
	E() {}
	E(char s, char e, int w) : sp(s), ep(e), w(w) {}
} E;

//保存边
vector<E> edge;

char node[5] = {'A','B','C','D','E'};

//记录点s到其他点最短路
int path[SIZE];

//记录点是否在队列
int in[SIZE];


//获取节点下标
int getIndex(char n) {
	for(int i = 0 ; i<5; i++) {
		if(node[i] == n) {
			return i;
		}
	}
}

//求s到其他点间的最短路
void SPFA(char s) {
	queue<char> q;
	//开始时将点s到其他点的距离设为∞
	memset(path, MAXV, sizeof(path));
	memset(in, 0, sizeof(in));
	int index = getIndex(s);
	//点s自己到自己的最短路为0
	path[index] = 0;
	q.push(s);
	in[index] = 1;
	while (!q.empty()) {
		char x = q.front();
		int x_index = getIndex(x);
		q.pop();
		in[x_index] = 0;
		//遍历所有与x所连通的节点,进行松弛操作
		for (int i = 0; i < edge.size(); i++) {
			//若某个边的起点是x
			if (edge[i].sp == x) {
				//cout<<edge[i].sp<<" "<<edge[i].ep<<endl;
				//获取该边的终点
				char end = edge[i].ep;
				int end_index = getIndex(end);
				//若从点S经过点X到点end的距离比S直接到end的距离短,则可进行松弛操作
				if (path[x_index] + edge[i].w < path[end_index]) {
					//从点S到点end的距离更新为点S到X的距离与X到end的距离之和
					path[end_index] = edge[i].w + path[x_index];
					//cout<<"path["<<end<<"] = "<<path[end_index]<<endl;
					if (!in[end_index]) {
						q.push(end);
						in[end_index] = 1;
					}
				}
			}
		}
	}
}
```

# 四、测试代码
```c
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
const int SIZE = 5;
const int MAXV = 10000; 
using namespace std;

typedef struct E {
	char sp;char ep;int w;
	E() {}
	E(char s, char e, int w) : sp(s), ep(e), w(w) {}
} E;

vector<E> edge;

char node[5] = {'A','B','C','D','E'};

int path[SIZE];

int in[SIZE];

int getIndex(char n) {
	for(int i = 0 ; i<5; i++) {
		if(node[i] == n) {
			return i;
		}
	}
}

//求s到其他点间的最短路
void SPFA(char s) {
	queue<char> q;
	//开始时将点s到其他点的距离设为∞
	memset(path, MAXV, sizeof(path));
	memset(in, 0, sizeof(in));
	int index = getIndex(s);
	//点s自己到自己的最短路为0
	path[index] = 0;
	q.push(s);
	in[index] = 1;
	while (!q.empty()) {
		char x = q.front();
		int x_index = getIndex(x);
		q.pop();
		in[x_index] = 0;
		//遍历所有与x所连通的节点,进行松弛操作
		for (int i = 0; i < edge.size(); i++) {
			//若某个边的起点是x
			if (edge[i].sp == x) {
				//cout<<edge[i].sp<<" "<<edge[i].ep<<endl;
				//获取该边的终点
				char end = edge[i].ep;
				int end_index = getIndex(end);
				//若从点S经过点X到点end的距离比S直接到end的距离短,则可进行松弛操作
				if (path[x_index] + edge[i].w < path[end_index]) {
					//从点S到点end的距离更新为点S到X的距离与X到end的距离之和
					path[end_index] = edge[i].w + path[x_index];
					//cout<<"path["<<end<<"] = "<<path[end_index]<<endl;
					if (!in[end_index]) {
						q.push(end);
						in[end_index] = 1;
					}
				}
			}
		}
	}
}

//建立测试数据
void init() {
	E e[6];
	e[0] = E('A','B',13);
	e[1] = E('A','E',70);
	e[2] = E('B','D',4);
	e[3] = E('B','C',28);
	e[4] = E('C','D',23);
	e[5] = E('C','E',15);
	for(int i = 0 ; i< 6; i++) {
		edge.push_back(e[i]);
	}
}

int main() {
	init();
	char s = 'A';
	SPFA(s);
	for(int i = 0 ; i<5;i++){
		cout<<"p["<<node[i]<<"] = "<<path[i]<<endl;
	}
	return 0;
}
```
运行结果
![](http://cdn.hurra.ltd/img/20200621231426.png)