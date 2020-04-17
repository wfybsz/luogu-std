#include <bits/stdc++.h>
using namespace std;

int len,tmp,maxn;
char s[1000000];

int main()
{
	scanf("%*d%s",s);
	len = strlen(s);
	for(int i = 0;i < len;++i)
		switch (s[i]){
			case 'I':maxn = max(maxn,++tmp);break;
			case 'D':--tmp;break;
		}
	cout<<maxn<<endl;
	return 0;
}
