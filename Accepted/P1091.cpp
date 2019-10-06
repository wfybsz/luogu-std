#include <bits/stdc++.h>
using namespace std;

const int NR = 1e2 + 10;
int n,a[NR],dp[NR],_dp[NR],maxn;

int main()
{
	cin>>n;
	_dp[n] = 1;
	for(int i = 1;i <= n;++i)
		cin>>a[i];
	for(int i = 1;i <= n;++i){
		for(int j = 0;j < i;++j)
			if(a[i] > a[j])
				dp[i] = max(dp[j] + 1,dp[i]);
	}
	for(int i = n;i >= 1;--i){
		for(int j = n + 1;j > i;--j)
			if(a[i] > a[j])
				_dp[i] = max(_dp[j] + 1,_dp[i]);
	}
	for(int i = 1;i <= n;++i)
		maxn = max(maxn,dp[i] + _dp[i] - 1);
	cout<<n - maxn;
	return 0;
}
