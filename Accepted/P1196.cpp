#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 3e4 + 10;
int t,n,x,y,a[NR],head[NR],len[NR],u,v;
char c;

int find(int x){
	if(a[x] == x)
		return a[x];
	int n = find(a[x]);
	head[x] += head[a[x]];
	return a[x] = n;
}

int main()
{
	t = in;
	for(int i = 1;i < NR;++i){
		a[i] = i;
		len[i] = 1;
	}
	while(t--){
		cin>>c;x = in;y = in;
		u = find(x);v = find(y);
		if(c == 'M'){
			head[u] += len[v];
			a[u] = v;
			len[v] += len[u];
			len[u] = 0;
		}
		if(c == 'C'){
			if(u != v)
				print(-1);
			else
				print(abs(head[x] - head[y]) - 1);
		}
	}
	return 0;
}
