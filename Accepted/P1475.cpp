#include <bits/stdc++.h>
using namespace std;

const int NR = 1e2 + 10;
int n,g[NR][NR],a,b,tmp;
bool c[NR][NR];

int main()
{
	cin>>n;
	for(int i = 1;i <= n;++i){
		cin>>a>>b;
		cin>>g[a][b];
		if(g[a][b] > 50)
			c[a][b] = true;
	}
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= n;++j){
			tmp = 0;
			if(i == j)
				continue;
			if(c[i][j]){
				cout<<i<<' '<<j<<endl;
				continue;
			}
			for(int k = 1;k <= n;++k){
				if(k == i or k == j)
					continue;
				if(c[i][k])
					tmp += g[k][j];
				if(tmp > 50)
					break;
			}
			if(tmp > 50){
				c[i][tmp] = true;
				cout<<i<<' '<<j<<endl;
			}
		}
	return 0;
}
