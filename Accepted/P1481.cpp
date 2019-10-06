#include <bits/stdc++.h>
using namespace std;

const int NR = 2e3 + 10;
int n,dp[NR],maxn;
char a[NR][1000];

int main()
{
	cin>>n;
	for(int i = 1;i <= n;++i)
		scanf("%s",a[i]);
	for(int i = 1;i <= n;++i){
		for(int j = 0;j < i;++j)
			if(strstr(a[i],a[j]) == a[i])
				dp[i] = max(dp[j] + 1,dp[i]);
		maxn = max(maxn,dp[i]);
	}
	cout<<maxn;
	return 0;
}
