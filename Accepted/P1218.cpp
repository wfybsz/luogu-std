#include <bits/stdc++.h>
using namespace std;

int n;

bool prime(int x){
	if(x < 2)
		return false;
	for(int i = 2;i * i <= x;i++)
		if(!(x % i))
			return false;
	return true;
}

bool super(int x){
	if(x < 10)
		return prime(x);
	if(prime(x))
		return super(x / 10);
	else
		return false;
}

int main()
{
	for(int i = 0;i < 100000000;++i)
		if(super(i))
			cout<<i<<',';
	return 0;
}
