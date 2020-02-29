#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int NR = 30;
const int MR = 1e4 + 10;
ll v,n,a[NR],dp[MR];

int main()
{
    dp[0] = 1;
    cin>>v>>n;
    for(int i = 1;i <= v;++i)
        cin>>a[i];
    for(int i = 1;i <= v;++i)
        for(int j = a[i];j <= n;++j)
            dp[j] += dp[j - a[i]];
    cout<<dp[n];
    return 0;
}
