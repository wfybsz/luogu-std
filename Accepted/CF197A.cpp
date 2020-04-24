#include <bits/stdc++.h>
using namespace std;

int a,b,r;

int main()
{
	cin>>a>>b>>r;
	if(r * 2 <= a and r * 2 <= b)
		cout<<"First";
	else
		cout<<"Second";
	return 0;
}
