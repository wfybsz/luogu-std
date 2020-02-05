#include <bits/stdc++.h>
using namespace std;

const int NR = 10;
int n,a[NR][NR],dp[2 * NR][NR][NR],x = 1,y,tmp,x_,y_;

int main()
{
	cin>>n;
	while(x || y || tmp){
		cin>>x>>y>>tmp;
		a[x][y] = tmp;
	}
	dp[2][1][1] = a[1][1];
	for(int k = 3;k <= 2 * n;++k)
		for(int x1 = max(k - n,1);x1 <= min(k - 1,n);++x1)
			for(int x2 = max(k - n,1);x2 <= min(k - 1,n);++x2){
				int y1 = k - x1,y2 = k - x2;
				dp[k][x1][x2] = max(dp[k - 1][x1][x2],dp[k][x1][x2]);
				dp[k][x1][x2] = max(dp[k - 1][x1 - 1][x2],dp[k][x1][x2]);
				dp[k][x1][x2] = max(dp[k - 1][x1][x2 - 1],dp[k][x1][x2]);
				dp[k][x1][x2] = max(dp[k - 1][x1 - 1][x2 - 1],dp[k][x1][x2]);
				dp[k][x1][x2] += a[x1][y1];
				if(x1 != x2)
					dp[k][x1][x2] += a[x2][y2];
			}
	cout<<dp[2 * n][n][n];
	return 0;
}
