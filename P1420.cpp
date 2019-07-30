#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;

int main()
{
	int i = 0;
	int n;
	int cnt = 0,max = 0;;
	cin>>n;
	int x[n];
	memset(x,0,sizeof(x));
	for(i = 0;i < n;i++){
		if(i == 0){
			cin>>x[i];
			continue;
		}
		cin>>x[i];
		if(x[i - 1] + 1 == x[i])cnt++;
		else{
			if(cnt > max)max = cnt;
			cnt = 0;
		}
	}
	cout<<max + 1;
	return 0;
}
