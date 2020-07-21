#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 5e3 + 10;
int n;
double dis[NR],ans;
bool vis[NR];
struct nod{int x,y;}node[NR];

double dist(int i,int j){
	return sqrt(1. * (node[i].x - node[j].x) * (node[i].x - node[j].x) + 1. * (node[i].y - node[j].y) * (node[i].y - node[j].y));
}

void prim(int s){
	memset(dis,999999,sizeof(dis));
	dis[s] = 0;
	for(int i = 1;i < n;++i){
		
	}
}

int main()
{
	n = in;
	for(int i = 1;i <= n;++i){
		node[i].x = in;node[i].y = in;
	}
	return 0;
}
