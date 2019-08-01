#include <iostream>
using namespace std;

int n,a[19] = {1,1};

int main()
{
	cin>>n;
	for(int i = 2;i <= n;i++)
		for(int j = 0;j < i;j++)
			a[i] += a[j] * a[i - j - 1];
	cout<<a[n];
	return 0;
}
