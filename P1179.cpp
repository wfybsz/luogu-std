#include <bits/stdc++.h>
using namespace std;

int l,r,cnt;

int T(int x){
	int ret = 0;
	while(x){
		if(x % 10 == 2)
			ret++;
		x /= 10;
	}
	return ret;
}

int main()
{
	cin>>l>>r;
	for(int i = l;i <= r;i++)
		cnt += T(i);
	cout<<cnt;
	return 0;
}
