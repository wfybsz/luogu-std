#include <bits/stdc++.h>
using namespace std;

const int NR = 2e2;
int n,a[NR * NR + 5],tmp,pos,i;
bool flag;

int main()
{
	cin>>n;
	while(cin>>tmp){
		for(i = pos;i < pos + tmp;i++)
			a[i] = flag;
		pos = i;
		flag = !flag;
	}
	pos = 0;
	for(int j = 0;j < n;j++){
		for(int k = 0;k < n;k++){
			cout<<a[pos];
			pos++;
		}
		cout<<endl;
	}
}
