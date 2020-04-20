#include <bits/stdc++.h>
using namespace std;

int tmp,tmp_,tmp__;
char c;
stack<int>a;

int main()
{
	while((c = getchar()) != '@'){
		if('0' <= c and c <= '9')
			tmp = tmp * 10 + c - '0';
		else
			switch(c){
				case '.':{
					a.push(tmp);
					tmp = 0;
				}break;
				case '+':{
					tmp_ = a.top();
					a.pop();
					tmp__ = a.top() + tmp_;
					a.pop();
					a.push(tmp__);
				}break;
				case '-':{
					tmp_ = a.top();
					a.pop();
					tmp__ = a.top() - tmp_;
					a.pop();
					a.push(tmp__);
				}break;
				case '*':{
					tmp_ = a.top();
					a.pop();
					tmp__ = a.top() * tmp_;
					a.pop();
					a.push(tmp__);
				}break;
				case '/':{
					tmp_ = a.top();
					a.pop();
					tmp__ = a.top() / tmp_;
					a.pop();
					a.push(tmp__);
				}
			}
	}
	cout<<a.top();
	return 0;
}
