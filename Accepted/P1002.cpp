#include <bits/stdc++.h>
using namespace std;

const int mv[8][2] = {
	1 , 2,
	1 ,-2,
	-1, 2,
	-1,-2,
	2 , 1,
	2 ,-1,
	-2, 1,
	-2,-1
},NR = 25;
int n,m,_n,_m,dp[NR][NR] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1},
	{1},
	{1},
	{1},
	{1},
	{1},
	{1},
	{1},
	{1},
	{1},
	{1},
	{1},
	{1},
	{1},
	{1},
	{1},
	{1},
	{1},
	{1},
	{1},
	{1},
};
bool flag[NR][NR];

int main()
{
	cin>>n>>m>>_n>>_m;
	flag[_n][_m] = true;
	for(int i = 0;i < 8;++i){
		int x = _n + mv[i][0],y = _m + mv[i][1];
		if(x < 1 or x > n or y < 0 or y > m)
			continue;
		flag[x][y] = true;
	}
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= m;++j){
			if(flag[i][j])
				continue;
			dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
		}
	cout<<dp[n][m]<<endl;
	return 0;
}
