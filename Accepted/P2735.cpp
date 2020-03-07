#include <bits/stdc++.h>
using namespace std;

int n,m,p;

int gcd(int a,int b){
	return b?gcd(b,a % b):a;
}

int main()
{
	cin>>n>>m>>p;
	cout<<(p * m / 2) - (gcd(n,m) + gcd(abs(p - n),m) + p) / 2 + 1;
	return 0;
}
