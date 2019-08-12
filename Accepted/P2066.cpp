#include <bits/stdc++.h>
using namespace std;

const int NR = 1e3;
int n,m,a[NR][NR],num[NR],ans[NR],maxn;

int cal(){
	int cnt = 0;
	for(int i = 1;i <= n;i++)
		cnt += a[i][num[i]];
	return cnt;
}

void dfs(int tot,int step){
	if(tot < 0)
		return;
	if(step == n){
		num[step] = tot;
		if(cal() > maxn){
			maxn = cal();
			for(int i = 1;i <= step;i++)
				ans[i] = num[i];
		}
		return;
	}
	for(int i = 0;i <= tot;i++){
		num[step] = i;
		dfs(tot - i,step + 1);
	}
}

int main()
{
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			cin>>a[i][j];
	dfs(m,1);
	cout<<maxn<<endl;
	for(int i = 1;i <= n;i++)
		cout<<i<<' '<<ans[i]<<endl;
	return 0;
}
