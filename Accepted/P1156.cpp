#include <bits/stdc++.h>
using namespace std;

const int MR = 125;
const int NR = 110;
int m,n,dp[NR][MR + 10];
struct rb{
	int t,e,h;
}a[NR];
// dp[i][j] 前i堆垃圾高度恰好为j时能量的最大值

bool cmp(rb x,rb y){
	return x.t < y.t;
}

int main()
{
	cin>>m>>n;
	for(int i = 1;i <= n;i++)
		cin>>a[i].t>>a[i].e>>a[i].h;
	sort(a + 1,a + 1 + n,cmp);
	memset(dp,-999999,sizeof(dp));
	dp[0][0] = 10;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= m + a[i].h;j++){
			// 堆起来
			if(j >= a[i].h && dp[i - 1][j - a[i].h] >= 0)
				dp[i][j] = max(dp[i][j],dp[i - 1][j - a[i].h] -(a[i].t - a[i - 1].t));
			// 吃掉
			if(dp[i - 1][j] - (a[i].t - a[i - 1].t) >= 0)
				dp[i][j] = max(dp[i][j],dp[i - 1][j] - (a[i].t - a[i - 1].t));
			// 出去了
			if(j >= m && dp[i][j] >= 0){
				cout<<a[i].t;
				return 0;
			}
			// 饿死了
			if(j == 0 && dp[i][j] < 0){
				cout<<a[i - 1].t + dp[i - 1][0];
				return 0;
			}
		}
	}
	cout<<a[n].t + dp[n][0];
	return 0;
}
