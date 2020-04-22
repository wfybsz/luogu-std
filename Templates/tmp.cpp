#include <bits/stdc++.h>
#include "Template-Stack.cpp"
using namespace std;

Stack<int>s;

int main()
{
	s.push(1);
	s.push(2);
	while(!s.empty())
		cout<<s.pop()<<' ';
	return 0;
}
