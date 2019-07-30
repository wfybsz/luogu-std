#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5;
int a[NR],b;

void read(int a[]){
	char s[NR];
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

void div(int a[],int b,int ans[]){
	ans[0] = a[0];
	for(int i = 1;i <= a[0];i++)
		ans[i]=  a[i];
	ans[ans[0] + 1] = 0;
	for(int i = ans[0];i >= 1;i--)
		ans[i] += ans[i + 1] % b * 10;
	for(int i = ans[0];i >= 1;i--)
		ans[i] /= b;
	while(ans[ans[0]] == 0)
		ans[0]--;
}

int main()
{
	read(a);
	cin>>b;
	div(a,b,a);
	print(a);
	return 0;
}
