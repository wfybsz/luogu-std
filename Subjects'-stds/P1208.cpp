#include <bits/stdc++.h>
using namespace std;

const int NR = 5e3;
int n,m,cnt;
struct node{
	int a,p;
}a[NR + 5];

int cmp(node x,node y){
	return x.p < y.p;
}

int main()
{
	cin>>n>>m;
	for(int i = 1;i <= m;i++)
		cin>>a[i].p>>a[i].a;
	sort(a + 1,a + m + 1,cmp);
	for(int i = 1;i <= m;i++)
		if(n > 0){
			if(n > a[i].a){
				n -= a[i].a;
				cnt += a[i].p * a[i].a;
			}else
				if(n <= a[i].a){
					cnt += a[i].p * n;
					n -= a[i].a;
				}
		}
	cout<<cnt;
	return 0;
}
