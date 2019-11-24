#include <bits/stdc++.h>
using namespace std;

const int NR = 3450;
const int MR = 13e3;
int n,m,w[NR],v[NR];
int dp[MR];

int main()
{
	cin>>n>>m;
	for(int i = 1;i <= n;++i)
		cin>>w[i]>>v[i];
	for(int i = 1;i <= n;++i)
		for(int j = m;j >= w[i];--j)
			dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
	cout<<dp[m];
	return 0;
}
