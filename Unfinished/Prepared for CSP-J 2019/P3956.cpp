#include <bits/stdc++.h>
using namespace std;

const int MAX = 2147483647;
const int NR = 1e2 + 10;
const int mv[4][2] = {-1,0,0,-1,1,0,0,1};
int n,m,ans = MAX,a[NR][NR],b[NR][NR],x,y,z;

void dfs(int x,int y,int tot,bool mag = false){
	if(x < 1 or y < 1 or x > m or y > m)
		return;
	b[x][y] = tot;
	if(x == m and y == m){
		if(tot < ans)
			ans = tot;
		return;
	}
	for(int i = 0;i < 4;++i){
		int xn = x + mv[i][0],yn = y + mv[i][1];
		if(a[xn][yn]){
			if(a[xn][yn] == a[x][y])
				dfs(xn,yn,tot);
			else
				dfs(xn,yn,tot + 1);
		}else if(!mag){
			a[xn][yn] = a[x][y];
			dfs(xn,yn,tot + 2,true);
			a[xn][yn] = 0;
		}
	}
}

int main()
{
	memset(b,0x7f,sizeof(b));
	cin>>m>>n;
	for(int i = 1;i <= n;++i){
		cin>>x>>y>>z;
		a[x][y] = ++z;
	}
	dfs(1,1,0);
	if(ans == MAX)
		cout<<-1;
	else
		cout<<ans;
	return 0;
}
