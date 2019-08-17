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

int main()
{
	cin>>n;
	for(int i = 2;i <= n - 4;i++)
		for(int j = 2;j <= n - i - 2;j++)
			if(prime(i) && prime(j) && prime(n - i - j)){
				cout<<i<<' '<<j<<' '<<n - i - j;
				return 0;
			}
	return 0;
}
