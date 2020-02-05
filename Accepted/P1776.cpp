#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5 + 10;
const int MR = 4e4 + 10;
int n,m,v[NR],w[NR],dp[MR];
int tmp,vv,ww,num;

int main()
{
	cin>>n>>m;
	for(int i = 1;i <= n;++i){
		cin>>vv>>ww>>num;
		for(int j = 1;j <= num;j *= 2){
			num -= j;
			v[++tmp] = j * vv;
			w[tmp] = j * ww;
		}
		if(num){
			v[++tmp] = vv * num;
			w[tmp] = ww * num;
		}
	}
	for(int i = 1;i <= tmp;++i)
		for(int j = m;j >= w[i];--j)
			dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
	cout<<dp[m];
	return 0;
}
