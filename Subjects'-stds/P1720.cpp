#include <bits/stdc++.h>
using namespace std;

int n;

double inv(double x,int y){
	double ret = 1;
	for(int i = 0;i < y;i++)
		ret *= x;
	return ret;
}

double F(int n){
	return (inv((1 + sqrt(5)) / 2,n) - inv((1 - sqrt(5)) / 2,n)) / sqrt(5);
}

int main()
{
	cin>>n;
	printf("%.2f",F(n));
	return 0;
}
