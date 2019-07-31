#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int m,n;
	cin>>m>>n;
	int box[10];
	memset(box,0,sizeof(box));
	for(int i = m;i <= n;i++){
		for(int x = i;x != 0;x /= 10){
			box[x % 10]++;
		}
	}
	for(int i = 0;i < 10;i++)
		cout<<box[i]<<" ";
	return 0;
}
