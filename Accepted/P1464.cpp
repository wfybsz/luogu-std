#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define min(a,b) (a < b?a:b)

ll a,b,c,m[30][30][30];

long long dfs(int a,int b,int c){
	if(a <= 0 or b <= 0 or c <= 0)
		return 1;
	if(m[a][b][c] != -1)
		return m[a][b][c];
	if(a > 20 or b > 20 or c > 20)
		return m[a][b][c] = dfs(20,20,20);
	if(a < b and b < c)
		return m[a][b][c] = dfs(a,b,c - 1) + dfs(a,b - 1,c - 1) - dfs(a,b - 1,c);
	return m[a][b][c] = dfs(a - 1,b,c) + dfs(a - 1,b - 1,c) + dfs(a - 1,b,c - 1) - dfs(a - 1,b - 1,c - 1);
}

int main()
{
	while(cin>>a>>b>>c){
		memset(m,-1,sizeof(m));
		if(a == -1 and b == -1 and c == -1)
			break;
		cout<<"w("<<a<<", "<<b<<", "<<c<<") = ";
		a = min(a,21);
		b = min(b,21);
		c = min(c,21);
		cout<<dfs(a,b,c)<<endl;
	}
	return 0;
}
