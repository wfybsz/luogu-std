#include <cstdio>
#include <algorithm>
using namespace std;

long long n,m,a;

int main()
{
	scanf("%lld%lld%lld",&n,&m,&a);
	if(n % a == 0)
		n /= a;
	else
		n = n / a + 1;
	if(m % a == 0)
		m /= a;
	else
		m = m / a + 1;
	printf("%lld",n * m);
	return 0;
}
