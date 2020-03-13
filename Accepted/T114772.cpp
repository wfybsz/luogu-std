#include <bits/stdc++.h>
using namespace std;
#define max(a,b) (a>b?a:b)

const int NR = 2e3 + 100;
int n,tmp[NR];
char c;

struct ii{
	int a[NR],len;
	ii(){
		len = 0;
	}
}num[NR];

void Plus(ii& a,ii& b){
	int l = max(a.len,b.len);
	a.len = max(a.len,b.len);
	b.len = max(a.len,b.len);
	for(int i = 1;i <= l;++i){
		a.a[i] += b.a[i];
		if(a.a[i] < 7)
			continue;
		else if(7 <= a.a[i] and a.a[i] <= 13)
			++a.a[i + 1];
		else
			a.a[i + 1] += 2;
		a.a[i] %= 10;
	}
	while(a.a[a.len + 1] != 0)
		++a.len;
}

int main()
{
	cin>>n;
	getchar();
	for(int i = 1;i <= n;++i){
		cin>>tmp[i];
		while(tmp[i]){
			num[i].a[++num[i].len] = tmp[i] % 10;
			tmp[i] /= 10;
		}
	}
	ii ans = num[1];
	for(int i = 2;i <= n;++i)
		Plus(ans,num[i]);
	for(int i = ans.len;i >= 1;--i)
		putchar(ans.a[i] + '0');
	return 0;
}
