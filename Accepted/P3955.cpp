#include <bits/stdc++.h>
using namespace std;

const int NR = 1e3;
int n,q,a[NR],tmp;

bool in(int x,int y){
	while(y and x){
		if(x % 10 != y % 10)
			return false;
		x /= 10;
		y /= 10;
		if(y && not x)
			return false;
	}
	return true;
}

int main()
{
	cin>>n>>q;
	for(int i = 0;i < n;++i)
		cin>>a[i];
	sort(a,a + n);
	qwq:
	while(q--){
		scanf("%*d");
		cin>>tmp;
		for(int i = 0;i < n;++i){
			if(in(a[i],tmp)){
				cout<<a[i]<<endl;
				goto qwq;
			}
		}
		cout<<-1<<endl;
	}
	return 0;
}

