#include <bits/stdc++.h>
using namespace std;

int n,m,a[110][110],maxn = -1,flag[110][110],mv[4][2] = {{1,0},{-1,0},{0,1},{0,-1}},mem[110][110];

int dfs(int x,int y){
	if(x < 1 || x > n || y < 1 || y > m)
		return -2000000000;
	if(mem[x][y] != -1)
		return mem[x][y];
	int maxm = 1;
	for(int i = 0;i < 4;i++){
		int xn = x + mv[i][0],yn = y + mv[i][1];
		if(flag[x][y] || a[x][y] <= a[xn][yn])
			continue;
		flag[x][y] = true;
		maxm = max(maxm,dfs(xn,yn) + 1);
		flag[x][y] = false;
	}
	mem[x][y] = maxm;
	return maxm;
}

int main()
{
	memset(mem,-1,sizeof(mem));
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			cin>>a[i][j];
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			maxn = max(maxn,dfs(i,j));
	cout<<maxn;
	return 0;
}
