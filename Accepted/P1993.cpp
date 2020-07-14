#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 5e3 + 10;
int n,m,x,u,v,w,size,head[NR],dis[NR],cnt[NR];
bool vis[NR];
struct edge{int to,next,w;}g[NR<<1];

void add(int u,int v,int w){
	g[++size] = (edge){v,head[u],w};
	head[u] = size;
}

bool spfa(int s){
	queue<int>q;
	memset(dis,999999,sizeof(dis));
	dis[s] = 0;
	q.push(s);
	while(!q.empty()){
		u = q.front();
		q.pop();
		vis[u] = false;
		for(int i = head[u];i;i = g[i].next){
			v = g[i].to;
			if(dis[u] + g[i].w < dis[v]){
				dis[v] = dis[u] + g[i].w;
				cnt[v] = cnt[u] + 1;
				if(!vis[v]){
					q.push(v);
					vis[v] = true;
				}
				if(cnt[v] >= n + 1)
					return true;
			}
		}
	}
	return false;
}

int main()
{
	n = in;m = in;
	for(int i = 1;i <= m;++i)
		switch(in){
			case 1:{
				u = in;v = in;w = in;
				add(u,v,-w);
			}break;
			case 2:{
				u = in;v = in;w = in;
				add(v,u,w);
			}break;
			case 3:{
				u = in;v = in;
				add(u,v,0);
				add(v,u,0);
			}break;
		}
	for(int i = 1;i <= n;++i)
		add(n + 1,i,0);
	printf(spfa(n + 1)?"No\n":"Yes\n");
	return 0;
}
