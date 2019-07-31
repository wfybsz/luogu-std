#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;

int main()
{
	int x[100],i = 0;
	memset(x,-1,sizeof(x));
	for(i = 0;;i++){
		cin>>x[i];
		if(x[i] == 0)break;
	}
	for(i--;i >= 0;i--)cout<<x[i]<<" ";
	return 0;
}
