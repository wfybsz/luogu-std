#include <bits/stdc++.h>
using namespace std;

const int NR = 1e3 + 10;
int n;
struct node{
	int x,id;
}a[NR];

bool cmp(node a,node b){
	return a.x > b.x;
}

int main()
{
	cin>>n;
	for(int i = 1;i <= n;++i){
		cin>>a[i].x;
		a[i].id = i;
	}
	sort(a + 1,a + n + 1,cmp);
	cout<<a[1].id<<' '<<a[2].x;
	return 0;
}
