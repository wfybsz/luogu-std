#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 1e3;
int d,p,c,f,s,u,v,w,dis[NR],cnt[NR],head[NR],size,maxn = -2147483647;
bool vis[NR],flag;
struct edge{int to,next,w;}g[NR];

void add(int u,int v,int w){
	g[++size] = (edge){v,head[u],w};
	head[u] = size;
}

void spfa(int s){
	queue<int>q;
	memset(dis,-999999,sizeof(dis));
	dis[s] = d;
	q.push(s);
	while(!q.empty()){
		u = q.front();
		q.pop();
		vis[u] = false;
		for(int i = head[u];i;i = g[i].next){
			v = g[i].to;
			if(dis[u] + g[i].w > dis[v]){
				dis[v] = dis[u] + g[i].w;
				cnt[v]++;
				if(cnt[v] > c){
					flag = true;
					return;
				}
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
	d = in;p = in;c = in;f = in;s = in;
	for(int i = 1;i <= p;++i){
		u = in;v = in;
		add(u,v,d);
	}
	for(int i = 1;i <= f;++i){
		u = in;v = in;w = in;
		add(u,v,d - w);
	}
	spfa(s);
	if(flag)
		print(-1);
	else{
		for(int i = 1;i <= c;++i)
			maxn = max(maxn,dis[i]);
		print(maxn);
	}
	return 0;
}
