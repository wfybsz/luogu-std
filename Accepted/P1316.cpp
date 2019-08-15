#include<bits/stdc++.h>
using namespace std;

const int NR = 1e5 + 10;
int n,m;
int a[NR];

bool check(int x){
	int num = 1,pos = a[1];
	for(int i = 2;i <= n;i++)
		if(a[i] - pos >= x){
			num++;
			pos = a[i];
		}
	return num >= m;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++)
		scanf("%d",a + i);
	sort(a + 1,a + 1 + n);
	int l = 1,r = a[n] - a[1],cnt = 0;
	while(l <= r){
		int m = (l + r) / 2;
		if(check(m))
			l = m + 1,cnt = m;
		else
			r = m - 1;
	}
	cout<<cnt;
	return 0;
}
