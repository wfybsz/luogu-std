#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 1e4 + 10;
const int MR = 1e5 + 10;
int n,m,u,v,w,size,head[NR],dis[NR],cnt[NR],node[NR];
bool vis[NR];
struct edge{int to,next,w;}e[MR];

bool spfa(int s,int maxn){
	queue<int>q;
	memset(dis,999999,sizeof(dis));
	dis[s] = 0;
	vis[s] = true;
	q.push(s);
	while(!q.empty()){
		u = q.front();
		q.pop();
		vis[u] = false;
		for(int i = head[u];i;i = e[i].next){
			v = e[i].to;
		}
	}
}

int main()
{
	return 0;
}