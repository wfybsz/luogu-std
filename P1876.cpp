#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
double tmp;

int main()
{
	cin>>n;
	tmp = sqrt(n);
	for(ll i = 1;i <= tmp;i++)
		cout<<1ll * i * i<<' ';
	return 0;
}
