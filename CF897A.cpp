#include <cstdio>
#include <iostream>
using namespace std;

int n,m,l,r;
char c[105],c1,c2;

int main()
{
	cin>>n>>m;
	scanf("%s",c);
	for(int i = 1;i <= m;i++){
		cin>>l>>r>>c1>>c2;
		for(int j = l - 1;j < r;j++)
			if(c[j] == c1)
				c[j] = c2;
	}
	printf("%s",c);
	return 0;
}
