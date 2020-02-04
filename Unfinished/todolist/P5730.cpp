#include <bits/stdc++.h>
using namespace std;

int x,i;
int ans[100];

char zero[5][3] = {
	"XXX",
	"X.X",
	"X.X",
	"X.X",
	"X.X",
	"XXX"
};

char one[5][3] = {
	"..X",
	"..X",
	"..X",
	"..X",
	"..X"
};

char two[5][3] = {
	"XXX",
	"..X",
	"XXX",
	"x..",
	"xxx"
};

char three[5][3] = {
	"xxx",
	"..x",
	"xxx",
	"..x",
	"xxx"
};

char four[5][3] = {
	"x.x",
	"x.x",
	"xxx",
	"..x",
	"..x"
};

char five[5][3] = {
	"xxx",
	"x..",
	"xxx",
	"..x",
	"xxx"
}

char six[5][3] = {
	"xxx",
	"x..",
	"xxx",
	"x.x",
	"xxx"
};

char seven[5][3] = {
	"xxx",
	"..x",
	"..x",
	"..x",
	"..x"
};

char eight[5][3] = {
	"xxx",
	"x.x",
	"xxx",
	"x.x",
	"xxx;"
}

char nine[5][3] = {
	"xxx",
	"x.x",
	"xxx",
	"..x",
	"xxx"
};

int main()
{
	scanf("%*d%d",&x);
	for(i = 1;x;++i){
		ans[i] = x % 10;
		x /= 10;
	}
	for(int j = 5;j;--j){
		int tmp = i;
		while(tmp--){
			if(tmp == 1)
				switch(ans[tmp]){
					case 0:cout<<zero[j];break;
					case 1:cout<<one[j];break;
					case 2:cout<<two[j];break;
					case 3:cout<<three[j];break;
					case 4:cout<<four[j];break;
					case 5:cout<<five[j];break;
					case 6:cout<<six[j];break;
					case 7:cout<<seven[j];break;
					case 8:cout<<eight[j];break;
					case 9:cout<<nine[j];break;
				}
			else
				switch(ans[tmp]){
					case 0:cout<<zero[j]<<'.';break;
					case 1:cout<<one[j]<<'.';break;
					case 2:cout<<two[j]<<'.';break;
					case 3:cout<<three[j]<<'.';break;
					case 4:cout<<four[j]<<'.';break;
					case 5:cout<<five[j]<<'.';break;
					case 6:cout<<six[j]<<'.';break;
					case 7:cout<<seven[j]<<'.';break;
					case 8:cout<<eight[j]<<'.';break;
					case 9:cout<<nine[j]<<'.';break;
				}
		}
		cout<<endl;
	}
	return 0;
}
