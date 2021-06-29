#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

const int NR = 2e5 +10;
int n,a[NR],sum,maxi,maxn,ansnum,ans[NR];

void spec(){
	int tmpmaxn = 0,tmpmaxi = 0;
	for(int i = 1;i <= n;++i){
		if(i == maxi)
			continue;
		tmpmaxi = tmpmaxn > a[i]?tmpmaxi:i;
		tmpmaxn = a[tmpmaxi];
	}
	if(sum - a[maxi] - a[tmpmaxi] == a[tmpmaxi])
		ans[++ansnum] = a[tmpmaxi];
}

int main()
{
	n = in;
	for(int i = 1;i <= n;++i){
		a[i] = in;
		sum += a[i];
		maxi = maxn > a[i]?maxi:i;
		maxn = a[maxi];
	}
	for(int i = 1;i <= n;++i){
		if(i == maxi){
			spec();
			continue;
		}
		if(sum - a[i] - a[maxi] == a[maxi])
			ans[++ansnum] = i;
	}
	print(ansnum);
	if(ansnum)
		for(int i = 1;i <= ansnum;++i)
			print(ans[i],' ');
	return 0;
}

/*
4
8 3 5 2
*/
