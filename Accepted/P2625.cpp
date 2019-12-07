#include <bits/stdc++.h>
using namespace std;

const double PI = 3.1415926535898;
const int NR = 18000;
int front,back,turn[60],degree,tmp,I;
bool f[NR + 10];
char c;

int main()
{
	int n;
	cin>>n;
	for(int i = 1;i <= n;++i){
		while(c < 'a' or c > 'z')
			c = getchar();
		cin>>tmp;
		switch(c){
			case 'f':front += tmp;break;
			case 'b':back += tmp;break;
			case 'r':turn[++I] = tmp % 360;break;
			case 'l':turn[++I] = (720 - tmp) % 360;break;
		}
	}
	double ans = sqrt(front * front + back * back - 2 * front * back * cos(degree * PI / 180));
	printf("%f",ans);
	return 0;
}
