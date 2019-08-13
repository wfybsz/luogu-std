#include <bits/stdc++.h>
using namespace std;

const int NR = 100;
int n,a[NR],cnt;
int flag[NR][NR];

void put(int step,int i){
	flag[step][i]++;
	for(int x = step + 1;x <= n;x++){
		flag[x][step + i - x]++;
		flag[x][i]++;
		flag[x][x + i - step]++;
	}
}

void undo(int step,int i){
	flag[step][i]--;
	for(int x = step + 1;x <= n;x++){
		flag[x][step + i - x]--;
		flag[x][i]--;
		flag[x][x + i - step]--;
	}
}

void dfs(int step){
	if(step > n){
		if(cnt <= 2){
			for(int i = 1;i <= n;i++)
				cout<<a[i]<<' ';
			puts("");
		}
		cnt++;
		return;
	}
	for(int i = 1;i <= n;i++){
		if(flag[step][i]){
			continue;
		}
		a[step] = i;
		put(step,i);
		dfs(step + 1);
		undo(step,i);
	}
}

int main()
{
	cin>>n;
	dfs(1);
	cout<<cnt;
	return 0;
}
