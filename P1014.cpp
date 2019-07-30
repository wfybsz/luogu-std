#include<cstdio>
#include<iostream>
#include<cmath>
#define ll long long
using namespace std;

int main()
{
	int n;
	cin>>n;
	int sum = 0,num = 0;
	while(sum < n)
	{
		num++;
		sum += num;
	}
	int x = n + num - sum;
	if(num % 2 == 1)
		printf("%d/%d\n",num + 1 - x,x); 
	else
		printf("%d/%d\n",x,num + 1 - x);
	return 0;
}
