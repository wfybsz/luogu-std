#include <bits/stdc++.h>
using namespace std;

const int NR = 30;
const int MR = 5e4;
int n,m,w[NR],v[NR],dp[MR];

int main()
{
	cin>>m>>n;
	for(int i = 1;i <= n;++i){
		cin>>v[i]>>w[i];
		w[i] *= v[i];
	}
	for(int i = 1;i <= n;++i)
		for(int j = m;j >= v[i];--j)
			if(j >= v[i])
				dp[j]=max(dp[j],dp[j - v[i]] + w[i]);
	cout<<dp[m];
	return 0;
}
