//Depth First Traversal(DFT) a graph
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> G[N];
void addedge(int u,int v){
    G[u].push_back(v);
    G[v].push_back(u);
}
int vis[N];
void dfs(int u){
    vis[u]=1;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(vis[v])continue;
        dfs(v);
    }
}
