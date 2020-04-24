#include <bits/stdc++.h>
using namespace std;

int n;

bool prime(int x){
	if(x < 2)
		return false;
	for(int i = 2;i * i <= x;++i)
		if(x % i == 0)
			return false;
	return true;
}

int main()
{
	while(true){
		cin>>n;
		if(!n)
			break;
		for(int i = 1;i <= n;++i)
			if(n % i == 0)
				if(prime(n / i)){
					cout<<n / i<<endl;
					break;
				}
	}
	return 0;
}
