#include <bits/stdc++.h>
using namespace std;

int n,tmp,minn = 2147483647;

int main()
{
	cin>>n;
	for(int i = 1;i <= n;++i){
		cin>>tmp;
		minn = min(minn,tmp);
	}
	cout<<minn;
	return 0;
}
