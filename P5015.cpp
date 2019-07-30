#include <bits/stdc++.h>
using namespace std;

char c[6];
int cnt;

int main()
{
	cin.getline(c,6);
	for(int i = 0;i < 6;i++)
		cnt += (('A' <= c[i] && c[i] <= 'Z') || ('a' <= c[i] && c[i] <= 'z') || ('0' <= c[i] && c[i] <= '9'));
	cout<<cnt;
	return 0;
}
