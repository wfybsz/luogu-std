#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5 + 10;
int q,n,a[NR],b[NR],tmp = 1;
stack<int>s;

int main()
{
	cin>>q;
	while(q--){
		cin>>n;
		tmp = 1;
		for(int i = 1;i <= n;++i)
			cin>>a[i];
		for(int i = 1;i <= n;++i)
			cin>>b[i];
		for(int i = 1;i <= n;++i){
			s.push(a[i]);
			while(s.top() == b[tmp]){
				s.pop();
				++tmp;
				if(s.empty())
					break;
			}
		}
		cout<<(s.empty()?"Yes":"No")<<endl;
		while(not s.empty())
			s.pop();
	}
	return 0;
}
