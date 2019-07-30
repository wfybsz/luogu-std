#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n,m,cnt = 0;
	cin>>n>>m;
	bool b[n + 5];
	memset(b,0,sizeof(b));
	int num = n,tmp = 1;
	while(num > 0){
		for(int i = tmp;cnt != m;i++){
			if(i > n)
				i %= n;
			if(b[i] == true)
				continue;
			++cnt;
			if(cnt == m){
				b[i] = true;
				num--;
				tmp = i + 1;
				cout<<i<<" ";
				break;
			}
		}
		cnt = 0;
	}
	return 0;
}
