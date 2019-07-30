#include <cstdio>
#include <iostream>
using namespace std;

char c[11];
int cnt;

int d(char c){
	return c - '0';
}

int main()
{
	scanf("%c-%c%c%c-%c%c%c%c%c-%c",&c[1],&c[2],&c[3],&c[4],&c[5],&c[6],&c[7],&c[8],&c[9],&c[10]);
	for(int i = 1;i <= 9;i++)
		cnt += d(c[i]) * i;
	if(cnt % 11 == d(c[10])){
		cout<<"Right";
		return 0;
	}
	if(cnt % 11 == 10 && c[10] == 'X'){
		cout<<"Right";
		return 0;
	}
	if(cnt % 11 < 10)
		printf("%c-%c%c%c-%c%c%c%c%c-%d",c[1],c[2],c[3],c[4],c[5],c[6],c[7],c[8],c[9],cnt % 11);
	else
		printf("%c-%c%c%c-%c%c%c%c%c-X",c[1],c[2],c[3],c[4],c[5],c[6],c[7],c[8],c[9]);
	return 0;
}
