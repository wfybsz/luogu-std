#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int NR = 1e5 + 10;
ll dp[NR],ans;
int t,n,i,j;
struct node{
	ll a,b,c;
}a[NR];

bool cmp(node a,node b){
	return a.c * b.b < b.c * a.b;
}

int main(){
	cin>>t>>n;
	for(i = 0;i < n;++i)
		cin>>a[i].a;
	for(i = 0;i < n;++i)
		cin>>a[i].b;
	for(i = 0;i < n;++i)
		cin>>a[i].c;
	sort(a,a + n,cmp);
	memset(dp,999999,sizeof(dp));
	dp[0] = 0;
	for(i = 0;i < n;++i){
		for(j = t;j >= 0;--j)
			if(dp[j] != -1 && j + a[i].c <= t)
				dp[j + a[i].c] = max(dp[j + a[i].c],dp[j] + a[i].a -(j + a[i].c) * a[i].b);
	}
	for(i = 0;i <= t;++i)
		ans = max(ans,dp[i]);
	cout<<ans<<endl;
}
