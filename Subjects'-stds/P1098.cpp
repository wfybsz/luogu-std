#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define secA (a < b)
#define secB ('a'<=a&&a<='z'&&'a'<=b&&b<='z')
#define secC ('0'<=a&&a<='9'&&'0'<=b&&b<='9')

int p1,p2,p3;
char s[100];

void init(){
	scanf("%d%d%d\n",&p1,&p2,&p3);
	cin.getline(s,105);
}

bool cmp(char a,char b){
	return secA && (secB || secC);
}

void little(char x,char y){
	if(p3 == 1){//little,front
		for(int i = int(x) + 1;i < int(y);i++)
			for(int j = 1;j <= p2;j++)
				printf("%c",i);
	}
	else{//little,back
		for(int i = int(y) - 1;i > int(x);i--)
			for(int j = 1;j <= p2;j++)
				printf("%c",i);
	}
}

void big(char x,char y){
	if('0'<x&&x<'9'&&'0'<y&&y<'9'){
		if(p3 == 1){//little,front
			for(int i = int(x) + 1;i < int(y);i++)
				for(int j = 1;j <= p2;j++)
					printf("%c",i);
		}
		else{//little,back
			for(int i = int(y) - 1;i > int(x);i--)
				for(int j = 1;j <= p2;j++)
					printf("%c",i);
		}
	}
	else
		if(p3 == 1){//big,front
			for(int i = int(x) + 1;i < int(y);i++)
				for(int j = 1;j <= p2;j++)
					printf("%c",i - 32);
		}else{//big,back
			for(int i = int(y) - 1;i > int(x);i--)
				for(int j = 1;j <= p2;j++)
					printf("%c",i - 32);
		}
}

void star(char x,char y){
	for(int i = int(x) + 1;i < int(y);i++)
			for(int j = 1;j <= p2;j++)
				printf("*");
}

int main()
{
	init();
	printf("%c",s[0]);
	for(int i = 1;i < strlen(s);i++){
		if(s[i] == '-' && cmp(s[i - 1],s[i + 1])){
			switch(p1){
				case 1:little(s[i - 1],s[i + 1]);break;
				case 2:big(s[i - 1],s[i + 1]);break;
				case 3:star(s[i - 1],s[i + 1]);break;
			}
		}
		else
			if(!int(s[i - 1]) + 1 == int(s[i + 1]))
				printf("-");
			else
				printf("%c",s[i]);
	}
	return 0;
}
