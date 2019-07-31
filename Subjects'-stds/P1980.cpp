#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;

int main()
{
	int n,x;
	cin>>n>>x;
	int cnt = 0,y;
	for(int i = 1;i <= n;i++){
		y = i;
		for(;y > 0;){
			if(y % 10 == x)cnt++;
			y /= 10;
		}
	}
	cout<<cnt;
	return 0;
}
