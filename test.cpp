#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;

SYSTEMTIME st = {0};
int a,b;

int main()
{
	while(true){
		system("cls");
		GetLocalTime(&st);
		srand(st.wMilliseconds);
		if(st.wMilliseconds % 2){
			a = (rand() % 100) % 20;
			b = (rand() % 100) % 20;
			cout<<max(a,b)<<" - "<<min(a,b)<<" =";
			getch();
		}else{
			while(true){
				a = (rand() % 100) % 20;
				b = (rand() % 100) % 20;
				if(a + b > 20)
					continue;
				else
					break;
			}
			cout<<a<<" + "<<b<<" =";
			getch();
		}
	}
	return 0;
}
