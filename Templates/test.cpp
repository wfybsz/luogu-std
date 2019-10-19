#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

class stack{
private:
	int a[1000000];
	int tp = 0;
public:
	void push(const int b){a[++tp] = b;}
	int pop(){return a[tp--];}
	int top()const{return a[tp];}
	int size()const{return tp;}
	bool empty()const{return !tp;}
}a;

int main()
{
	string s;
	int n,x;
	cin>>n;
	while(n--){
		cin>>s;
		if(s == "PUSH"){
			cin>>x;
			a.push(x);
		}else if(s == "POP")
			cout<<a.pop()<<endl;
		else if(s == "TOP")
			cout<<a.top()<<endl;
		else if(s == "SIZE")
			cout<<a.size()<<endl;
		else if(s == "EMPTY")
			if(a.empty())
				cout<<"QAQ"<<endl;
			else
				cout<<"qwq"<<endl;
		else if(s == "OvO"){
			for(int i = 0;i < s.size();++i)
				cout<<"OvO";
			putchar('\n');
		}
	}
	return 0;
}
