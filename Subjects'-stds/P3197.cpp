#include <iostream>
#define ll long long
#define mod % NR
using namespace std;

const int NR = 1e5 + 3;
ll m,n;

ll fp(ll a,ll b){
	if(!b)
		return 1;
	ll p = fp(a,b / 2) mod;
	if((b % 2))
		return (((p * p) mod) * a) mod;
	else
		return (p * p) mod;
}

int main()
{
	cin>>m>>n;
	cout<<(fp(m,n) - ((m * fp(m - 1,n - 1)) mod) + NR) mod;
	return 0;
}
