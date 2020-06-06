#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 1e3 + 10;
const int MR = 1e5 + 10;
int n,m,x,size,size_,head[NR],head_[NR],dis[NR],dis_[NR],u,v,w,maxn;
bool flag[NR],flag_[NR];
struct edge{
	int to,next,w;
}g[MR],g_[MR];

void add(int u,int v,int w){
	g[++size] = (edge){v,head[u],w};
	head[u] = size;
}

void add_(int u,int v,int w){
	g_[++size_] = (edge){v,head_[u],w};
	head_[u] = size_;
}

void spfa(int s){
	queue<int>q;
	q.push(s);
	memset(dis,999999,sizeof(dis));
	dis[s] = 0;
	while(!q.empty()){
		u = q.front();
		q.pop();
		flag[u] = false;
		for(int i = head[u];i;i = g[i].next){
			v = g[i].to,w = g[i].w;
			if(dis[u] + w >= dis[v])
				continue;
			dis[v] = dis[u] + w;
			if(flag[v])
				continue;
			flag[v] = true;
			q.push(v);
		}
	}
}

void spfa_(int s){
	queue<int>q;
	q.push(s);
	memset(dis_,999999,sizeof(dis_));
	dis_[s] = 0;
	while(!q.empty()){
		u = q.front();
		q.pop();
		flag_[u] = false;
		for(int i = head_[u];i;i = g_[i].next){
			v = g_[i].to,w = g_[i].w;
			if(dis_[u] + w >= dis_[v])
				continue;
			dis_[v] = dis_[u] + w;
			if(flag_[v])
				continue;
			flag_[v] = true;
			q.push(v);
		}
	}
}

int main()
{
	n = in;m = in;x = in;
	while(m--){
		u = in;v = in;w = in;
		add(u,v,w);
		add_(v,u,w);
	}
	spfa(x);
	spfa_(x);
	for(int i = 1;i <= n;++i)
		maxn = max(maxn,dis[i] + dis_[i]);
	print(maxn);
	return 0;
}
