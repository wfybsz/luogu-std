#include <bits/stdc++.h>
using namespace std;

int t,m,n;

int f(int m,int n,int min){
	if(n == 1)
		return 1;
	int sum = 0;
	for(int i = min;i <= m / n;++i)
		sum += f(m - i,n - 1,i);
	return sum;
}

int main()
{
	cin>>t;
	while(t--){
		cin>>m>>n;
		cout<<f(m,n,0)<<endl;
	}
	return 0;
}
