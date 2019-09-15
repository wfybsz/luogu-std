#include<bits/stdc++.h>
using namespace std;

const int NR=100010;
int n,k,a[NR],mem[NR][22][3];

int dfs(int num,int x,int tree){
    if(!num)
        return 0;
    if(mem[num][x][tree])
        return mem[num][x][tree];
    int maxm = dfs(num - 1,x,tree);
    if(x != 0)
        for(int i = 0;i < 3;i++)
            if(i != tree)
                maxm = max(maxm,dfs(num - 1,x - 1,i));
    return mem[num][x][tree] = maxm + (tree == a[num]);
}

int main()
{
    cin>>n>>k;
	for(int i = 1;i <= n;)
		switch(getchar()){
			case 'P':++i;break;
			case 'H':a[i++] = 1;break;
			case 'S':a[i++] = 2;break;
		}
    int maxn = 0;
    for(int i = 0;i <= k;i++)
        for(int j = 0;j < 3;j++)
            maxn = max(maxn,dfs(n,i,j));
    cout<<maxn<<endl;
	return 0;
}
