#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5;
int n,a[NR] = {1},b[NR] = {1},ans[NR] = {1},t[NR] = {1},tmp[NR] = {1};
int x;

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
	puts("");
}

void Time(int a[],int b,int ans[]){
	ans[0] = a[0] + 1;
	for(int i = 1;i <= ans[0];i++)
		ans[i] = a[i] * b;
	for(int i = 1;i < ans[0];i++){
		ans[i + 1] += ans[i] / 10;
		ans[i] %= 10;
	}
	while(ans[ans[0]] >= 10){
		ans[ans[0] + 1] = ans[ans[0]] / 10;
		ans[ans[0]] %= 10;
		ans[0]++;
	}
	while(ans[ans[0]] == 0 && ans[0] > 1)
		ans[0]--;
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

bool cmp(int a[],int b[]){
	if(a[0] != b[0])
		return a[0] < b[0];
	for(int i = a[0];i >= 1;i--)
		if(a[i] != b[i])
			return a[i] < b[i];
	return false;
}

int main()
{
	cin>>n;
	for(int i = 0;i <= n;i++)
		cin>>a[i]>>b[i];
	for(int i = 1;i <= n;i++)
		for(int j = i + 1;j <= n;j++)
			if(a[i] * b[i] > a[j] * b[j]){
				swap(a[i],a[j]);
				swap(b[i],b[j]);
			}
	memset(t,0,sizeof(t));
	t[0] = t[1] = 1;
	Time(t,a[0],t);
	for(int i = 1;i <= n;i++){
		div(t,b[i],tmp);
		if(cmp(ans,tmp))
			memcpy(ans,tmp,sizeof(tmp));
		Time(t,a[i],t);
	}
	print(ans);
	return 0;
}
