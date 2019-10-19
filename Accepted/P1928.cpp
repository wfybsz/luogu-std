#include <bits/stdc++.h>
using namespace std;

string _s;

string str(string s,int l,int r){
	string ret = "";
	for(int i = l;i <= r;++i)
		ret += s[i];
	return ret;
}

string f(string s,int l,int r,int t = 1){
	bool flag = true;
	int _l,_r;
	for(_l = l;_l <= r;++_l)
		if(s[_l] == '['){
			flag = false;
			break;
		}
	if(flag){
		string ret = "";
		string x = str(s,l + 1,r);
		if((t / 10))
			x = str(s,l + 2,r);
		while(t--)
			ret += x;
		return ret;
	}
	else{
		t = s[_l + 1] - '0';
		if('0' <= s[_l + 2] and s[_l + 2] <= '9'){
			t *= 10;
			t += s[_l + 2] - '0';
		}
		for(_r = r;s[_r] != ']';--_r);
		string RET = "";
		if(_l != l)
			RET += str(s,l,_l - 1);
		RET += f(s,_l + 1,_r - 1,t);
		if(_r != r)
			RET += str(s,_r + 1,r);
		return RET;
	}
}

int main()
{
	cin>>_s;
	cout<<f(_s,0,_s.length());
	return 0;
}
