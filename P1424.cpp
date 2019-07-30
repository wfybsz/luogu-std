#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;

int main()
{
	ll x,n,cnt = 0;
	cin>>x>>n;
	int zh = x;
	for(int i = 1;i <= n;i++,zh++){
		if(zh < 6)cnt += 250;
		if(zh == 7)zh = 0;
	}
	cout<<cnt;
	return 0;
}
