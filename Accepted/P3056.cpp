#include <bits/stdc++.h>
using namespace std;

const int NR = 1e9;
char c[NR];
int cnt,len,num;

int main(){
	scanf("%s",c);
	len=strlen(c);
	for(int i=0;i<len;i++)
		if(c[i]=='(')
			num++;
		else
			if(c[i]==')'&&num==0){
				cnt++;
				num++;
			}
			else
				num--;
	cnt += num / 2;
	if(num % 2 != 0)
		cnt++;
	cout<<cnt;
	return 0;
}
