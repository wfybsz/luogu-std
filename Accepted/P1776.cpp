#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void print(int x,char end = '\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);putchar(end);}}using namespace io;
#define in io::read()

const int NR = 1e5 + 10;
const int MR = 4e4 + 10;
int n,m,v[NR],w[NR],dp[MR];
int tmp,vv,ww,num;

int main()
{
	n = in;m = in;
	for(int i = 1;i <= n;++i){
		vv = in;ww = in;num = in;
		for(int j = 1;j <= num;j *= 2){
			num -= j;
			v[++tmp] = j * vv;
			w[tmp] = j * ww;
		}
		if(num){
			v[++tmp] = vv * num;
			w[tmp] = ww * num;
		}
	}
	for(int i = 1;i <= tmp;++i)
		for(int j = m;j >= w[i];--j)
			dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
	print(dp[m]);
	return 0;
}
