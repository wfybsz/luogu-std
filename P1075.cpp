#include<cstdio>
using namespace std;

int main()
{
	int n,x,y;
	scanf("%d",&n);
	for(int i = 2;i * i <= n;i++)
	{
		if(n % i == 0)
		{
			x = n / i;
			y = n / x;
		}	
	}
	if(x > y)
			printf("%d\n",x);
		else
			printf("%d\n",y);
	return 0;
}
