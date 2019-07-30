#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5;
int n,a[NR + 5];

void read(int a[]){
	char s[NR + 5];
	scanf("%s",s);
	a[0] = strlen(s);
	for(int i = 1;i <= a[0];i++)
		a[i] = s[a[0] - i] - '0';
}

int main()
{
	cin>>n;
	while(n--){
		read(a);
		if(a[1] % 2)
			cout<<"odd"<<endl;
		else
			cout<<"even"<<endl;
	}
	return 0;
}
