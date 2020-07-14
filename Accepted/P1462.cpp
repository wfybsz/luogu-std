#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 1e4 + 10;
const int MR = 1e5 + 10;
int n,m,b,u,v,w,size,head[NR],dis[NR],cnt[NR],node[NR],node_[NR],l = 1,r,mid,ans;
bool vis[NR];
struct edge{int to,next,w;}g[MR];

void add(int u,int v,int w){
	g[++size] = (edge){v,head[u],w};
	head[u] = size;
}

bool spfa(int s,int maxn){
	queue<int>q;
	memset(dis,999999,sizeof(dis));
	dis[s] = 0;
	vis[s] = true;
	q.push(s);
	while(!q.empty()){
		u = q.front();
		q.pop();
		vis[u] = false;
		for(int i = head[u];i;i = g[i].next){
			v = g[i].to;
			if(dis[u] + g[i].w < dis[v] and node[v] <= maxn){
				dis[v] = dis[u] + g[i].w;
				if(!vis[v]){
					q.push(v);
					vis[v] = true;
				}
			}
		}
	}
	return dis[n] <= b;
}

int main()
{
	n = r = in;m = in;b = in;
	for(int i = 1;i <= n;++i)
		node[i] = node_[i] = in;
	for(int i = 1;i <= m;++i){
		u = in;v = in;w = in;
		add(u,v,w);
		add(v,u,w);
	}
	sort(node_ + 1,node_ + n + 1);
	if(!spfa(1,2147483647)){
		printf("AFK\n");
		return 0;
	}
	while(l <= r){
		mid = (l + r) / 2;
		if(spfa(1,node_[mid])){
			ans = node_[mid];
			r = mid - 1;
		}else
			l = mid + 1;
	}
	print(ans);
	return 0;
}
