#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 2e5 + 10;
int n,head[NR],size,minn = 2147483647;
struct node{int anc,dis;}a[NR];

int fath(int x){
	if(a[x].anc != x){
		int father = a[x].anc;
		a[x].anc = fath(a[x].anc);
		a[x].dis += a[father].dis;
	}
	return a[x].anc;
}

void add(int u,int v){
	int U = fath(u),V = fath(v);
	if(U != V){
		a[U].anc = V;
		a[u].dis = a[v].dis + 1;
	}else
		minn = min(minn,a[u].dis + a[v].dis + 1);
}

int main()
{
	n = in;
	for(int i = 1;i <= n;++i)
		a[i].anc = i;
	for(int i = 1;i <= n;++i)
		add(i,in);
	print(minn);
	return 0;
}
