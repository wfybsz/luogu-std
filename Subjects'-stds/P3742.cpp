#include <bits/stdc++.h>
using namespace std;

const int NR = 1e2;
int n;
char x[NR],y[NR],z[NR];

int main()
{
	cin>>n;
	scanf("%s%s",x,y);
	for(int i = 0;i < n;i++)
		if(x[i] < y[i]){
			cout<<-1;
			return 0;
		}
	for(int i = 0;i < n;i++){
		if(x[i] == y[i])
			z[i] = x[i];
		else
			z[i] = y[i];
	}
	printf("%s",z);
	return 0;
}
