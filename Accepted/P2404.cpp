#include <bits/stdc++.h>
using namespace std;

const int NR = 10;
int n,a[NR];

void dfs(int x,int min,int step){
	if(!x){
		if(step == 2)
			return;
		printf("%d",a[1]);
		for(int i = 2;i < step;i++)
			printf("+%d",a[i]);
		puts("");
		return;
	}
	if(x < min)
		return;
	for(int i = min;i <= x;i++){
		a[step] = i;
		dfs(x - i,i,step + 1);
	}
}

int main()
{
	cin>>n;
	dfs(n,1,1);
	return 0;
}
