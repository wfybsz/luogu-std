#include <bits/stdc++.h>
using namespace std;

const int NR = 1e6;
int n,a[NR + 5],cnt = 1;
bool flag;

int main()
{
	cin>>n;
	for(int i = 0;i < n;i++)
		cin>>a[i];
	flag = a[1] >= a[0];
	for(int i = 0;i < n;i++){
		if((!flag) && i == n - 1){
			cnt++;
			break;
		}
		if(flag && a[i] > a[i + 1]){
			cnt++;
			flag = !flag;
			continue;
		}
		if((!flag) && a[i] < a[i + 1]){
			cnt++;
			flag = !flag;
		}
	}
	cout<<cnt;
	return 0;
}
