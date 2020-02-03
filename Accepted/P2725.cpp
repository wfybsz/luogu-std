#include <bits/stdc++.h>
using namespace std;

const int NR = 2e6 + 10;
int k,n,f[NR],w[60],cnt,ans;

int main()
{
	for(int i = 1;i < NR;++i)
		f[i] = 20050923;
	f[0] = 0;
	cin>>k>>n;
	for(int i = 1;i <= n;++i)
		cin>>w[i];
	for(int i = 1;i <= n;++i)
		for(int j = w[i];j <= NR;++j)
			f[j] = min(f[j],f[j - w[i]] + 1);
	for(int i = 1;i <= NR;++i){
		if(f[i] != 20050923 and f[i] <= k)
			++cnt;
		else
			cnt = 0;
		ans = max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
