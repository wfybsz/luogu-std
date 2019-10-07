#include <bits/stdc++.h>
using namespace std;

const int NR = 2e3 + 10;
int n,dp[NR],maxn;
char a[NR][1000];

bool instr(char a[],char b[]){
	int len = strlen(b);
	if(strlen(a) < len)
		return false;
	for(int i = 0;i < len;++i)
		if(a[i] != b[i])
			return false;
	return true;
}

int main()
{
	cin>>n;
	for(int i = 1;i <= n;++i)
		scanf("%s",a[i]);
	for(int i = 1;i <= n;++i){
		for(int j = 0;j < i;++j)
			if(instr(a[i],a[j]))
				dp[i] = max(dp[j] + 1,dp[i]);
		maxn = max(maxn,dp[i]);
	}
	cout<<maxn;
	return 0;
}
