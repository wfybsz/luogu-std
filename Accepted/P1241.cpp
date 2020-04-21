#include <bits/stdc++.h>
using namespace std;

const int NR = 1e2 + 10;
char s[NR],b[NR];
stack<int>q;

int main()
{
	scanf("%s",s);
	for(int i = 0;s[i] != '\0';++i){
		if(s[i] == '('){
			q.push(i);
			b[i] = ')';
		}
		if(s[i] == '['){
			q.push(i);
			b[i] = ']';
		}
		if(s[i] == ')' or s[i] == ']')
			if(q.empty() || b[q.top()] != s[i])
				if(s[i] == ')')
					b[i] = '(';
				else
					b[i] = '[';
			else{
				b[q.top()] = ' ';
				q.pop();
			}
	}
	for(int i = 0;s[i] != '\0';++i){
		if(b[i] == '(' or b[i] == '[')
			putchar(b[i]);
		putchar(s[i]);
		if(b[i] == ')' or b[i] == ']')
			putchar(b[i]);
	}
	return 0;
}
