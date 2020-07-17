#include <bits/stdc++.h>
using namespace std;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 2e2 + 10;
const int inf = 0x3fffffff;
int g[NR][NR],n,m,u,v,w,t,k,q,t_[NR];

int main()
{
	n = in;m = in;
	for(int i = 0;i < n;++i){
		for(int j = 0;j < n;++j)
			g[i][j] = inf;
		g[i][i] = 0;
	}
	for(int i = 0;i < n;++i)
		t_[i] = in;
	for(int i = 1;i <= m;++i){
		u = in;v = in;w = in;
		g[u][v] = g[v][u] = min(g[u][v],w);
	}
	q = in;
	for(int w = 1;w <= q;++w){
		u = in;v = in;t = in;
		while(t_[k] <= t and k < n){
			for(int i = 0;i < n;++i)
				for(int j = 0;j < n;++j)
					g[i][j] = min(g[i][j],g[i][k] + g[k][j]);
			++k;
		}
		if(g[u][v] >= inf or t_[u] > t or t_[v] > t)
			print(-1);
		else 
			print(g[u][v]);
	}
	return 0;
}
