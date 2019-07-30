#include<cstdio>
using namespace std;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int c;
	c = a * 10 + b;
	c /= 19;
	printf("%d",c);
	return 0;
}
