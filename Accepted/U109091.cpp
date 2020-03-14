#include <bits/stdc++.h>
using namespace std;

int m;
bool used[10],flag[10];

bool finished(){
	for(int i = 1;i < 10;++i)
		if(flag[i] == true && used[i] == false)
			return false;
	return true;
}

bool check(int n){
	memset(flag,false,sizeof(flag));
	string s = "";
	int tmp,sum = 0;
	while(n){
		tmp = n % 10;
		if(tmp == 0 or flag[tmp] == true)
		return false;
		flag[tmp] = true;
		sum += tmp;
		s += tmp + '0';
		n /= 10;
	}
	memset(used,0,sizeof(used));
	int pos = s.length() - 1;
	used[s[pos] - '0'] = 1;
	while(!finished()){
		pos -= s[pos] - '0';
		pos = (pos + s.length() * 10) % s.length();
		if(used[s[pos] - '0'])
			return false;
		used[s[pos] - '0'] = true;
		if(s[pos] == s[s.length() - 1])
			return false;
	}
		pos -= s[pos] - '0';
		pos = (pos + s.length() * 10) % s.length();
	if(s[pos] == s[s.length() - 1])
		return true;
	return false;
}

int main()
{
	cin>>m;
	while(not(check(++m)));
	cout<<m;
	return 0;
}
