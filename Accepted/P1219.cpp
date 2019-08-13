#include <bits/stdc++.h>
using namespace std;

const int NR = 15;
int n,a[NR],cnt;
bool flag[NR][NR];

void dfs(int step){
	if(step > n){
		cnt++;
		if(cnt > 3)
			return;
		for(int i = 1;i <= n;i++)
			cout<<a[i]<<' ';
		puts("");
		return;
	}
	bool tmp[NR][NR];
	memcpy(tmp,flag,sizeof(tmp));
	for(int i = 1;i <= n;i++){
		if(flag[step][i])
			continue;
		a[step] = i;
		for(int x = step + 1;x <= n;x++){
			int y1 = step + i - x,y2 = i,y3 = x + i - step;
			if(y1 >= 1)
				flag[x][y1] = true;
			flag[x][y2] = true;
			if(y3 <= n)
				flag[x][y3] = true;
		}
		dfs(step + 1);
		memcpy(flag,tmp,sizeof(tmp));
	}
}

int main()
{
	cin>>n;
	dfs(1);
	cout<<cnt;
	return 0;
}
