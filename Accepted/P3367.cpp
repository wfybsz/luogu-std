#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 1e4 + 10;
int n,m,z,x,y,a[NR];

int find(int x){
	if(a[x] == x)
		return x;
	return a[x] = find(a[x]);
}

void merge(int x,int y){
	a[find(x)] = find(y);
}

int main()
{
	n = in;m = in;
	for(int i = 1;i <= n;++i)
		a[i] = i;
	for(int i = 1;i <= m;++i){
		z = in;x = in;y = in;
		switch(z){
			case 1:merge(x,y);break;
			case 2:{
				putchar(find(x) == find(y)?'Y':'N');
				putchar('\n');
			}break;
		}
	}
	return 0;
}
