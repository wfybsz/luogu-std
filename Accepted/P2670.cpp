#include <bits/stdc++.h>
using namespace std;

const int NR = 1e2 + 10;
int n,m,a[NR][NR];

void Do(int& a){
	if(a == -1)
		return;
	++a;
}

int main()
{
	cin>>n>>m;
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= m;)
			switch(getchar()){
				case '*':a[i][j++] = -1;
				case '?':++j;
			}
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= m;++j)
			if(a[i][j] == -1){
				Do(a[i - 1][j - 1]);
				Do(a[i - 1][j]);
				Do(a[i - 1][j + 1]);
				Do(a[i][j - 1]);
				Do(a[i][j + 1]);
				Do(a[i + 1][j - 1]);
				Do(a[i + 1][j]);
				Do(a[i + 1][j + 1]);
			}
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= m;++j)
			if(a[i][j] == -1)
				putchar('*');
			else
				cout<<a[i][j];
		cout<<endl;
	}
	return 0;
}
