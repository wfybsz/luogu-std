#include <bits/stdc++.h>
using namespace std;

const int NR = 1e6 + 10;
const int MR = 86400;
int n,t,m,x,flag[NR],cnt;
struct node{
	int nat,t;
}tmp;
queue<node>a;

int main()
{
	cin>>n;
	for(int i = 1;i <= n;++i){
		cin>>t>>m;
		while(not a.empty()){
			tmp = a.front();
			if(tmp.t + MR <= t){
				a.pop();
				--flag[tmp.nat];
				if(not flag[tmp.nat])
					--cnt;
				continue;
			}
			break;
		}
		for(int j = 1;j <= m;++j){
			cin>>x;
			tmp.nat = x;
			tmp.t = t;
			a.push(tmp);
			++flag[x];
			if(flag[x] == 1)
				++cnt;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
