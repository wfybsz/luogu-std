#include <bits/stdc++.h>
using namespace std;

const int NR = 2e5 + 10;
int n,dp[NR] = {1};
struct node{
	int n,s;
}a[NR];

bool cmp(node a,node b){
	return a.n < b.n;
}

int main()
{
	cin>>n;
	for(int i = 1;i <= n;++i)
		cin>>a[i].n>>a[i].s;
	sort(a + 1,a + n + 1,cmp);
	for(int i = 1;i <= n;++i){
		//dp[i] =
	}
	return 0;
}
