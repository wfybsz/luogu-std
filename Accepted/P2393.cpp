#include <bits/stdc++.h>
using namespace std;

long double x,sum;

int main()
{
	while(scanf("%Lf",&x))
		sum += x * 100000;
	printf("%.5Lf",sum / 100000);
	return 0;
}
