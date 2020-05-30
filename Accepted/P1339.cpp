#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int u=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){u=(u<<1)+(u<<3)+(c^48);c=getchar();}if(flag)return u;return ~(u-1);}inline void write(int u,char end='\n'){int s[20];register int top=0;if(u<0){putchar('-');u=~(u-1);}while(u){s[++top]=u%10;u/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 2510;
const int MR = 6210 * 2;
int n,m,s,t,size,head[NR],u,v,w,dis[NR];
struct edge{
	int to,next,w;
}g[MR];
queue<int>q;
bool flag[NR];

void add(int u,int v,int w){
	g[++size] = (edge){v,head[u],w};
	head[u] = size;
}

void spfa(int s){
	memset(dis,999999,sizeof(dis));
	dis[s] = 0;
	q.push(s);
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
			q.push(v);
			flag[v] = true;
		}
	}
}

int main()
{
	n = in;m = in;s = in;t = in;
	for(int i = 1;i <= m;++i){
		u = in;v = in;w = in;
		add(u,v,w);
		add(v,u,w);
	}
	spfa(s);
	print(dis[t]);
	return 0;
}
