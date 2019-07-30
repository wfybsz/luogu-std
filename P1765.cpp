#include <bits/stdc++.h>
using namespace std;

int cnt,len,a[26] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
char c[201];

int main()
{
	cin.getline(c,201);
	len = strlen(c);
	for(int i = 0;i < len;i++)
		if(c[i] == ' ')
			cnt++;
		else
			if('a' <= c[i] && c[i] <= 'z')
				cnt += a[c[i] - 'a'];
	cout<<cnt;
	return 0;
}
