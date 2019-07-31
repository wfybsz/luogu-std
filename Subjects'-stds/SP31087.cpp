#include <bits/stdc++.h>
using namespace std;

long long a,b;

int main()
{
	cin>>a>>b;
	cout<<(a > b?a * a - b * b:b * b - a * a);
	return 0;
}
