#include <bits/stdc++.h>
using namespace std;

int b,a[100];
char dict[12] = {'A','B','C','D','E','F','G','H','I','J','K','L'};
long long tmp;

bool pal(int x)
{
	int end = 1;
	while(x){
		a[end] = x % b;
		x /= b;
		end++;
	}
	end--;
	for(int i = 1;i <= (end + 1) / 2;i++)
		if(a[i] != a[end + 1 - i])
		return false;
	return true;
}

void print(int x)
{
	int end = 1;
	while(x){
		a[end] = x % b;
		x /= b;
		end++;
	}
	end--;
	for(int i = end;i >= 1;i--){
		if(a[i] < 10)
			cout<<a[i];
		else
			cout<<dict[a[i]-10];
	}
} 

int main()
{
	cin>>b;
	for(int i = 1;i <= 300;i++){
		if(pal(i * i)){
			print(i);
			cout<<' ';
			print(i * i);
			cout<<endl;
		}
	}
	return 0;
}
