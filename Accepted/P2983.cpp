#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int NR = 1e5 + 10;
ll n,b,cnt,tmp;
struct node{
	ll c,p;
}a[NR];

bool cmp(node x,node y){
	if(x.c != y.c)
		return x.c < y.c;
	else
		return x.p > y.p;
}

int main(){
	cin>>n>>b;
	for(int i = 1;i <= n;++i)
		cin>>a[i].c>>a[i].p;
	sort(a + 1,a + n + 1,cmp);
	for(int i = 1;i <= n;++i)
		if(a[i].c <= b){
			tmp = min(b / a[i].c,a[i].p);
			b -= tmp * a[i].c;
			cnt += tmp;
		}
	cout<<cnt;
	return 0;
}
