#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 1e4 + 10;
const int MR = 4e4 + 10;
int n,m,s,t,u,v,w,size,head[NR],l,r,ans;
bool flag[NR];
struct edge{int to,next,w;}g[MR];

void add(int u,int v,int w){
	g[++size] = (edge){v,head[u],w};
	head[u] = size;
}

void dfs(int x,int lim){
	flag[x] = true;
	for(int i = head[x];i;i = g[i].next){
		if(g[i].w > lim or flag[g[i].to])
			continue;
		dfs(g[i].to,lim);
	}
}

bool check(int x){
	memset(flag,0,sizeof(flag));
	dfs(s,x);
	return flag[t];
}

int main()
{
	n = in;m = in;s = in;t = in;
	for(int i = 1;i <= m;++i){
		u = in;v = in;w = in;
		add(u,v,w);
		add(v,u,w);
	}
	int l = 1,r = NR;
	while(l <= r){
		int m = (l + r) / 2;
		if(check(m)){
			r = m - 1;
			ans = m;
		}else
			l = m + 1;
	}
	print(ans);
	return 0;
}
