#include <bits/stdc++.h>
using namespace std;

const int NR = 2e3 + 10;
int n,m,a[NR][NR],dp[NR][NR],minn = 2147483647;

int main()
{
	cin>>n>>m;
	for(int i = 1;i <= m;++i)
		for(int j = 1;j <= n;++j)
			cin>>a[i][j];
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= m;++j){
			if(j != 1)
				dp[i][j] = min(dp[i - 1][j - 1],dp[i - 1][j]) + a[j][i];
			else
				dp[i][j] = min(dp[i - 1][m],dp[i - 1][j]) + a[j][i];
		}
	for(int i = 1;i <= m;++i)
		minn = min(minn,dp[n][i]);
	cout<<minn;
	return 0;
}
