#include <bits/stdc++.h>
using namespace std;

int a[3];
char c;

int main()
{
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a + 3);
	c = getchar();
	c = getchar();
	c = getchar();
	switch(c){
		case 'A':cout<<a[0]<<' ';break;
		case 'B':cout<<a[1]<<' ';break;
		case 'C':cout<<a[2]<<' ';break;
	}
	c = getchar();
	switch(c){
		case 'A':cout<<a[0]<<' ';break;
		case 'B':cout<<a[1]<<' ';break;
		case 'C':cout<<a[2]<<' ';break;
	}
	c = getchar();
	switch(c){
		case 'A':cout<<a[0];break;
		case 'B':cout<<a[1];break;
		case 'C':cout<<a[2];break;
	}
	return 0;
}
