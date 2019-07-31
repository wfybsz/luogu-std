#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;

int main()
{
	int n;
	cin>>n;
	int shu[3],cost[3];
	int i = 0;
	for(i = 0;i <= 2;i++){
		cin>>shu[i];
		cin>>cost[i];
	}
	int min_cost = 2147483647;
	for(i = 0;i <= 2;i++){
		if(min_cost > ((n / shu[i]) + 1) * cost[i])
			if(n % shu[i] == 0)
				min_cost = n / shu[i] * cost[i];
			else
				min_cost = ((n / shu[i]) + 1) * cost[i];
	}
	cout<<min_cost;
	return 0;
}
