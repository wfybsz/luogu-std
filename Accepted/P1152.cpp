#include <bits/stdc++.h>
using namespace std;

const int NR = 1e3;
int n,a[NR],b[NR];

int main()
{
	cin>>n>>a[0];
	for(int i = 1;i < n;++i){
		cin>>a[i];
		b[i] = abs(a[i] - a[i - 1]);
	}
	sort(b,b + n);
	for(int i = 1;i < n;++i)
		if(b[i] == b[i - 1] + 1)
			continue;
		else{
			cout<<"Not jolly";
			return 0;
		}
	cout<<"Jolly";
	return 0;
}
