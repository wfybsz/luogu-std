#include <bits/stdc++.h>
using namespace std;

struct node{int x,y;}point,t;
const int dx[4] = {1,-1,2,-2},dy[4] = {1,-1,2,-2};
int a[410][410];
bool b[410][410];
int n,m;

void bfs(int x,int y,int step){
	a[x][y] = step;
	b[x][y] = false;
	queue<node>q;
	point.x = x;
	point.y = y;
	q.push(point);
	while(!q.empty()){
		t = q.front();
		q.pop();
		for(int i = 0;i < 4;++i)
			for(int j = 0;j < 4;++j)
				if(abs(dx[i]) != abs(dy[j])){
					int xn = t.x + dx[i],yn = t.y + dy[j];
					if(xn < 1 || xn > n || yn < 1 || yn > m)
						continue;
					if(b[xn][yn]){
						point.x = xn;
						point.y = yn;
						q.push(point);
						b[xn][yn] = false;
						a[xn][yn] = a[t.x][t.y] + 1;
					}
				}
	}
}

int main(){
	memset(b,1,sizeof(b));
	memset(a,-1,sizeof(a));
	int x,y;
	cin>>n>>m>>x>>y;
	bfs(x,y,0);
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= m;++j)
			printf("%-5d",a[i][j]);
		putchar('\n');
	}
	return 0;
}
