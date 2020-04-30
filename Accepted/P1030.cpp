#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write

void dfs(string inOrd,string postOrd){
	if(inOrd.size() <= 0)
		return;
	char root = postOrd[postOrd.size() - 1];
	putchar(root);
	int pos = inOrd.find(root);
	dfs(inOrd.substr(0,pos),postOrd.substr(0,pos));
	dfs(inOrd.substr(pos + 1),postOrd.substr(pos,inOrd.size() - pos - 1));
}

int main(){
	string inOrder,postOrder;
	cin>>inOrder;
	cin>>postOrder;
	dfs(inOrder,postOrder);
	putchar('\n');
	return 0;
}
