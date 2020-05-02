#include <bits/stdc++.h>
using namespace std;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

int p[10] = {0},n;
bool vis[10] = {0};

void dfs(int x){
	if(x == n + 1){
		for(int i = 1;i <= n;i++)
			print(p[i],' ');
		putchar('\n');
		return;
	}
	for(int i = 1;i <= n;i++){
		if(vis[i] == false){
			p[x] = i;
			vis[i] = true;
			dfs(x + 1);
			vis[i] = false;
		}
	}
}

int main()
{
	while(cin>>n)
		dfs(1);
	return 0;
}
