#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#define MAXPARKSPORT 5
using namespace std;
typedef struct {
	char flag;
	int licensePlate;

} Car,*CarList;

//便道
typedef struct {
	Car *base;
	//头指针
	int front;
	//尾指针
	int rear;
} Road,*RoadList;

//初始化便道
void initQuene(Road &r) {
	r.base = (CarList)malloc(MAXPARKSPORT *sizeof(Road));
	if(!r.base) {
		exit(0);
	}
	//头尾指针置为0队列为空
	r.front = r.rear = 0;
	printf("初始化成功\n");
}


//车辆开入便道
void carDirvingInRoad(Road &r,Car &elem) {
	if((r.rear +1) % MAXPARKSPORT == r.front) {
		return;
	}
	//新元素插入队尾
	r.base[r.rear] = elem;
	//队尾指针加1
	r.rear = (r.rear + 1) % MAXPARKSPORT;
}

//车辆离开便道
void carLeaveRoad(Road &r,Car &c) {
	if(r.front == r.rear) {
		return ;
	}
	c = r.base[r.front];
	//队头指针加1相当于删除了队头
	r.front = (r.front + 1)  % MAXPARKSPORT ;
}

//搜寻车辆在通道内的位置
int getCarPositon2(Road &r,Car &elem) {
	for(int i = r.rear ; i>=r.front  ; i--) {
		if(elem.licensePlate == r.base[i].licensePlate) {
			return i;
		}
	}
	return -1;
}

int main() {
	Car c;
	Road r;
	initQuene(r);
	for(int i = 0 ; i < 3; i++) {
		cin>>c.flag>>c.licensePlate;
		carDirvingInRoad(r,c);
		cout<<"入队成功"<<endl;
	}
	cin>>c.flag>>c.licensePlate;
	cout<<getCarPositon2(r,c);
}
