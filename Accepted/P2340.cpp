#include <bits/stdc++.h>
using namespace std;

const int NR = 400 + 10;
const int MR = 3.5e4;
int n,iq[NR],eq[NR],f[NR][2 * MR + 10],ans;

int main()
{
	memset(f,-999999,sizeof(f));
	cin>>n;
	for(int i = 1;i <= n;++i)
		cin>>iq[i]>>eq[i];
	f[0][MR] = 0;
	for(int i = 1;i <= n;++i)
		for(int j = -MR;j <= MR;++j){
			f[i][j + MR] = f[i - 1][j + MR];
			if(j + MR - iq[i] >= 0 and j + MR - iq[i] <= MR * 2)
				f[i][j + MR] = max(f[i][j + MR],f[i - 1][j + MR - iq[i]] + eq[i]);
		}
	for(int i = 0;i <= MR;++i)
		if(f[n][i + MR] >= 0)
		ans = max(ans,f[n][i + MR] + i);
	cout<<ans;
	return 0;
}
