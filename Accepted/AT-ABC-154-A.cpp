#include <bits/stdc++.h>
using namespace std;

int n,A,B;
string a,b,tmp;

int main()
{
	cin>>a>>b;
	cin>>A>>B;
	cin>>tmp;
	if(tmp == a)
		--A;
	if(tmp == b)
		--B;
	cout<<A<<' '<<B<<endl;
	return 0;
}
