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
	int x[n];
	int i = 0,j = 0,cnt = 0;
	for(i = 0;i < n;i++)cin>>x[i];
	for(i = 0;i < n;i++){
		for(j = i;j >= 0;j--)if(x[j] < x[i])cnt++;
		cout<<cnt<<" ";
		cnt = 0;
	}
	return 0;
}
