#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// *INDENT-OFF*
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write
// *INDENT-ON*

const int NR = 60;
int n, k, a[NR], cnt, ans = 1;

int main() {
	n = in;
	k = in;
	for ( int i = 1; i <= n; ++i )
		a[i] = in;
	sort( a + 1, a + n + 1 );
	for ( int i = n; i >= 1; --i, ++ans ) {
		cnt += a[i];
		if ( cnt >= k )
			break;
	}
	if ( cnt < k )
		print( -1 );
	else
		print( ans );
	return 0;
}
