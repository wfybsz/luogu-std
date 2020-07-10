#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 1e4 + 10;
const int MR = 5e5 + 10;
int n,m,s,size,head[NR],dis[NR],u,v,w;
bool flag[NR];
struct edge{
	int to,next,w;
}g[MR];

void add(int u,int v,int w){
	g[++size] = (edge){v,head[u],w};
	head[u] = size;
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

int main()
{
	n = in;m = in;s = in;
	for(int i = 1;i <= m;++i){
		u = in;v = in;w = in;
		add(u,v,w);
	}
	spfa(s);
	for(int i = 1;i <= n;++i)
		if(dis[i] > 1e9)
			print(2147483647,' ');
		else
			print(dis[i],' ');
	return 0;
}
