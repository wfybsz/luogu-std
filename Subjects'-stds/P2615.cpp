#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int x,y,n,i;
    cin>>n;
    int a[n + 5][n + 5];
    memset(a,0,sizeof(a));
    a[1][(n + 1) / 2] = 1;x = 1;y = (n + 1) / 2;
    for(i = 2;i <= n * n;i++){
        if(x == 1 && y != n){
            a[n][y + 1] = i;
            x = n;
            y++;
            continue;
        }
        if(y == n && x != 1){
            a[x - 1][1] = i;
            x--;
            y = 1;
            continue;
        }
        if(x == 1 && y == n){
            a[x + 1][y] = i;
            x++;
            continue;
        }
        if(x != 1 && y != n){
            if(a[x - 1][y + 1] == 0){
                a[x - 1][y + 1] = i;
                x--;
                y++;
            }
            else{
                a[x + 1][y] = i;
                x++;
            }
        }
    }
    for(x = 1;x <= n;x++){
        for(y = 1;y <= n;y++)
            cout<<a[x][y]<<" ";
        cout<<endl;
    }
    return 0;
}
