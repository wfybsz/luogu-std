#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5 + 10;
const int MR = 4e4 + 10;
int n,m,v[NR],w[NR],dp[MR],sz,vv,ww,num;

int main()
{
	cin>>n>>m;
	for(int i = 1;i <= n;++i){
		cin>>vv>>ww>>num;
		for(int j = 1;j <= num;j *= 2){
			v[++sz] = j * vv;
			w[sz] = j * ww;
			num -= j;
		}
		if(num){
			v[++sz] = vv * num;
			w[sz] = ww * num;
		}
	}
	for(int i = 1;i <= sz;++i)
		for(int j = m;j >= w[i];--j)
			dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
	cout<<dp[m];
	return 0;
}
