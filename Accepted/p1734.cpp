#include <bits/stdc++.h>
using namespace std;

int s,dp[10000],w[10000],v[10000];

int f(int x){
	int ret = 0;
	for(int i = 1;i <= x / 2;++i)
		ret += (x % i == 0)?i:0;
	return ret;
}

int main()
{
	cin>>s;
	for(int i = 1;i <= s;++i){
		w[i] = i;
		v[i] = f(i);
	}
	for(int i = 1;i <= s;++i)
		for(int j = s;j >= w[i];--j)
			dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
	cout<<dp[s];
	return 0;
}
