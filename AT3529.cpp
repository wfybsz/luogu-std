#include <bits/stdc++.h>
using namespace std;

int n,cnt,tmp1,tmp2;

int main()
{
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>tmp1>>tmp2;
		cnt += abs(tmp1 - tmp2) + 1;
	}
	cout<<cnt;
	return 0;
}
