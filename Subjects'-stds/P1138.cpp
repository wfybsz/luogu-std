#include <bits/stdc++.h>
using namespace std;

const int NR = 3e4;
int n,tmp,k,box[NR],cnt;

int main()
{
	cin>>n>>k;
	if(k > n){
		cout<<"NO RESULT";
		return 0;
	}
	for(int i = 0;i < n;i++){
		cin>>tmp;
		if(!box[tmp])
			cnt++;
		box[tmp]++;
	}
	if(k > cnt){
		cout<<"NO RESULT";
		return 0;
	}
	for(int i = 0,j = 0;j != k;i++){
		if(box[i])
			j++;
		if(j == k){
			cout<<i;
			break;
		}
	}
	return 0;
}
