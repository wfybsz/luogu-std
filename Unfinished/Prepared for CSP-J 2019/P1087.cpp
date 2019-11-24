#include <bits/stdc++.h>
using namespace std;

const int NR = 1e3 + 100;
int n;
char c;
bool t[NR];

void dfs(int u,int v){
	bool b = true,i = true;
	if(v > u){
		dfs(u,(u + v) / 2);
		dfs((u + v + 1) / 2,v);
	}
	for(int i = 0;i <= v - u;++i){
		if(t[u + i])
			b = false;
		else
			i = false;
	}
	if(b)
		putchar('B');
	else if(i)
		putchar('I');
	else
		putchar('F');
}

int main()
{
	cin>>n;
	do
		c = getchar();
	while(c != '0' and c != '1');
	int i = 0;
	while(c == '0' or c == '1'){
		t[i++] = (c == '1');
		c = getchar();
	}
	dfs(0,(1 << n) - 1);
	return 0;
}
