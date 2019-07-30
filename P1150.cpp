#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;

int main()
{
	/*
	freopen("H:\\in.txt","r",stdin);
	freopen("H:\\out.txt","w",stdout);
	*/
	int n,k;
	cin>>n>>k;
	cout<<n + (n - 1) / (k - 1);
	return 0;
}
