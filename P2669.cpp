#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int k;
	cin>>k;
	int coin = 0,i,j,day = 0;
	for(i = 1;day <= k;i++){
		for(j = 1;j <= i;j++){
			coin += i;
			day++;
			if(day == k){
				cout<<coin<<endl;
				return 0;
			}
		}
	}
	return 0;
}
