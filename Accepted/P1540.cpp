#include <bits/stdc++.h>
using namespace std;

int m,n,tmp,cnt,ans;
bool flag[10000];
queue<int>a;

int main()
{
	cin>>m>>n;
	for(int i = 1;i <= n;++i){
		cin>>tmp;
		if(flag[tmp])
			continue;
		flag[tmp] = true;
		++cnt;
		if(a.size() >= m){
			flag[a.front()] = false;
			a.pop();
		}
		a.push(tmp);
	}
	cout<<cnt;
	return 0;
}
