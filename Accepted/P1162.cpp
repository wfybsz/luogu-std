#include <bits/stdc++.h>
using namespace std;

const int NR = 40,p[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int n,a[NR][NR];

void dfs(int x,int y){
	if(x < 0 || x > n + 1 || y < 0 || y > n + 1)
		return;
	a[x][y] = 3;
	for(int i = 0;i < 4;i++)
		if(!a[x + p[i][0]][y + p[i][1]])
			dfs(x + p[i][0],y + p[i][1]);
}

int main()
{
	cin>>n;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			cin>>a[i][j];
	dfs(0,0);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			switch(a[i][j]){
				case 3:putchar('0');break;
				case 1:putchar('1');break;
				case 0:putchar('2');break;
			}
			putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}
