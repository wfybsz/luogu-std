#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;

int main()
{
	ll i = 0;
	ll x,y;
	cin>>x;
	if(x < 0){
		cout<<"-";
		x = 0 - x;
	}
	for(;x % 10 == 0;){
		x /= 10;
	}
	y = x;
	ll cnt = 0;
	for(;y > 0;){
		y /= 10;
		cnt++;
	}
	for(i = 1;i <= cnt;i++){
		cout<<x % 10;
		x /= 10;
	}
	return 0;
}
