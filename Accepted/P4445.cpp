#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int NR = 1e5;
ll n,tmp,last,cnt;

int main()
{
	cin>>n;
	n--;
	cin>>tmp;
	while(n--){
		last = tmp;
		cin>>tmp;
		cnt += max(last,tmp);
	}
	cout<<cnt;
	return 0;
}
