#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x;

bool check(int x){
	int a = x,b = 0;
	while(a != 0){
		b *= 10;
		b += a % 10;
		a /= 10;
	}
	return b == x;
}

int change(int x){
	while(x % 10 == 0)
		x /= 10;
	return x;
}

int main()
{
	cin>>x;
	cout<<(check(change(x))?"YES":"NO");
	return 0;
}
