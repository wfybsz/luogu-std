#include<bits/stdc++.h>
using namespace std;
struct Stu
{
	int y,s,e,num;
};

bool cmp(Stu x,Stu y){
	if(x.y + x.s + x.e != y.y + y.s + y.e)
		return x.y + x.s + x.e > y.y + y.s + y.e;
	if(x.y != y.y)
		return x.y > y.y;
	return x.num <= y.num;
}

int main()
{
	int n;
	cin>>n;
	Stu a[n + 1];
	for(int i = 1;i <= n;i++){
		cin>>a[i].y>>a[i].s>>a[i].e;
		a[i].num = i;
	}
	sort(a + 1,a + 1 + n,cmp);
	for(int i = 1;i <= 5;i++)
		cout<<a[i].num<<" "<<a[i].y + a[i].s + a[i].e<<endl;
	return 0;
}
