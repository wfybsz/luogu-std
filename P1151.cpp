#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;

int main()
{
	bool flag = true;
	int x = 10000,y;
	cin>>y;
	for(;x <= 30000;x++)
	{
		int a,b,c;
		a = x / 100;
		b = (x - 10000 * (x / 10000)) / 10;
		c = x - 1000 * (x / 1000);
		if(a % y == 0 && b % y == 0 && c % y == 0)
		{
			cout<<x<<endl;
			flag = false;
		}
	}
	if(flag)
		printf("No");
	return 0;
} 
