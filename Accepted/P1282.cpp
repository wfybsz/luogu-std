#include <bits/stdc++.h>
using namespace std;

const int NR = 1e3 + 10;
int n,a[NR],b[NR],dp[NR][NR * 6],sum,mindif = 2147483647,minrot = 2147483647;

int main()
{
	memset(dp,999999,sizeof(dp));
	dp[0][0] = 0;
	cin>>n;
	for(int i = 1;i <= n;++i){
		cin>>a[i]>>b[i];
		sum += a[i] + b[i];
	}
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= 6 * i;++j){
			if(j >= a[i])
				dp[i][j] = min(dp[i][j],dp[i - 1][j - a[i]]);
			if(j >= b[i])
				dp[i][j] = min(dp[i][j],dp[i - 1][j - b[i]] + 1);
		}
	for(int j = 1;j <= 6 * n;++j){
		if(dp[n][j] <= n and abs(sum - j - j) == mindif)
			minrot = min(minrot,dp[n][j]);
		if(dp[n][j] <= n and abs(sum - j - j) < mindif){
			mindif = abs(sum - j - j);
			minrot = dp[n][j];
		}
	}
	cout<<minrot;
	return 0;
}
