#include <bits/stdc++.h>
using namespace std;

const int NR = 2500 + 10;
int n,m,a,tmp,f[NR];

int main()
{
	cin>>n>>m;
	for(int i = 1;i <= n;++i)
		f[i] = 2147483647;
	a = m;
	for(int i = 1;i <= n;i++){
		cin>>tmp;
		a += tmp;
		for(int j = i;j <= n;j++)
			f[j] = min(f[j],f[j - i] + a + m);
	}
	cout<<f[n] - m;
	return 0;
}
