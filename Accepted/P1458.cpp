#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int NR = 1e5;
int n,tmp;
struct node{
	int s,m;
	double x;
}a[NR];

bool rePrime(int a,int b){
    for(int i = 2;i <= 170;++i)
        if(a % i == 0 and b % i == 0)
            return false;
    return true;
}

bool cmp(node a,node b){
	return a.x < b.x;
}

int main()
{
	cin>>n;
	for(double i = 1;i <= n;++i)
		for(double j = 1;j < i;++j){
			a[++tmp].s = j;
			a[tmp].m = i;
			a[tmp].x = j / i;
		}
	sort(a + 1,a + 1 + tmp,cmp);
	cout<<"0/1"<<endl;
	for(int i = 1;i <= tmp;++i)
		if(rePrime(a[i].s,a[i].m))
			cout<<a[i].s<<'/'<<a[i].m<<endl;
	cout<<"1/1"<<endl;
	return 0;
}
