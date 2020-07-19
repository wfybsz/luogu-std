#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 1e3 + 10;
const int MR = 1e5 + 10;
int n,m,a[NR];
struct data{
	int t,u,v;
}b[MR];

bool cmp(data a,data b){
	return a.t < b.t;
}

int find(int x){
	if(a[x] == x)
		return x;
	return a[x] = find(a[x]);
}

void merge(int x,int y){
	if(find(x) != find(y))
		n--;
	a[find(x)] = find(y);
}

int main()
{
	n = in;m = in;
	if(n == 1){
		print(0);
		return 0;
	}
	for(int i = 1;i <= m;++i)
		a[i] = i;
	for(int i = 1;i <= m;++i){
		b[i].u = in;b[i].v = in;b[i].t = in;
	}
	sort(b + 1,b + m + 1,cmp);
	for(int i = 1;i <= m;++i){
		merge(b[i].u,b[i].v);
		if(n == 1){
			print(b[i].t);
			return 0;
		}
	}
	print(-1);
	return 0;
}
