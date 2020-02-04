#include <bits/stdc++.h>
using namespace std;

const int NR = 2e5 + 10;
struct node{
	int u,v;
}t[NR];
int n;

int deep(int x){
	if(!x)
		return 0;
	return max(deep(t[x].u),deep(t[x].v)) + 1;
}

int main()
{
	cin>>n;
	for(int i = 1;i <= n;++i)
		cin>>t[i].u>>t[i].v;
	cout<<deep(1);
	return 0;
}
