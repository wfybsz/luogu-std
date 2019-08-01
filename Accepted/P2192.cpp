#include <bits/stdc++.h>
using namespace std;

const int NR = 1e3;
int n,a[NR],cnt5,cnt0;
bool flag;

int main()
{
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>a[i];
		if(a[i] == 0)
			cnt0++;
		else
			cnt5++;
	}
	if(!cnt0){
		cout<<-1;
		return 0;
	}
	if(cnt5 / 9 == 0){
		cout<<0;
		return 0;
	}
	for(int i = 0;i < cnt5 / 9;i++)
		cout<<"555555555";
	for(int i = 0;i < cnt0;i++)
		cout<<'0';
	return 0;
}
