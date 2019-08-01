#include <iostream>
using namespace std;

int a = 1,b = 1;
char c[10];

int main()
{
	cin.getline(c,7);
	for(int i = 0;c[i] != '\0';i++)
		a *= c[i] - 'A' + 1;
	cin.getline(c,7);
	for(int i = 0;c[i] != '\0';i++)
		b *= c[i] - 'A' + 1;
	if(a % 47 == b % 47)
		cout<<"GO";
	else
		cout<<"STAY";
	return 0;
}
