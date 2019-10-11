#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int NR = 25;
const int mv[8][2] = {
	1,2,-1,2,1,-2,-1,-2,
	2,1,2,-1,-2,1,-2,-1
};
int n,m,hn,hm,dp[NR][NR] = {{},1};
bool flag[NR][NR];

void put(int x,int y){
	flag[x][y] = true;
	dp[x][y] = 0;
}

int main()
{
	cin>>n>>m>>hn>>hm;
	put(hn,hm);
	for(int i = 0;i < 8;++i){
		int x = hn + mv[i][0],y = hm + mv[i][1];
		if(x < 0 or x > n or y < 0 or y > m)
			continue;
		put(x,y);
	}
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= m;++j){
			if(flag[i][j])
				continue;
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
		}
	}
	for(int i = 0;i <= n;++i){
		for(int j = 0;j <= m;++j)
			cout<<flag[i][j]<<' ';
		cout<<endl;
	}
	cout<<endl;
	for(int i = 0;i <= n;++i){
		for(int j = 0;j <= m;++j)
			printf("%-7d",dp[i][j]);
		putchar('\n');
	}
	cout<<dp[n][m]<<endl;
	return 0;
}
