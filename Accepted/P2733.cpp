#include <bits/stdc++.h>
using namespace std;

const int NR = 300;
int n,tmp,dp[NR][NR],cnt[NR];
bool a[NR][NR];
char c;

int main()
{
	cin>>n;
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= n;++j){
			cin>>c;
			a[i][j] = c == '1';
		}
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= n;++j)
			if(a[i][j])
				dp[i][j] = min(min(dp[i - 1][j],dp[i][j - 1]),dp[i - 1][j - 1]) + 1;
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= n;++j)
			for(int k = 1;k <= n;++k)
				if(k <= dp[i][j])
					++cnt[k];
				else
					continue;
	for(int i = 2;i <= n;++i)
		if(cnt[i])
			cout<<i<<' '<<cnt[i]<<endl;
		else
			break;
	return 0;
}
