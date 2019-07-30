#include <bits/stdc++.h>
#define jd 0
#define st 1
#define bu 2
#define xy 3
#define sp 4
using namespace std;

const int NR = 200;
int n,na,nb,a[NR],b[NR],A,B;

void win(bool flag){
	if(flag)
		A++;
	else
		B++;
}

int main()
{
	scanf("%d%d%d",&n,&na,&nb);
	for(int i = 0;i < na;i++)
		scanf("%d",&a[i]);
	for(int i = 0;i < nb;i++)
		scanf("%d",&b[i]);
	for(int i = 0;i < n;i++){
		if(a[i % na] == b[i % nb])
			continue;
		switch(a[i % na]){
			case jd:{
				switch(b[i % nb]){
					case st:win(0);break;
					case bu:win(1);break;
					case xy:win(1);break;
					case sp:win(0);break;
				}
				break;
			}
			case st:{
				switch(b[i % nb]){
					case jd:win(1);break;
					case bu:win(0);break;
					case xy:win(1);break;
					case sp:win(0);break;
				}
				break;
			}
			case bu:{
				switch(b[i % nb]){
					case jd:win(0);break;
					case st:win(1);break;
					case xy:win(0);break;
					case sp:win(1);break;
				}
				break;
			}
			case xy:{
				switch(b[i % nb]){
					case jd:win(0);break;
					case st:win(0);break;
					case bu:win(1);break;
					case sp:win(1);break;
				}
				break;
			}
			case sp:{
				switch(b[i % nb]){
					case jd:win(1);break;
					case st:win(1);break;
					case bu:win(0);break;
					case xy:win(0);break;
				}
			}
		}
	}
	cout<<A<<' '<<B;
	return 0;
}
