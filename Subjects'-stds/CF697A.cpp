#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;

ll t,s,x;

bool will_bark(){
	return (!((x - t) % s) || !((x - t - 1) % s)) && x != t + 1;
}

int main()
{
	cin>>t>>s>>x;
	if(x < t){
		cout<<"NO";
		return 0;
	}
	if(will_bark())
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}
