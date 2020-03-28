#include <bits/stdc++.h>
using namespace std;

const int NR = 1e4 + 10;
const int MR = 1e9 + 9;
int n,dp[NR][15][15],num;

bool prime(int q){
	if(q < 2)
		return false;
	for(int i = 2;i * i <= q;++i)
		if(q % i == 0)
			return false;
	return true;
}

int main(){
	cin>>n;
	for(int i = 1;i < 10;++i)
		for(int j = 0;j < 10;++j)
			dp[2][i][j] = 1;
	for(int i = 3;i <= n;++i)
		for(int j = 0;j < 10;++j)
			for(int k = 0;k < 10;++k)
				for(int l = 1;l < 10;++l)
					if(prime(l * 100 + j * 10 + k)){
						dp[i][j][k] += dp[i - 1][l][j];
						dp[i][j][k] %= MR;
					}
	for(int i = 0;i < 10;++i)
		for(int j = 0;j < 10;++j){
			num += dp[n][i][j];
			num %= MR;
		}
	cout<<num;
	return 0;
}
