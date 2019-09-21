#include <bits/stdc++.h>
using namespace std;

const int NR = 400 * 2;
char s[NR];
int Left[NR],Right[NR],red[NR],blue[NR],maxn;

int main()
{
	int n;
	cin>>n;
	scanf("%s",s + 1);
	for(int i = 1;i <= n;++i)
		s[i + n] = s[i];
	for(int i = 1;i <= 2 * n;++i){
		red[i] = red[i - 1] + 1;
		if(s[i] == 'b')
			red[i] = 0;
		blue[i] = blue[i - 1] + 1;
		if(s[i] == 'r')
			blue[i] = 0;
		Left[i] = max(red[i],blue[i]);
	}
	for(int i = n + 1;i <= 2 * n;++i)
		cout<<Left[i]<<' ';
	cout<<endl;
	memset(red,0,sizeof(red));
	memset(blue,0,sizeof(blue));
	for(int i = 2 * n;i >= 1;--i){
		red[i] = red[i + 1] + 1;
		if(s[i] == 'b')
			red[i] = 0;
		blue[i] = blue[i + 1] + 1;
		if(s[i] == 'r')
			blue[i] = 0;
		Right[i] = max(red[i],blue[i]);
	}
	for(int i = n + 1;i <= 2 * n;++i)
		cout<<Right[i]<<' ';
	for(int i = 1;i <= n;++i){
		int a = i,b = i + 1;
		if(b > n)
			b = 1;
		maxn = max(maxn,Left[a + n],Right[b]);
	}
	cout<<min(maxn,n);
	return 0;
}
