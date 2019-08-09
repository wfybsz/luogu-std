#include <bits/stdc++.h>
using namespace std;

const int NR = 40;
int n;//必要维生素的数量
int need[NR];//need[i]代表第i种维生素需要的量
int g;//饲料种数
int food[NR][NR];//food[i][j]表示第种饲料提供的第j种维生素的数量
int m;//需要选m种
int a[NR];//a[i]表示选择的第i个是几号饲料

//从g个里面选m个

bool check(){
	int cnt[NR];
	memset(cnt,0,sizeof(cnt));
	for(int i = 1;i <= m;i++)
		for(int j = 1;j <= n;j++)
			cnt[j] += food[a[i]][j];
	for(int i = 1;i <= n;i++)
		if(cnt[i] < need[i])
			return false;
	return true;
}

void f(int x_min,int step){
	if(step > m){
		if(check()){
			cout<<m<<' ';
			for(int i = 1;i <= m;i++)
				cout<<a[i]<<' ';
			puts("");
			exit(0);
		}
		return;
	}
	for(int i = x_min;i <= g;i++){
		a[step] = i;
		f(i + 1,step + 1);
	}
}

int main()
{
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>need[i];
	}
	cin>>g;
	for(int i = 1;i <= g;i++)
		for(int j = 1;j <= n;j++)
			cin>>food[i][j];
	for(int i = 1;i <= g;i++){
		m = i;
		f(1,1);
	}
	return 0;
}
