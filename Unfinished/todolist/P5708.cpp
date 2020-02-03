#include <bits/stdc++.h>
using namespace std;

int a,b,c;
double p;

int main()
{
	cin>>a>>b>>c;
	p = (a + b + c) / 2.;
	printf("%.1f",sqrt(p * (p - a) * (p - b) * (p - c)));
	return 0;
}
