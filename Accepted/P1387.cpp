#include <bits/stdc++.h>
using namespace std;

const int NR = 1e2 + 10;
int n,m,dp[NR][NR],maxn,tmp;
bool a[NR][NR];

int main()
{
	cin>>n>>m;
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= m;++j){
			cin>>tmp;
			a[i][j] = tmp;
			if(a[i][j]){
				dp[i][j] = min(min(dp[i - 1][j],dp[i][j - 1]),dp[i - 1][j - 1]) + 1;
				maxn = max(maxn,dp[i][j]);
			}
		}
	cout<<maxn;
	return 0;
}
