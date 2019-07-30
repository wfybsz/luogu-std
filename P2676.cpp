#include <bits/stdc++.h>
using namespace std;

int n,h[20001],s,b,cnt,ans;

bool cmp(int a,int b){
	return a > b;
}

int main()
{
	cin>>n>>b;
	for(int i = 0;i < n;i++){
		cin>>h[i];
		s += h[i];
	}
	sort(h,h + n,cmp);
	for(;cnt < b;ans++)
		cnt += h[ans];
	cout<<ans;
	return 0;
}
