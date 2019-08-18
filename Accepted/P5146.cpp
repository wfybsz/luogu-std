#include <bits/stdc++.h>
using namespace std;

int n,tmp,maxn = -1,minn = 2147483647;

int main()
{
    cin>>n;
    while(n--){
        cin>>tmp;
        minn = min(minn,tmp);
        maxn = max(maxn,tmp);
    }
    cout<<maxn - minn;
    return 0;
}
