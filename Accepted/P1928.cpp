#include <bits/stdc++.h>
using namespace std;

string Do(){
	string s = "",a;
	char c;
	int num;
	while(cin>>c)
		if(c == '['){
			cin>>num;
			a = Do();
			while(num--)
				s += a;
		}else 
  			if(c == ']')
				return s;
			else
  				s += c;
}

int main()
{
	cout<<Do();
	return 0;
}
