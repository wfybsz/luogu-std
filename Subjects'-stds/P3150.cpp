#include <bits/stdc++.h>
using namespace std;

int n,a;

int main()
{
	cin>>n;
	while(n--){
		cin>>a;
		if(a % 2)
			cout<<"zs wins"<<endl;
		else
			cout<<"pb wins"<<endl;
	}
	return 0;
}
