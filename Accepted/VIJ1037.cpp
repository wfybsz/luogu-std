#include <bits/stdc++.h>
using namespace std;

const int NR = 1e2 + 10;
const int MR = 2e3 + 10;
int n,a[NR];
bool dp[MR][MR];

int main()
{
	cin>>n;
	for(int i = 1;i <= n;++i)
		cin>>a[i];
	dp[0][0] = true;
	for(int j = 1;j <= 1000;++j)
		for(int k = 1;k <= 1000;++k)
			dp[j][k] |= dp[j - a[j]][k] or dp[j][k - a[j]];
	for(int i = 0;i <= MR;++i)
		if(!dp[i][i]){
			cout<<i - 1;
			return 0;
		}
	cout<<"Impossible";
	return 0;
}
