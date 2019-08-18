#include <bits/stdc++.h>
using namespace std;

int n,tmp,ans,minn = 2147483647;

int main()
{
    cin>>n;
    while(n--){
        cin>>tmp;
        minn = min(minn,tmp);
        ans = max(tmp - minn,ans);
    }
    cout<<ans;
    return 0;
}
