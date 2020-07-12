#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 1e4 + 10;
const int MR = 5e4 + 10;
int n,m,size,size_,u,v,w,w_,dis1[NR],dis2[NR],dis3[NR],head[NR];
bool vis[NR];
struct edge{int from,to,w,w_;}g[MR];
struct edge_{int next,to,w;}g_[MR];
struct qu{
	int to,w;
	bool operator<(const qu&b)const{return w > b.w;}
};
priority_queue<qu>q;

void add(int u,int v,int w){
	g_[++size_] = (edge_){head[u],v,w};
	head[u] = size_;
}

void dij(int u,int dis[]){
	qu tmp;
	for(int i = 1;i <= n;++i){
		dis[i] = 2147483647;
		vis[i] = false;
	}
	tmp.to = u;
	tmp.w = 0;
	dis[u]=0;
	q.push(tmp);
	while(!q.empty()){
		u = q.top().to;
		q.pop();
		if(vis[u])
			continue;
		vis[u] = true;
		for(int i = head[u];i;i = g_[i].next){
			v = g_[i].to;
			if(!vis[v] and dis[u] + g_[i].w < dis[v]){
				dis[v] = dis[u] + g_[i].w;
				tmp.to = v;
				tmp.w = dis[v];
				q.push(tmp);
			}
		}
	}
}

int main()
{
	n = in;m = in;
	for(int i = 1;i <= m;++i){
		g[i].to = in;
		g[i].from = in;
		g[i].w = in;
		g[i].w_ = in;
	}
	memset(head,0,sizeof(head));
	memset(g_,0,sizeof(g_));
	size_ = 0;
	for(int i = 1;i <= m;++i)
		add(g[i].from,g[i].to,g[i].w);
	dij(n,dis1);
	memset(head,0,sizeof(head));
	memset(g_,0,sizeof(g_));
	size_ = 0;
	for(int i = 1;i <= m;++i)
		add(g[i].from,g[i].to,g[i].w_);
	dij(n,dis2);
	memset(head,0,sizeof(head));
	memset(g_,0,sizeof(g_));
	size_ = 0;
	for(int i = 1;i <= m;++i){
		int cnt = 0;
		if(dis1[g[i].to] != dis1[g[i].from] + g[i].w)
			++cnt;
		if(dis2[g[i].to] != dis2[g[i].from] + g[i].w_)
			++cnt;
		add(g[i].from,g[i].to,cnt);
	}
	dij(n,dis3);
	print(dis3[1]);
	return 0;
}
