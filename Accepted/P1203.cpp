#include <bits/stdc++.h>
using namespace std;

const int NR = 1100;
//Left[i]表示第i个珠子必选的情况下左侧最长连珠
int Left[NR],Right[NR];
int blue[NR],red[NR];
char s[NR];

int main()
{
	int n;
	cin>>n;
	scanf("%s",s + 1);
	for(int i = 1;i <= n;i++)
		s[i + n] = s[i];
	//Left n + 1 - 2n
	for(int i = 1;i <= 2 * n;i++){
		red[i] = red[i - 1] + 1;
		blue[i] = blue[i - 1] + 1;
		if(s[i] == 'b')
			red[i] = 0;
		if(s[i] == 'r')
			blue[i] = 0;
		if(i > n)
			Left[i - n] = max(red[i],blue[i]);
	}
	//Right
	memset(blue,0,sizeof(blue));
	memset(red,0,sizeof(red));
	for(int i = 2 * n;i >= 1;i--){
		red[i] = red[i + 1] + 1;
		blue[i] = blue[i + 1] + 1;
		if(s[i] == 'b')
			red[i] = 0;
		if(s[i] == 'r')
			blue[i] = 0;
		Right[i] = max(red[i],blue[i]);
	}
	int ans = Left[n] + Right[1];
	for(int i = 1;i <= n;i++)
		ans = max(ans,Left[i] + Right[i + 1]);
	cout<<min(ans,n);
	return 0;
}
