#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 4e4 + 10;
int n,m,b,e,p,dis[3][NR],size,head[NR],u,v,minn = 2147483647;
bool vis[NR];
struct edge{int to,next,w;}g[NR];

void add(int u,int v,int w){
	g[++size] = (edge){v,head[u],w};
	head[u] = size;
}

void spfa(int s,int id){
	queue<int>q;
	memset(dis[id],999999,sizeof(dis[id]));
	memset(vis,false,sizeof(vis));
	dis[id][s] = 0;
	q.push(s);
	while(!q.empty()){
		u = q.front();
		q.pop();
		vis[u] = false;
		for(int i = head[u];i;i = g[i].next){
			v = g[i].to;
			if(dis[id][u] + g[i].w < dis[id][v]){
				dis[id][v] = dis[id][u] + g[i].w;
				if(!vis[v]){
					q.push(v);
					vis[v] = true;
				}
			}
		}
	}
}

int main()
{
	b = in;e = in;p = in;n = in;m = in;
	for(int i = 1;i <= m;++i){
		u = in;v = in;
		add(u,v,1);
		add(v,u,1);
	}
	spfa(1,0);
	spfa(2,1);
	spfa(n,2);
	for(int i = 1;i <= n;++i)
		minn = min(minn,b * dis[0][i] + e * dis[1][i] + p * dis[2][i]);
	print(minn);
	return 0;
}
