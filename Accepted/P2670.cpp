#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int NR = 1e2 + 10;
int n,m,a[NR][NR];
bool flag[NR][NR];
char s[NR];

int check(int x,int y){
	int ret = 0;
	if(flag[x - 1][y])++ret;
	if(flag[x][y - 1])++ret;
	if(flag[x - 1][y - 1])++ret;
	if(flag[x + 1][y])++ret;
	if(flag[x][y + 1])++ret;
	if(flag[x + 1][y + 1])++ret;
	if(flag[x - 1][y + 1])++ret;
	if(flag[x + 1][y - 1])++ret;
	return ret;
}

int main()
{
	cin>>n>>m;
	for(int i = 1;i <= n;++i){
		cin>>s;
		for(int j = 0;j < m;++j)
			flag[i][j + 1] |= s[j] == '*';
	}
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= m;++j)
			if(flag[i][j])
				putchar('*');
			else
				cout<<check(i,j);
		putchar('\n');
	}
	return 0;
}
