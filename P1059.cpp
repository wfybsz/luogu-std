#include<cstdio>
#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
bool b[1000];
int main()
{
	/*
	freopen("C:\\c\\in.txt","r",stdin);
	freopen("C:\\c\\out.txt","w",stdout);
	*/
	int i;
	int n;
	cin>>n;
	int y,m = 0;
	for(i = 0;i <= n - 1;i++){
		cin>>y;
		b[y] = true;
	}
	for(i = 0;i <= 999;i++)
		if(b[i])m++;
	cout<<m<<endl;
	for(i = 0;i <= 999;i++){
		if(b[i])cout<<i<<" ";
	}
	return 0;
}
