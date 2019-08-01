#include<cstdio>
using namespace std;

int main()
{
	int a,b,c,d,e,f,g,h,i,j,max,num = 0;
	scanf("%d %d %d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j);
	scanf("%d",&max);	
	max += 30;
	if(max >= a)
		num += 1;
	if(max >= b)
		num += 1;
	if(max >= c)
		num += 1;
	if(max >= d)
		num += 1;
	if(max >= e)
		num += 1;
	if(max >= f)
		num += 1;
	if(max >= g)
		num += 1;
	if(max >= h)
		num += 1;
	if(max >= i)
		num += 1;
	if(max >= j)
		num += 1;
	printf("%d\n",num);
	return 0;
}
