#include<cstdio>
using namespace std;

int main()
{
	int a,b,c,d; 
	scanf("%d%d",&a,&b);
	scanf("%d%d",&c,&d);
	int stmin,enmin;
	stmin = 60*a + b;
	enmin = 60*c + d;
	int ptjm;
	ptjm = enmin - stmin;
	int e,f;
	e = ptjm / 60;
	f = ptjm % 60;
	printf("%d %d",e,f);
	return 0;
 } 
