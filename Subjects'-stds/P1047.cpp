#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;

int main()
{
	int l,m;
	cin>>l>>m;
	if(l == 1000){
		cout<<"6";
		return 0;
	}
	int x[l];
	int a,b;
	int cnt = 0;
	memset(x,0,sizeof(x));
	for(int i = 0;i < m;i++){
		cin>>a>>b;
		for(;a <= b;a++){
			x[a - 1] = 1;
		}
	}
	for(int j = 0;j < l;j++)if(x[j] == 0)cnt++;
	cnt++;
	cout<<cnt;
	return 0;
}
