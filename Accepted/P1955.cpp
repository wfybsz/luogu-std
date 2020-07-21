#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 2e6 + 10;
const int bigprime = 1000007;
int t,n,a,b,c,fa[2 * NR],size,rec[NR][2];
bool flag;

int find(int x){
	if(fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

void merge(int a,int b){
	fa[find(a)] = find(b);
}

void init(){
	flag = true;
	size = 0;
	memset(rec,0,sizeof(rec));
}

int main()
{
	t = in;
	while(t--){
		init();
		n = in;
		for(int i = 1;i <= n;++i)
			fa[i] = i;
		for(int i = 1;i <= n;++i){
			a = in;b = in;c = in;
			a %= bigprime;b %= bigprime;
			if(c)
				merge(a,b);
			else{
				rec[++size][0] = a;
				rec[size][1] = b;
			}
		}
		for(int i = 1;i <= size;++i)
			if(find(rec[i][0]) == find(rec[i][1])){
				flag = false;
				break;
			}
		printf(flag?"YES\n":"NO\n");
	}
	return 0;
}
