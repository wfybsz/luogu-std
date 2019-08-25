#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll NR = 1e6;
ll n,m,p,a[NR],cnt;
bool flag[NR];

void dfs(ll last,ll tot){
    if(last > n){
        if(tot == m)
            cnt++;
        return;
    }
    if(tot == m){
        cnt++;
        return;
    }
    for(ll i = last;i <= n;i++)
        for(ll j = 1;j <= m;j++){
            if(flag[j])
                continue;
            flag[j] = true;
            a[i] = j;
            dfs(i + 2,tot + 1);
            flag[j] = false;
        }
}

int main()
{
    cin>>n;
    cin>>n>>m>>p;
    dfs(1,0);
    cout<<cnt % p;
    return 0;
}
