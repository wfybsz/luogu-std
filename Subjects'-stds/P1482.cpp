#include <bits/stdc++.h>
using namespace std;

int s1,m1,s2,m2,s,m;
bool flag = true;

int main()
{
	scanf("%d/%d",&s1,&m1);
	scanf("%d/%d",&s2,&m2);
	s = s1 * s2;
	m = m1 * m2;
	while(flag){
		flag = false;
		for(int i = min(s,m);i > 1;i--)
			if(s % i == 0 && m % i == 0){
				flag = true;
				s /= i;
				m /= i;
			}
	}
	cout<<m<<' '<<s;
	return 0;
}
