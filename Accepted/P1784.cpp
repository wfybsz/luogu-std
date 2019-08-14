#include <bits/stdc++.h>
using namespace std;
#define f(i) for(int i = 1;i < NR;i++)

const int NR = 10;
int a[NR][NR];
bool flag1[NR][NR],flag2[NR][NR],flag3[NR][NR];
int map_[NR][NR] = {{},
	{0,1,1,1,2,2,2,3,3,3},
	{0,1,1,1,2,2,2,3,3,3},
	{0,1,1,1,2,2,2,3,3,3},
	{0,4,4,4,5,5,5,6,6,6},
	{0,4,4,4,5,5,5,6,6,6},
	{0,4,4,4,5,5,5,6,6,6},
	{0,7,7,7,8,8,8,9,9,9},
	{0,7,7,7,8,8,8,9,9,9},
	{0,7,7,7,8,8,8,9,9,9}};

void dfs(int x,int y){
	if(y > 9){
		x++;
		y = 1;
	}
	if(x > 9){
		f(i){
			f(j)
				cout<<a[i][j]<<' ';
			puts("");
		}
		exit(0);
	}
	if(a[x][y])
		dfs(x,y + 1);
	else{
		f(k){
			if(flag1[x][k])
				continue;
			if(flag2[y][k])
				continue;
			if(flag3[map_[x][y]][k])
				continue;
			a[x][y] = k;
			flag1[x][k] = flag2[y][k] = flag3[map_[x][y]][k] = true;
			dfs(x,y + 1);
			a[x][y] = 0;
			flag1[x][k] = flag2[y][k] = flag3[map_[x][y]][k] = false;
		}
	}
}

int main()
{
	f(x)
		f(y){
			cin>>a[x][y];
			if(a[x][y]){
				flag1[x][a[x][y]] = true;
				flag2[y][a[x][y]] = true;
				flag3[map_[x][y]][a[x][y]]=  true;
			}
		}
	dfs(1,1);
	return 0;
}
