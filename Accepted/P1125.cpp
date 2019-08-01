#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char s[110];
int box[26];
int ppp = 0;

bool prime(int q){
	if(q < 2)
		return false;
	for(int i = 2;i * i <= q;i++)
		if(q % i == 0)
			return false;
	return true;
}

void init(){
	cin.getline(s,200);
}

void True(){
	printf("Lucky Word\n");
	printf("%d", box[25] - box[ppp]);
}

void False(){
	printf("No Answer\n0");
}

int main()
{
	init();
	for(int i = 0;;i++){
		if(s[i] == '\0')
			break;
		box[int(s[i] - 97)]++;
	}
	sort(box,box + 26);
	
	while(true){
		if(box[ppp] > 0 || ppp == 24)
			break;
		ppp++;
	}
	if(prime(box[25] - box[ppp]))
		True();
	else
		False();
	return 0;
}
