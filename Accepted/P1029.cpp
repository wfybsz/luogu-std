#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int gcd(int a,int b){return b?gcd(b,a % b):a;}

int gbs(int x,int y){
	return (x * y) / gcd(x,y);
}

int main()
{
	int x0,y0,cnt = 0;
	cin>>x0>>y0;
	for(int i = x0;i <= y0;i += x0){
		for(int j = x0;j <= y0;j += x0){
			if(gcd(i,j) == x0 && gbs(i,j) == y0)
				cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
