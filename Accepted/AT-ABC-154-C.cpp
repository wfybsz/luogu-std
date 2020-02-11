#include <bits/stdc++.h>
using namespace std;

int n,tmp;
bool box[1000000],flag;

int main()
{
	cin>>n;
	for(int i = 1;i <= n;++i){
		cin>>tmp;
		if(box[tmp])
			flag = true;
		box[tmp] = true;
	}
	if(flag)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
	return 0;
}
