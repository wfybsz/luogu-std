#include <bits/stdc++.h>
using namespace std;

const int NR = 10010;
int n,w,a[NR],mem[NR][NR / 100 + 1];

int dfs(int t,int tree,int move){
    if(t > n)
        return 0;
    if(mem[t][move] != -1)
        return mem[t][move];
    mem[t][move] = 0;
    if(a[t] == tree)
        mem[t][move] = dfs(t + 1,a[t],move) + 1;
    else{
        mem[t][move] = dfs(t + 1,tree,move);
        if(move < w)
            mem[t][move] = max(mem[t][move],dfs(t + 1,a[t],move + 1) + 1);
    }
    return mem[t][move];
}

int main()
{
    memset(mem,-1,sizeof(mem));
    cin>>n>>w;
    for(int i = 1;i <= n;i++)
        cin>>a[i];
    cout<<dfs(1,1,0);
    return 0;
}
