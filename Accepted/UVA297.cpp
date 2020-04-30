#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace io{inline int read(){register int x=0,flag=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')flag=0;c=getchar();}while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}if(flag)return x;return ~(x-1);}inline void write(int x,char end='\n'){int s[20];register int top=0;if(x<0){putchar('-');x=~(x-1);}while(x){s[++top]=x%10;x/=10;}if(!top)s[++top]=0;while(top)putchar(s[top--]^48);if(end!=0)putchar(end);}}
#define in io::read()
#define print io::write
#define ri register int

int n;
struct node{
	char c;
	node *sp[4];
	node(){c = 0;sp[0] = sp[1] = sp[2] = sp[3] = NULL;}
}*root,*root_;

void dfs(node*&p){
	p = new node;
	while(!(p->c == 'f' or p->c == 'e' or p->c == 'p'))
		p->c = getchar();
	switch(p->c){
		case 'f':return;break;
		case 'e':return;break;
		case 'p':{
			for(ri i = 0;i < 4;++i)
				dfs(p->sp[i]);
			break;
		}
	}
}

void merge(node *&p,node *p_){
	if(p_ == NULL)
		return;
	if(p->c == 'f' or p_->c == 'f'){
		p->c = 'f';
		return;
	}
	if(p->c == 'e'){
		p = p_;
		return;
	}
	for(ri i = 0;i < 4;++i)
		merge(p->sp[i],p_->sp[i]);
}

int count(node *p,int edge){
	if(p->c == 'f'){
		return edge * edge;
	}
	if(p->c == 'e')
		return 0;
	ri tot = 0;
	for(ri i = 0;i < 4;++i)
		tot += count(p->sp[i],edge / 2);
	return tot;
}

int main()
{
	n = in;
	while(n--){
		dfs(root);
		dfs(root_);
		merge(root,root_);
		printf("There are %d black pixels.\n",count(root,32));
		root = root_ = NULL;
	}
	return 0;
}
