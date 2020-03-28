#include <bits/stdc++.h>
using namespace std;

int cx,cy,fx,fy,cd = 1,fd = 1,t,a[20][20];
char tmp;
int dir[5][3] = {
	{0,0,0},
	{0,-1,0},
	{0,0,1},
	{0,1,0},
	{0,0,-1}
};
int check[11][11][11][11][5][5];
//check[cx][cy][fx][fy][cd][fd]

int main()
{
	for(int i = 0;i <= 11;++i){
		a[i][0] = -1;
		a[0][i] = -1;
		a[11][i] = -1;
		a[i][11] = -1;
	}
	for(int i = 1;i <= 10;++i){
		for(int j = 1;j <= 10;++j){
			cin>>tmp;
			switch(tmp){
				case '*':a[i][j] = -1;break;
				case 'C':{
						cx = i;
						cy = j;
						break;
					}
				case 'F':{
						fx = i;
						fy = j;
						break;
					}
			}
		}
	}
	while(true){
		if(check[cx][cy][fx][fy][cd][fd] == 1){//loop
			putchar('0');
			return 0;
		} 
		check[cx][cy][fx][fy][cd][fd] = 1;
		++t;
		if(a[cx + dir[cd][1]][cy + dir[cd][2]] == -1){//cow change dir
			cd %= 4;
			++cd;
		}else{
			cx += dir[cd][1];
			cy += dir[cd][2];
		} 
		if(a[fx + dir[fd][1]][fy + dir[fd][2]] == -1){//fj change dir
			fd %= 4;
			++fd;
		}else{
			fx += dir[fd][1];
			fy += dir[fd][2];
		}
		if(cx == fx && cy == fy){//catch
			cout<<t;
			return 0;
		}
	}
	return 0;
}
