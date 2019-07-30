#include<cstdio>
using namespace std;

int main()
{
	int a,b,c,d,e,f,g,h,i,j,k,l,m,n;
	int mon = 0,tue = 0,wed = 0,thu = 0,fri = 0,sat = 0,sun = 0;
	bool flag = false;
	scanf("%d %d",&a,&b);
	scanf("%d %d",&c,&d);
	scanf("%d %d",&e,&f);
	scanf("%d %d",&g,&h);
	scanf("%d %d",&i,&j);
	scanf("%d %d",&k,&l);
	scanf("%d %d",&m,&n);
	if(a + b > 8)
	{
		flag = true;
		mon = a + b;
	}
	if(c + d > 8)
	{
		flag = true;
		tue = c + d;
	}
	if(e + f > 8)
	{
		flag = true;
		wed = e + f;
	}
	if(g + h > 8)
	{
		flag = true;
		thu = g + h;
	}
	if(i + j > 8)
	{
		flag = true;
		fri = i + j;
	}
	if(k + l > 8)
	{
		flag = true;
		sat = k + l;
	}
	if(m + n > 8)
	{
		flag = true;
		sun = m + n;
	}
	int max = 0,da = 0;
	if(mon > max)
	{
		max = mon;
		da = 1;
	}	
	if(tue > max)
	{
		max = tue;
		da = 2;
	}
	if(wed > max)
	{
		max = wed;
		da = 3;
	}
	if(thu > max)
	{
		max = thu;
		da = 4;
	}
	if(fri > max)
	{
		max = fri;
		da = 5;
	}
	if(sat > max)
	{
		max = sat;
		da = 6;
	}
	if(sun > max)
	{
		max = sun;
		da = 7;
	}
	printf("%d\n",da);
	return 0;
}
