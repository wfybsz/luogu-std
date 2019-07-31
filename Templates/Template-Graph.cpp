//Use STL::vector to store a graph
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct Node{
    int val,lc,rc,w;
}T[N];
int n,cnt,a[N];
void ins(int o,int v){
    if(!T[o].val){T[o].val=v;T[o].w++;return;}
    if(T[o].val==v){T[o].w++;return;}
    if(v<T[o].val){
        if(!T[o].lc)T[o].lc=++cnt;
        ins(T[o].lc,v);
    }
    if(v>T[o].val){
        if(!T[o].rc)T[o].rc=++cnt;
        ins(T[o].rc,v);
    }
}
void dfs(int o){
    if(!T[o].val)return;
    if(T[o].lc)dfs(T[o].lc);
    printf("%d ",T[o].val);
    if(T[o].rc)dfs(T[o].rc);
}
int main(){//sample
    scanf("%d",&n);cnt=1;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++)ins(1,a[i]);
    dfs(1);
}