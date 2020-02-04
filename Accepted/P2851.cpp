#include <bits/stdc++.h>
using namespace std;

const int NR = 4e4;
int n,t,ans = 1e9,v[2100],w1[110],w2[2100],dp1[NR + 10],dp2[NR + 10],sz,c;

int main()
{
	memset(dp2,999999,sizeof(dp2));
	memset(dp1,999999,sizeof(dp1));
	cin>>n>>t;
	for(int i = 1;i <= n;i++)
		cin>>w1[i];
	for(int i = 1;i <= n;i++){
		cin>>c;
		for(int j = 1;j <= c;j *= 2){
			w2[++sz] = w1[i] * j;
			v[sz] = j;
			c -= j;
		}
		if(c){
			w2[++sz] = w1[i] * c;
			v[sz] = c;
		}
	}
	for(int i = 1;i <= sz;i++)
		for(int j = NR;j >= w2[i];j--)
			dp2[j] = min(dp2[j],dp2[j - w2[i]] + v[i]);
	for(int i = 1;i <= n;++i)
		for(int j = w1[i];j <= NR - t;++j)
			dp1[j] = min(dp1[j],dp1[j - w1[i]] + v[i]);
	for(int i = t;i <= NR;++i)
		ans = min(ans,dp2[i] + dp1[i - t]);
	cout<<ans;
	return 0;
}
