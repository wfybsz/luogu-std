#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char s[110];
int box[26];

int main()
{
	for(int i = 1;i <= 4;i++){
		cin.getline(s,120);
		for(int j = 0;;j++){
			if(s[j] == '\0')
			break;
			if(!int(s[j]) > 64 && int(s[j]) < 91){
				continue;
			}
			else
			box[int(s[j]) - 65]++;
		}
	}
	int b[26];
	for(int i = 0;i < 26;i++)
		b[i] = box[i];
	sort(b,b + 26);
	for(int i = b[25];i > 0;i--){
		for(int j = 0;j < 26;j++){
			if(j == 25){
				if(box[j] >= i){
					cout<<"*";
				}
				else{
					cout<<" ";
				}
			}
			else{
				if(box[j] >= i){
					cout<<"* ";
				}
				else{
					cout<<"  ";
				}
			}
		}
		cout<<endl;
	}
	for(int i = 65;i < 90;i++)
		printf("%c ",i);
	printf("Z");
	return 0;
}
/*THE QUICK BROWN FOX JUMPED OVER THE LAZY DOG.
THIS IS AN EXAMPLE TO TEST YOUR
HISTORGRAM PROGRAM.
HELLO!*/
