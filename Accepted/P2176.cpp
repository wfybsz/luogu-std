#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 1e2 + 10;
const int MR = 1e4 + 10;
int n,m,u,v,w,size,head[NR],dis[NR],maxn = -1,tmp;
bool vis[NR];
struct edge{int to,next,w;}g[MR];

void add(int u,int v,int w){
	g[++size] = (edge){v,head[u],w};
	head[u] = size;
}

void spfa(int s){
	deque<int>q;
	memset(dis,999999,sizeof(dis));
	dis[s] = 0;
	q.push_back(s);
	while(!q.empty()){
		u = q.front();
		q.pop_front();
		vis[u] = false;
		for(int i = head[u];i;i = g[i].next){
			v = g[i].to;
			if(dis[u] + g[i].w < dis[v]){
				dis[v] = dis[u] + g[i].w;
				if(!vis[v]){
					vis[v] = true;
					if(q.empty() or dis[v] > dis[q.front()])
						q.push_back(v);
					else
						q.push_front(v);
				}
			}
		}
	}
}

int main()
{
	n = in;m = in;
	for(int i = 1;i <= m;++i){
		u = in;v = in;w = in;
		add(u,v,w);
		add(v,u,w);
	}
	spfa(1);
	tmp = dis[n];
	for(int i = 1;i <= m;i += 2){
		g[i].w *= 2;
		g[i + 1].w *= 2;
		spfa(1);
		maxn = max(maxn,dis[n] - tmp);
		g[i].w /= 2;
		g[i + 1].w /= 2;
	}
	print(maxn);
	return 0;
}
