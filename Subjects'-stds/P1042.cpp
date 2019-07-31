#include <bits/stdc++.h>
using namespace std;

const int NR = 1e6;
char c;
int sc11[NR][2],sc21[NR][2],i,j,k;

bool getchar_(char &c){
	c = getchar();
	return c != 'E';
}

void GOTONEXT(){
	if(sc11[i][0] >= 11 || sc11[i][1] >= 11)
		if(abs(sc11[i][0] - sc11[i][1]) > 1)
			i++;
	if(sc21[j][0] >= 21 || sc21[j][1] >= 21)
		if(abs(sc21[j][0] - sc21[j][1]) > 1)
			j++;
}

void W(){
	sc11[i][0]++;
	sc21[j][0]++;
	GOTONEXT();
}

void L(){
	sc11[i][1]++;
	sc21[j][1]++;
	GOTONEXT();
}

void otit(){
	for(;k <= i;k++)
		cout<<sc11[k][0]<<':'<<sc11[k][1]<<endl;
	puts("");
	for(k = 0;k <= j;k++)
		cout<<sc21[k][0]<<':'<<sc21[k][1]<<endl;
}

int main()
{
	while(getchar_(c)){
		switch(c){
			case 'W':W();break;
			case 'L':L();break;
			default:break;
		}
	}
	otit();
	return 0;
}
