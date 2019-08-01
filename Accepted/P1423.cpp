#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;

int main()
{
	long double x = 2,y;
	int cnt = 0;
	cin>>y;
	for(;y > 0;cnt++){
		y -= x;
		x *= 0.98;
	}
	cout<<cnt;
	return 0;
}
