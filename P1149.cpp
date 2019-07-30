#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int a[10] = {6,2,5,5,4,5,6,3,7,6},n;

int num(int q){
	int cnt = 0;
	do
		cnt += a[q % 10];
	while(q /= 10);
	return cnt;
}

int main()
{
	int cnt = 0;
	cin>>n;
	n -= 4;
	for(int i = 0;i <= 1000;i++)
		for(int j = 0;j <= 1000;j++)
			if(num(i) + num(j) + num(i + j) == n)
				cnt++;
	cout<<cnt;
	return 0;
}
