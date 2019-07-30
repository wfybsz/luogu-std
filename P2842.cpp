#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int NR = 1e9 + 7;
ll a,b;

inline ll fp_mod(ll a,ll b,ll mod){
	ll ret = 1;
	a %= mod;
	for(;b;b >>= 1,a *= a,a %= mod)
		if(b & 1)
			ret = ret * a % mod;
	return ret;
}

int main()
{
	cin>>a>>b;
	cout<<fp_mod(a,fp_mod(a,b - 1,NR - 1),NR);
	return 0;
}
