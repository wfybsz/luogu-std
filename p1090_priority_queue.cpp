#include <bits/stdc++.h>
using namespace std;

const int NR = 1e4 + 1e3;
int n,tmp,cnt;
priority_queue<int,vector<int>,greater<int> >a,b;

int main()
{
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>tmp;
		a.push(tmp);
	}
	for(int i = 1;i < n;i++){
		tmp = a.top();
		a.pop();
		tmp += a.top();
		cnt += tmp;
		a.pop();
		a.push(tmp);
	}
	cout<<cnt;
	return 0;
}
