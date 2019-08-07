#include <bits/stdc++.h>
using namespace std;

bool mem[21][21][21];
int maxa,maxb,maxc;
priority_queue<int,vector<int>,greater<int> >ans;

void ms(int a,int b,int c){
	if(mem[a][b][c])
		return;
	mem[a][b][c] = true;
	if(a){
		int x = min(a,maxb - b);
		ms(a - x,b + x,c);
		x = min(a,maxc - c);
		ms(a - x,b,c + x);
	}else{
		ans.push(c);
	}
	if(b){
		int x = min(b,maxa - a);
		ms(a + x,b - x,c);
		x = min(b,maxc - c);
		ms(a,b - x,c + x);
	}
	if(c){
		int x = min(c,maxa - a);
		ms(a + x,b,c - x);
		x = min(c,maxb - b);
		ms(a,b + x,c - x);
	}
}

int main()
{
	cin>>maxa>>maxb>>maxc;
	ms(0,0,maxc);
	while(!ans.empty()){
		cout<<ans.top()<<' ';
		ans.pop();
	}
	return 0;
}
