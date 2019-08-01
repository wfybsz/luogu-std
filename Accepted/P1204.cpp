#include <bits/stdc++.h>
using namespace std;

const int NR = 1e6;
int n,a[NR],x,y,
	l = 2147483647,r = -2147483648,max_true,max_false,
	cnt_true,cnt_false;

int main()
{
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>x>>y;
		l = min(x,l);
		r = max(y,r);
		a[x]++;;
		a[y]--;
	}
	for(int i = 1;i < NR;i++)
		a[i] += a[i - 1];
	for(int i = l;i <= r;i++){
		if(a[i]){
			cnt_true++;
			max_false = max(cnt_false,max_false);
			cnt_false = 0;
		}
		else{
			cnt_false++;
			max_true = max(cnt_true,max_true);
			cnt_true = 0;
		}
	}
	cout<<max_true<<' '<<max_false;
	return 0;
}
