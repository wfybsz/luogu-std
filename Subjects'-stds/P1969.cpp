#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int x;
	cin>>x;
	int y = x;
	int cnt = x;
	for(int i = 2;i <= n;i++){
		scanf("%d",&x);
		if(x > y)
			cnt += x - y;
		y = x;
	}
	cout<<cnt<<endl;
	return 0;
}
