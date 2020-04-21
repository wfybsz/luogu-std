#include <bits/stdc++.h>
using namespace std;

long long n;

bool Do(long long x){
	if(x == 1)
		return true;
	if(x % 2 == 0)
		return Do(x / 2);
	return false;
}

int main()
{
	cin>>n;
	cout<<(Do(n)?"TAK":"NIE")<<endl;
	return 0;
}
