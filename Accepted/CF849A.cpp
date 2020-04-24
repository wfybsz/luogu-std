#include <bits/stdc++.h>
using namespace std;

const int NR = 110;
int n,a[NR];

int main()
{
	cin>>n;
	if(n % 2 == 0){
		cout<<"No";
		return 0;
	}
	for(int i = 1;i <= n;++i)
		cin>>a[i];
	if(a[1] % 2 == 0 or a[n] % 2 == 0){
		cout<<"No";
		return 0;
	}
	cout<<"Yes";
	return 0;
}
