#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 1e4 + 10;
const int MR = 5e4 + 10;
int n,m,u,v,w,w_,size,size_,size__,head[3][NR],dis[3][NR];
bool vis[NR];
struct edge{int to,next,w;}g[3][MR];

void add(int &size,int head[],edge g[],int u,int v,int w){
	g[++size] = (edge){v,head[u],w};
	head[u] = size;
}

void spfa(int s,edge g[],int head[],int id){
	queue<int>q;
	memset(dis[id],999999,sizeof(dis[id]));
	memset(vis,false,sizeof(vis));
	q.push(s);
	dis[id][s] = 0;
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
	n = in;m = in;
	for(int i = 1;i <= m;++i){
		u = in;v = in;w = in;w_ = in;
		add(size,head[0],g[0],v,u,w);
		add(size_,head[1],g[1],v,u,w_);
	}
	spfa(n,g[0],head[0],0);
	spfa(n,g[1],head[1],1);
	for(int i = 1;i <= m;++i){
		int cnt = 0,x = i,y = g[0][i].to;
		cnt += dis[0][y] != dis[0][x] + g[0][x].w;
		cnt += dis[1][y] != dis[1][x] + g[1][x].w;
		add(size__,head[2],g[2],y,x,cnt);
	}
	spfa(1,g[2],head[2],2);
	print(dis[2][n]);
	return 0;
}
