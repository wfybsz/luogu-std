#include <bits/stdc++.h>
using namespace std;

int n,maxn = -2147483648,minn = 2147483647,tmp;

int main()
{
	cin>>n;
	while(n--){
		cin>>tmp;
		maxn = max(maxn,tmp);
		minn = min(minn,tmp);
	}
	cout<<maxn - minn;
	return 0;
}
