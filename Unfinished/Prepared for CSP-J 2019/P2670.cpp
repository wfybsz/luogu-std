#include <bits/stdc++.h>
using namespace std;

const int NR = 1e2;
int n,m,mv[8][2] = {0,1,0,-1,1,0,1,1,1,-1,-1,0,-1,1,-1,-1},ans[NR][NR];
bool a[NR][NR];

int gen(int i,int j){
	int ret = 0;
	for(int k = 0;k < 8;++k)
		if(!a[i + mv[i][0]][j + mv[i][1]])
			++ret;
	return ret;
}

int main()
{
	cin>>n>>m;
	for(int i = 0;i < n;++i)
		for(int j = 0;j < m;)
			switch(getchar()){
				case '*':++j;
				case '?':a[i][j++] = true;
			}
	for(int i = 0;i < n;++i){
		for(int j = 0;j < m;++j)
			if(!a[i][j])
				putchar('*');
			else
				cout<<gen(i,j);
		putchar('\n');
	}
	return 0;
}
