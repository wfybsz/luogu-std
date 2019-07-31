#include <cstdio>
using namespace std;

int gys(int p,int q){
	for(;;){
		if(p > q)
			p -= q;
		else
			if(p < q)
			q -= p;
		else
			if(p == q)
			return p;
	}
}

int main()
{	int a,b,l;
	scanf("%d%d%d",&a,&b,&l);
	double m;
	m =(double) a / b;
	int p, q;
	double min = 10000000;
	for(int i = 1;i <= l;i++)
	{
		for(int j = 1; j <= l; j ++)
		{
			if (gys(i,j) != 1) continue;
			double n;
			n = (double) i / j;
			if (n < m) continue;
			//printf("%d %d %f %f\n", i, j, n, m);
			if (n - m >= min) continue;
			//printf("%d %d\n", i, j);
		 
			min = n - m;
			p = i;
			q = j;
			//printf("%d %d\n", p, q);
			
		}
	}
	printf("%d %d",p,q);
	return 0;
}
