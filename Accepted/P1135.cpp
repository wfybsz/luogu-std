#include <bits/stdc++.h>
using namespace std;

const int NR = 210;
int n,a,b,k[NR],minn[NR];

void dfs(int fl,int step){
	if(minn[fl] <= step)
		return;
	minn[fl] = step;
	if(fl + k[fl] <= n)
		dfs(fl + k[fl],step + 1);
	if(fl - k[fl] > 0)
		dfs(fl - k[fl],step + 1);
}

int main()
{
	cin>>n>>a>>b;
	for(int i = 1;i <= n;i++)
		cin>>k[i];
	memset(minn,999999,sizeof(minn));
	dfs(a,0);
	if(minn[b] > 1e9)
		cout<<-1;
	else
		cout<<minn[b];
	return 0;
}
