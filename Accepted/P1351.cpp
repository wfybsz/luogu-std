#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write
#define mod % 10007

const int NR = 2e5 + 10;
int n,u,v,size,head[NR * 2],node[NR],maxn;
ll cnt;
struct edge{int to,next,d;}g[NR * 2];

void add(int u,int v){
	g[++size] = (edge){v,head[u]};
	++g[size].d;
	head[u] = size;
}

int main()
{
	n = in;
	for(int i = 1;i < n;++i){
		u = in;v = in;
		add(u,v);
		add(v,u);
	}
	for(int i = 1;i <= n;++i)
		node[i] = in;
	for(int i = 1;i <= n;++i)
		for(int j = head[i];j;j = g[j].next)
			for(int k = head[i];k;k = g[k].next){
				u = g[j].to,v = g[k].to;
				if(u == v)
					continue;
				maxn = max(maxn,node[u] * node[v]);
				cnt += node[u] * node[v];
			}
	print(maxn,' ');
	print(cnt % 10007);
	return 0;
}
