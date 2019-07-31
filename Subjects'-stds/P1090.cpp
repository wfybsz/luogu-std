#include <bits/stdc++.h>
using namespace std;

const int NR = 1e4;
int n,a[NR + 5],cnt;

int main()
{
	cin>>n;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	sort(a + 1,a + 1 + n);
	for(int i = 1;i < n;i++){
		cnt += a[i] + a[i + 1];
		a[i + 1] += a[i];
		for(int j = i + 1;j < n;j++)
			if(a[j] > a[j + 1])
				swap(a[j],a[j + 1]);
			else
				break;
	}
	cout<<cnt;
	return 0;
}
