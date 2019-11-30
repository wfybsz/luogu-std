#include <bits/stdc++.h>
using namespace std;

const int NR = 2e4 + 10;
int m,n,dp[NR],w[40];

int main(){
	scanf("%d%d",&m,&n);
	for(int i = 1;i <= n;++i)
		cin>>w[i];
	for(int i = 1;i <= n;++i)
		for(j = m;j >= w[i];--j)
			if(dp[j] < dp[j - w[i]] + w[i])
				dp[j] = dp[j - w[i]] + w[i];
	cout<<m - dp[m];
	return 0;
}
