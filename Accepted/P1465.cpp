#include <bits/stdc++.h>
using namespace std;

int n,I,V,X,L,C,D,M;
string s = "";

/*
I	1
IV	4
V	5
IX	9
X	10
XL	40
L	50
XC	90
C	100
CD	400
D	500
CM	900
M	1000
*/

string Do(int n){
	string s = "";
	while(n >= 1000){
		n -= 1000;
		s += 'M';
	}
	if(n >= 900){
		n -= 900;
		s += "CM";
	}
	if(n >= 500){
		n -= 500;
		s += 'D';
	}
	if(n >= 400){
		n -= 400;
		s += "CD";
	}
	while(n >= 100){
		n -= 100;
		s += 'C';
	}
	if(n >= 90){
		n -= 90;
		s += "XC";
	}
	if(n >= 50){
		n -= 50;
		s += 'L';
	}
	if(n >= 40){
		n -= 40;
		s += "XL";
	}
	while(n >= 10){
		n -= 10;
		s += 'X';
	}
	if(n >= 9){
		n -= 9;
		s += "IX";
	}
	if(n >= 5){
		n -= 5;
		s += 'V';
	}
	if(n >= 4){
		n -= 4;
		s += "IV";
	}
	while(n--)
		s += 'I';
	s += '\0';
	return s;
}

int main()
{
	cin>>n;
	for(int j = 1;j <= n;++j){
		s = Do(j);
		for(int i = 0;s[i] != '\0';++i)
			switch(s[i]){
				case 'I':++I;break;
				case 'V':++V;break;
				case 'X':++X;break;
				case 'L':++L;break;
				case 'C':++C;break;
				case 'D':++D;break;
				case 'M':++M;break;
			}
	}
	if(I)
		cout<<"I "<<I<<endl;
	if(V)
		cout<<"V "<<V<<endl;
	if(X)
		cout<<"X "<<X<<endl;
	if(L)
		cout<<"L "<<L<<endl;
	if(C)
		cout<<"C "<<C<<endl;
	if(D)
		cout<<"D "<<D<<endl;
	if(M)
		cout<<"M "<<M<<endl;
	return 0;
}
