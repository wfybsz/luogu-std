#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int NR = 1e3 + 10;
int n,dp[NR],sum[NR],maxn = -2e9;

int main()
{
	memset(dp,-999999,sizeof(dp));
	cin>>n;
	for(int i = 1;i <= n;++i){
		cin>>sum[i];
		sum[i] += sum[i - 1];
	}
	dp[0] = 0;
	for(int i = 1;i <= n;++i){
		for(int j = 0;j < i;++j)
			if(sum[i] - sum[j] >= 0)
				dp[i] = max(dp[j] + 1,dp[i]);
	}
	if(dp[n] < -1e9)
		cout<<"Impossible";
	else
		cout<<dp[n];
	return 0;
}
