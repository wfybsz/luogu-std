#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int NR = 510;
int n,m;
int a[NR][NR];

void dfs(int x,int y){
    if(y > m + 1){
        x++;
        y = 1;
    }
    if(x > n + 1)
        return;
}

int main()
{
    cin>>m>>n;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;)
            switch(getchar()){
                case '0':++j;break;
                case '*':a[i][j++] = 1;break;
            }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++)
            cout<<a[i][j]<<' ';
        putchar('\n');
    }
    return 0;
}
