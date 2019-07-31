#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;
const int q = 10000;
int main()
{
	int x;
	cin>>x;
	double y = 0;
	if(x <= 150)y = x * 0.4463;
	else{
		if(x <= 400)y = 150 * 0.4463 + (x - 150) * 0.4663;
		else y = 150 * 0.4463 + 250 * 0.4663 + (x - 400) * 0.5663;
	}
	if(y > 10000)cout<<q;
	else printf("%.1f",y);
	return 0;
}
