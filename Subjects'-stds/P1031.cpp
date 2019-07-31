#include <bits/stdc++.h>
using namespace std;

const int NR = 1e2;
int n,sum,ave,a[NR],s;

int main()
{
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>a[i];
		sum += a[i];
	}
	ave = sum / n;
	for(int i = 0;i < n;i++){
		if(a[i] == ave)
			continue;
		else{
			a[i + 1] += (a[i] - ave);
			s++;
		}
	}
	cout<<s;
	return 0;
}
