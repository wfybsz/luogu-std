#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 1e2 + 10;
const int MR = 1e4 + 10;
int n,m,a[MR],dis[NR][NR];
ll cnt;

void flo(){
	for(int k = 1;k <= n;++k)
		for(int i = 1;i <= n;++i)
			for(int j = 1;j <= n;++j)
				dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
}

int main()
{
	n = in;m = in;
	for(int i = 1;i <= m;++i)
		a[i] = in;
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= n;++j)
			dis[i][j] = in;
	flo();
	for(int i = 2;i <= m;++i)
		cnt += dis[a[i - 1]][a[i]];
	cout<<cnt<<endl;
	return 0;
}
