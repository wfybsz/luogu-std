#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 1e2 + 10;
int n,ans,a[NR],cnt,maxn;
bool flag[NR];

bool dfs(int num,int len_,int last){
	if(num > cnt / ans)
		return true;
	if(len_ == ans)
		return dfs(num + 1,0,1);
	int fail = 0;
	for(int i = last;i <= n;++i){
		if(!flag[i] and a[i] + len_ <= ans and fail != a[i]){
			flag[i] = true;
			if(dfs(num,len_ + a[i],i))
				return true;
			flag[i] = false;
			fail = a[i];
			if(len_ == 0 or len_ + a[i] == ans)
				return false;
		}
	}
	return false;
}

bool cmp(int a,int b){
	return a > b;
}

int main()
{
	while(n = in){
		cnt = maxn = 0;
		for(int i = 1;i <= n;++i){
			a[i] = in;
			cnt += a[i];
			maxn = max(maxn,a[i]);
		}
		sort(a + 1,a + n + 1,cmp);
		for(ans = maxn;ans <= cnt;++ans){
			if(cnt % ans != 0)
				continue;
			memset(flag,0,sizeof(flag));
			if(dfs(1,0,0)){
				print(ans);
				break;
			}
		}
	}
	return 0;
}
