#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);}}inline void print(int x,char c = '\n'){io::write(x);putchar(c);}
#define in io::read()

const int NR = 5e3 + 10;
const int MR = 2e5 + 10;
int n,m,fath[NR],ans,cnt;
struct edge{
	int u,v,w;
}a[MR];

int find(int x){while(x != fath[x])x = fath[x] = fath[fath[x]];return x;}

bool cmp(edge a,edge b){return a.w < b.w;}

int main()
{
	n = in;m = in;
	for(int i = 1;i <= n;++i)
		fath[i] = i;
	for(int i = 1;i <= m;++i){
		a[i].u = in;a[i].v = in;a[i].w = in;}
	sort(a + 1,a + m + 1,cmp);
	for(int i = 1;i <= m;++i){
		int u = find(a[i].u),v = find(a[i].v);
		if(u == v)
			continue;
		ans += a[i].w;
		fath[v] = u;
		if(++cnt == n - 1)
			break;
	}
	print(ans);
	return 0;
}
