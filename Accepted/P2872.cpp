#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 2e6 + 10;
int n,m,u,v,w,size,fa[NR],cnt;
double ans;
struct nod{int x,y;}node[NR];
struct edge{int u,v;double w;}g[NR];

bool cmp(edge a,edge b){
	return a.w < b.w;
}

void add(int u,int v,double w){
	g[++size] = (edge){u,v,w};
}

int find(int x){
	if(fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

double dis(int i,int j){
	return sqrt(1. * (node[i].x - node[j].x) * (node[i].x - node[j].x) + 1. * (node[i].y - node[j].y) * (node[i].y - node[j].y));
}

int main()
{
	n = in;m = in;
	for(int i = 1;i <= n;++i)
		fa[i] = i;
	for(int i = 1;i <= n;++i){
		node[i].x = in;node[i].y = in;
	}
	for(int i = 1;i <= n;++i)
		for(int j = i + 1;j <= n;++j)
			add(i,j,dis(i,j));
	for(int i = 1;i <= m;++i){
		u = in;v = in;
		add(u,v,0.);
	}
	sort(g + 1,g + size + 1,cmp);
	for(int i = 1;i <= size;++i){
		u = find(g[i].u),v = find(g[i].v);
		if(u != v){
			ans += g[i].w;
			fa[v] = u;
			if(++cnt == n - 1)
				break;
		}
	}
	printf("%.2f\n",ans);
	return 0;
}
