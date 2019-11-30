#include <bits/stdc++.h>
using namespace std;

const int NR = 410;
const int MR = 3.5e4;
int n,iq[NR],eq[NR],dp[NR][2 * MR + 10],ans;

int main()
{
	cin>>n;
	for(int i = 1;i <= n;++i)
		cin>>iq[i]>>eq[i];
	memset(dp,-999999,sizeof(dp));
	dp[0][0 + MR] = 0;
	for(int i = 1;i <= n;++i)
		for(int j = -MR;j <= MR;++j){
			dp[i][j + MR] = dp[i - 1][j + MR];
			if(0 <= j + MR - iq[i] and j + MR - iq[i] <= 2 * MR)
				dp[i][j + MR] = max(dp[i][j + MR],dp[i - 1][j + MR - iq[i]] + eq[i]);
		}
	for(int i = 0;i <= MR;++i)
		if(dp[n][i + MR] >= 0)
			ans = max(ans,dp[n][i + MR] + j);
	cout<<ans<<endl;
	return 0;
}
