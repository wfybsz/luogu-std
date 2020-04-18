#include <bits/stdc++.h>
using namespace std;

string s;

char dfs(string s){
	if (s.length() > 1){
		putchar(dfs(s.substr(0,s.length() / 2)));
		putchar(dfs(s.substr(s.length() / 2,s.length() / 2)));
	}
	if (s == string(s.length(),'0'))
		return 'B';
	if (s == string(s.length(),'1'))
		return 'I';
	return 'F';
}

int main()
{
	scanf("%*d");
	cin>>s;
	putchar(dfs(s));
	return 0;
}
