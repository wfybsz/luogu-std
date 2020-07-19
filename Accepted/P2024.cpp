#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 1e5 + 10;
int n,m,t,x,y,cnt,a[3 * NR];

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
	for(int i = 1;i <= 3 * n;++i)
		a[i] = i;
	while(m--){
		t = in;x = in;y = in;
		if(x > n or y > n){
			++cnt;
			continue;
		}
		if(t == 1)
			if(find(x + n) == find(y) or find(y + n) == find(x))
				++cnt;
			else{
				merge(x,y);
				merge(x + n,y + n);
				merge(x + 2 * n,y + 2 * n);
			}
		else
			if(find(x) == find(y) or find(x) == find(y + n))
				++cnt;
			else{
				merge(x,y + 2 * n);
				merge(x + n,y);
				merge(x + 2 * n,y + n);
			}
	}
	print(cnt);
	return 0;
}
