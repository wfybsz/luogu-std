#include <bits/stdc++.h>
using namespace std;

const int NR = 10;
int n,a[NR];
bool flag[NR];

void dfs(int x){
	if(x > n){
		for(int i = 1;i <= n;i++)
			printf("%5d",a[i]);
		puts("");
		return;
	}
	for(int i = 1;i <= n;i++){
		if(!flag[i]){
			flag[i] = true;
			a[x] = i;
			dfs(x + 1);
			flag[i] = false;
		}
	}
}

int main()
{
	cin>>n;
	dfs(1);
	return 0;
}
