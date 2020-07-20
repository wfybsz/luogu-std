#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 1e6 + 10;
int s,p,size,fa[NR],cnt;
double ans;
struct nod{int x,y;}node[NR];
struct edge{int u,v;double w;}g[NR];

bool cmp(edge a,edge b){
	return a.w < b.w;
}

int find(int x){
	if(fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

void merge(int a,int b){
	fa[find(a)] = find(b);
}

double dis(int i,int j){
	return sqrt(1. * (node[i].x - node[j].x) * (node[i].x - node[j].x) + 1. * (node[i].y - node[j].y) * (node[i].y - node[j].y));
}

int main()
{
	s = in;p = in;
	for(int i = 1;i <= p;++i)
		fa[i] = i;
	for(int i = 1;i <= p;++i){
		node[i].x = in;node[i].y = in;
	}
	for(int i = 1;i <= p;++i){
		for(int j = 1;j < i;++j)
			g[++size] = (edge){i,j,dis(i,j)};
	}
	sort(g + 1,g + size + 1,cmp);
	for(int i = 1;i <= size;++i)
		if(find(g[i].u) != find(g[i].v)){
			merge(g[i].u,g[i].v),ans = g[i].w,++cnt;
			if(cnt >= p - s){
				printf("%.2f",ans);
				return 0;
			}
		}
	return 0;
}
