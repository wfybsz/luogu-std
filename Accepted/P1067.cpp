#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// *INDENT-OFF*
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write
// *INDENT-ON*
#define abs(x) (x>0?x:-x)

const int NR = 1e2 + 10;
int n, a[NR];

int main() {
	n = in;
	for ( int i = 0; i <= n; ++i )
		a[i] = in;
	if ( a[0] == -1 )
		printf( "-x^%d", n );
	else
		if ( a[0] == 1 )
			printf( "x^%d", n );
		else
			if ( a[0] != 0 )
				printf( "%dx^%d", a[0], n );
	for ( int i = 1; i < n; ++i ) {
		if ( a[i] == 0 )
			continue;
		if ( a[i] < 0 )
			putchar( '-' );
		else
			putchar( '+' );
		a[i] = abs( a[i] );
		if ( a[i] == 1 )
			printf( "x^%d", n - i );
		else
			printf( "%dx^%d", a[i], n - i );
	}
	return 0;
}
