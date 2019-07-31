#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

bool prime(int q){
	for(int i = 2;i * i <= q;i++)
		if(q % i == 0)
			return false;
	return true;
}

int main()
{
	int n;
	cin>>n;
	for(int i = 4;i <= n;i += 2){
		for(int j = 2;j != i - 1;j++){
			if(prime(j) && prime(i - j)){
				printf("%d=%d+%d\n",i,j,i - j);
				break;
			}
		}
	}
	return 0;
}
