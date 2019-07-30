#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5;
int n;
int a[NR] = {1,1},b[NR] = {1,2},c[NR];

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
	cin>>n;
	if(n <= 2){
		cout<<n;
		return 0;
	}
	for(int i = 1;i < n;i++){
		memset(c,0,sizeof(c));
		Plus(a,b,c);
		memcpy(a,b,sizeof(a));
		memcpy(b,c,sizeof(b));
	}
	print(a);
	return 0;
}
