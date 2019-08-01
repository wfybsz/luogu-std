#include <bits/stdc++.h>
using namespace std;

double d1,c,d2,p,maxn,ans,c_cur;
int n;
struct node{
	double p,d;
}a[10000];

int gotonext(int pos){
	int can = 1e9;
	int f = a[pos].d;
	for(int i = pos + 1;i <= n && a[i].d - f <= maxn;i++){
		if(a[i].p < a[pos].p){
			ans += ((a[i].d - c_cur - f) / d2) * a[pos].p;
			c_cur = 0;
			return i;
		}
		if(can == 1e9 || a[i].p < a[can].p)
			can = i;
	}
	if(d1 - a[pos].d <= maxn){
			ans += ((d1 - c_cur - a[pos].d) / d2) * a[pos].p;
			return -1e9;
		}
	if(can == 1e9){
		cout<<"No Solution";
		return -1;
	}
	else{
		ans += c * a[pos].p;
		c_cur += (maxn - a[can].d + f);
		return can;
	}
}

bool cmp(node a,node b){
	return a.d < b.d;
}

int main()
{
	cin>>d1>>c>>d2>>p>>n;
	a[0].p = p;
	for(int i = 1;i <= n;i++)
		cin>>a[i].d>>a[i].p;
	sort(a,a + n,cmp);
	maxn = c * d2;
	int k = 0,t;
	do{
		t = gotonext(k);
		k = t;
		if(t == -1)
			return 0;
	}while(t != -1e9);
	printf("%.2f",ans);
	return 0;
}
