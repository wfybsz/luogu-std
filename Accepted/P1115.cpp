#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int NR = 2e5 + 10;
int n,a[NR],dp[NR],maxn;

int main()
{
    cin>>n;
    for(int i = 1;i <= n;++i){
        cin>>a[i];
        if(i == 1)
            dp[1] = maxn = a[i];
        else{
            dp[i] = max(dp[i - 1] + a[i],a[i]);
            maxn = max(maxn,dp[i]);
        }
    }
    cout<<maxn;
    return 0;
}
