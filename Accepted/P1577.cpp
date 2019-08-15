#include <bits/stdc++.h>
using namespace std;

const int NR = 1e4;
int n,k,a[NR],l,r = 1e8,m,cnt;
double tmp;

bool check(int x){
	int cnt = 0;
	for(int i = 0;i < n;i++)
		cnt += a[i] / x;
	return cnt >= k;
}

int main()
{
	cin>>n>>k;
	for(int i = 0;i < n;i++){
		cin>>tmp;
		a[i] = tmp * 100;
	}
	while(l <= r){
		m = (l + r) / 2;
		if(!m)
			break;
		if(check(m))
			l = m + 1,cnt = m;
		else
			r = m - 1;
	}
	printf("%.2f",cnt / 100.);
	return 0;
}
