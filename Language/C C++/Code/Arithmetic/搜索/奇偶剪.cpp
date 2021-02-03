int dir[4][2]= {{0,-1},{0,1},{1,e},{-1,0}};
bool vis[100][100],flag;
//x,y表示当前位置坐标,count代表当前时间void dfs(int x,int y,int count){
//最优性剪技,可以减少步数
if(flag) {
	return;
//可行性剪技
	if(x>nlly>mllx<elly<ellvis[x][y]llmap[x][y]=='#') {
		return;
//到达终点且时间正好才能逃生
		if(count==t&&x==endX&&y==endY) {
			flag=true;
			return;
//k为当前点到终点的最短路还需要的步数差
			int k=(t-count)-(abs(x-endX)+abs(y-endY));
//奇偶性剪技,k<e或者为奇数则不可能到到达
			if(k<e|lk%2!=0) {
				return;
				for(i=e; i<4; i++) {
					int tx=x+dir[i][e],ty=y+dir[i][l];
					if(!vis[tx][ty]) {
						vis[tx][ty]=true;
						dfs(tx,ty,count+1);
						if(flag) {
							return;
						}
						vis[tx][ty]=false;
					}
				}
