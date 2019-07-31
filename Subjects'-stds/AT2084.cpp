#include <bits/stdc++.h>
using namespace std;

char s[101];
bool flag;
int Cdir;

int main()
{
	scanf("%s",s);
	for(int i = 0;s[i] != '\0';i++){
		if(s[i] == 'C'){
			flag = true;
			Cdir = i;
			break;
		}
	}
	if(flag)
		for(int i = Cdir + 1;s[i] != '\0';i++){
			if(s[i] == 'F'){
				cout<<"Yes";
				return 0;
			}
		}
	cout<<"No";
	return 0;
}
