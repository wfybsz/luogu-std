#include <bits/stdc++.h>
using namespace std;

const int NR = 2e4 + 10;
int m,n,dp[NR],w[40];

int main(){
	cin>>m>>n;
	for(int i = 1;i <= n;++i)
		cin>>w[i];
	for(int i = 1;i <= n;++i)
		for(int j = m;j >= w[i];--j)
			dp[j] = max(dp[j],dp[j - w[i]] + w[i]);
	cout<<m - dp[m];
	return 0;
}
