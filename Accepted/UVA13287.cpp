#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,w,a,b,cnt;

int main()
{
	while(cin>>w>>n){
		for(int i = 1;i <= n;++i){
			cin>>a>>b;
			cnt += a * b;
		}
		cout<<cnt / w<<endl;
		cnt = 0;
	}
	return 0;
}
