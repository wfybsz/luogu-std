#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 2e4 + 10;
const int MR = 2e5 + 10;
int n,m,head[NR],size,u,v,cnt0,cnt1,cnt;
bool fla;
struct edge{int to,next;}g[MR];
struct node{bool flag,clr;}node[NR];

void add(int u,int v){
	g[++size] = (edge){v,head[u]};
	head[u] = size;
}

bool dfs(int u,bool c){
	if(node[u].flag)
		return node[u].clr == c?true:false;
	node[u].flag = true;
	node[u].clr = c;
	++(c?cnt1:cnt0);
	fla = true;
	for(int i = head[u];i and fla;i = g[i].next)
		fla &= dfs(g[i].to,!c);
	return fla;
}

int main()
{
	n = in;m = in;
	while(m--){
		u = in;v = in;
		add(u,v);
		add(v,u);
	}
	for(int i = 1;i <= n;++i){
		cnt0 = cnt1 = 0;
		if(node[i].flag)
			continue;
		if(!dfs(i,0))
			return printf("Impossible\n") * 0;
		cnt += min(cnt0,cnt1);
	}
	print(cnt);
	return 0;
}
