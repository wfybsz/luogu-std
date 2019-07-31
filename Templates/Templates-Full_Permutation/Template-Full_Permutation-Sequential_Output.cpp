#include <bits/stdc++.h>
using namespace std;

int p[10] = {0},n = 4;
bool vis[10] = {0};

void dfs(int x){
	if(x == n + 1){
		for(int i = 1;i <= n;i++)
			cout<<p[i]<<' ';
		puts("");
		return;
	}
	for(int i = 1;i <= n;i++)
		if(vis[i] == false && i > p[x]){
			p[x] = i;
			vis[i] = true;
			dfs(x + 1);
			vis[i] = false;
		}
}

int main()
{
	dfs(1);
	return 0;
}
