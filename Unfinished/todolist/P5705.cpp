#include <bits/stdc++.h>
using namespace std;

stack<char>a;

int main()
{
	a.push(getchar());
	a.push(getchar());
	a.push(getchar());
	a.push(getchar());
	a.push(getchar());
	putchar(a.top()),a.pop();
	putchar(a.top()),a.pop();
	putchar(a.top()),a.pop();
	putchar(a.top()),a.pop();
	putchar(a.top()),a.pop();
	return 0;
}
