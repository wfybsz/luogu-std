#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int NR = 1e2 + 10;
const int MR = 2e3 + 10;
int n,m,a[NR][MR];
long long cnt;

namespace qwq{
	long long dp[50][600][600];
	//f[i][j][k] i methods, j dishes, k dish[2]fas
	void solve(){
		memset(dp,0,sizeof(dp));
		dp[0][0][0] = 1;
		for(int i = 1;i <= n;++i)
			for(int j = 0;j <= i;++j)
				for(int k = 0;k <= i - j;++k){
					dp[i][j][k] = dp[i - 1][j][k];
					if(j >= 1){
						dp[i][j][k] += dp[i - 1][j - 1][k] * a[i][1] % MOD;
						dp[i][j][k] %= MOD;
					}
					if(k >= 1){
						dp[i][j][k] += dp[i - 1][j][k - 1] * a[i][2] % MOD;
						dp[i][j][k] %= MOD;
					}

				}
		for(int i = 1;i <= n / 2;++i){
			cnt += dp[n][i][i];
			cnt %= MOD;
		}
	}
}

namespace m3{
	long long dp[50][50][50][50];
	dp[0][0][0][0] = 1;
	for(int i = 1;i <= n;++i)
		for(int j = 0;j <= i;++j)
			for(int k = 0;k <= i - j;++k)
				for(int l = 0;l <= i - j - k;++l){
					fp[i][j][k][l] = f[i - 1][j][k][l];
					if(j >= 1){
						dp[i][j][k][l] += dp[i - 1][j - 1][k][l] * a[i][1];
						
					}
				}
}

int main()
{
	cin>>n>>m;
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= m;++j)
			cin>>a[i][j];
	if(m == 2)
		qwq::solve();
	if(m == 3)
		m3::solve();
	cout<<cnt;
	return 0;
}
