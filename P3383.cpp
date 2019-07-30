#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	/*
	freopen("H:\\in.txt","r",stdin);
	freopen("H:\\out.txt","w",stdout);
	*/
	int n,m;
	cin>>n>>m;
	for(int j = 1;j <= m;j++)
	{
		int x;
		scanf("%d",&x);
		bool flag = true;
		if(x < 2)
			flag = false;
		for(int i = 2;i * i <= x;i++)
		{
			if(x % i == 0)
				flag = false;
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
