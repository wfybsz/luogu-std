#include <bits/stdc++.h>
using namespace std;

const int NR = 1e6;
int a[NR],b[NR],ans[NR];

void read(int a[]){
	char s[1000000];
	scanf("%s",s);
	a[0] = strlen(s);
	for(int i = 1;i <= a[0];i++)
		a[i] = s[a[0] - i] - '0';
}

void print(int a[]){
	for(int i = a[0];i >= 1;i--)
		cout<<a[i];
	cout<<endl;
}

void Plus(int a[],int b[],int ans[]){
	ans[0]= max(a[0],b[0]);
	for(int i = 1;i <= ans[0];i++){
		ans[i] += a[i] + b[i];
		ans[i + 1] = ans[i] / 10;
		ans[i] %= 10;
	}
	if(ans[ans[0] + 1] > 0)
		ans[0]++;
}

int main()
{
	read(a);
	read(b);
	Plus(a,b,ans);
	print(ans);
	return 0;
}
