#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int NR = 1e5 + 10;
int n,q,tmp,I,J,K;
struct node{
	vector<int>b,t;
	int cnt = 0;
}a[NR];

int main()
{
	cin>>n>>q;
	while(q--){
		cin>>tmp>>I>>J;
		if(tmp == 1){
			cin>>K;
			++a[I].cnt;
			a[I].b.push_back(J);
			a[I].t.push_back(K);
		}else{
			for(int i = a[I].cnt - 1;i >= 0;--i)
				if(a[I].b[i] == J){
					cout<<a[I].t[i]<<endl;
					break;
				}
		}
	}
	return 0;
}
