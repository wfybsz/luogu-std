#include<iostream>
using namespace std;

int a[20],n,k;

bool prime(int q){
	if(q < 2)
		return false;
	for(int i = 2;i * i <= q;i++)
		if(!(q % i))
			return false;
	return true;
}
int Do(int digit,int now,int last){
	if(!digit)
		return prime(now);
	int sum = 0;
	for(int i = last;i < n;i++){
		sum += Do(digit - 1,now + a[i],i + 1);
	}
	return sum;
}
int main(){
	cin>>n>>k;
	for(int i = 0;i < n;i++)
		cin>>a[i];
	cout<<Do(k,0,0);
	return 0;
}
