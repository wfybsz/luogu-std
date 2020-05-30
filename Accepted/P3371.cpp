#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 1e4 + 10;
const int MR = 5e5 + 10;
int n,m,s,u[MR],v[MR],w[MR],dis[NR];
bool flag = true;

int main()
{
	memset(dis,999999,sizeof(dis));
	n = in;m = in;s = in;
	dis[s] = 0;
	for(int i = 1;i <= m;++i){
		u[i] = in;v[i] = in;w[i] = in;
	}
	while(flag){
		flag = false;
		for(int i = 1;i <= m;++i)
			if(dis[u[i]] + w[i] < dis[v[i]]){
				dis[v[i]] = dis[u[i]] + w[i];
				flag = true;
			}
	}
	for(int i = 1;i <= n;++i)
		print(dis[i] > 1e9?2147483647:dis[i],' ');
	return 0;
}
