#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int gys(int a,int b){
	for(;;){
		if(a > b)
			a -= b;
		if(a < b)
			b -= a;
		if(a == b)
			return a;
	}
}

int gbs(int x,int y){
	return (x * y) / gys(x,y);
}

int main()
{
	int x0,y0,cnt = 0;
	cin>>x0>>y0;
	for(int i = x0;i <= y0;i += x0){
		for(int j = x0;j <= y0;j += x0){
			if(gys(i,j) == x0 && gbs(i,j) == y0)
				cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
