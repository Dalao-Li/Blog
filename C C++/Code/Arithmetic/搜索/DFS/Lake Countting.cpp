#include<iostream>
using namespace std;

int n=3,m=3;
int a[3][6]= {
	{1,1,1,1,1,1},
	{1,0,1,0,0,1},
	{1,1,1,1,1,1}
};

void dfs(int x,int y) {
	//将此处换为1
	a[x][y] = 1;
	//即用(-1,-1),(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(0,0)表示八个方向
	for(int dx = -1; dx<=1; dx++) {
		for(int dy = -1; dy<=1; dy++) {
			//nx,ny代表移动之后的位置
			int nx = x + dx,ny = y + dy;
			//当该位置在矩阵内且值为0时
			if(0<=nx&&nx<n&&0<=ny&&ny<m&& a[nx][ny] == 0 ) {
				//继续DFS
				dfs(nx,ny);
			}
		}
	}
}

int main() {
	int sum = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(a[i][j]==0) {
				dfs(i,j);
				sum++;
			}
		}
	}
	cout<<sum<<endl;
}
