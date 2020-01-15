#include <bits/stdc++.h>
using namespace std;

const int NR = 1e2 + 10;
const int MR = 1e4 + 10;
int n,m,cost[NR],dp[NR][MR];

int main()
{
	cin>>n>>m;
	for(int i = 1;i <= n;++i)
		cin>>cost[i];
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= m;++j){
			if(j == cost[i])
				dp[i][j] = dp[i - 1][j] + 1;
			if(j > cost[i])
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - cost[i]];
			if(j < cost[i])
				dp[i][j] = dp[i - 1][j];
		}
	cout<<dp[n][m];
	return 0;
}
