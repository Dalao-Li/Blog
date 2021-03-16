//t.detach()可以在程序一运行开始就输入字符
//t.join()会等待启动的线程结束，才继续向下执行
#include <iostream>
#include <thread>
#include<windows.h>

using namespace std;

void output1() {
	for (int i = 0; i < 4; i++) {
		cout <<"线程1:" <<i << endl;
	}
}

void output2() {
	for (int i = 0; i < 4; i++) {
		cout <<"线程2:"<<i*i<<endl;
	}
}

int main() {
	//创建一个线程t
	thread t1(output1);
	thread t2(output2);
	//该线程在后台允许，无序等待该线程的完成
	t1.detach();
	Sleep(1000);
	t2.detach();
	Sleep(1000);
	return 0;
}
