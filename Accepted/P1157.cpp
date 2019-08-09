#include <bits/stdc++.h>
using namespace std;

int n,r,a[10000];

void dfs(int min,int step){
	if(step > r){
		for(int i = 1;i <= r;i++)
			printf("%3d",a[i]);
		puts("");
		return;
	}
	for(int i = min;i <= n;i++){
		a[step] = i;
		dfs(i + 1,step + 1);
	}
}

int main()
{
	cin>>n>>r;
	dfs(1,1);
	return 0;
}
