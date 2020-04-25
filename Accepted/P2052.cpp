#include <bits/stdc++.h>
using namespace std;

const int NR = 1e6 + 10;
const int MR = 2e6 + 10;

int n,cnt,size,head[NR];
long long fee;
struct edge{
	int u,v,w,next;
}g[MR];

void add(int u,int v,int w){
	g[++size] = (edge){u,v,w,head[u]};
	head[u] = size;
}

void dfs(int a,int fath){
	++cnt;
	for(int i = head[a];i;i = g[i].next){
		int b = g[i].v;
		if(b == fath)
			continue;
		dfs(b,a);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i = 1;i < n;++i){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i = 2;i <= 2 * n - 2;i += 2){
		cnt = 0;
		dfs(g[i].u,g[i].v);
		int d = cnt;
		cnt = 0;
		dfs(g[i].v,g[i].u);
		d -= cnt;
		fee += 1ll * abs(d) * g[i].w;
	}
	cout<<fee;
	return 0;
}
