#include <bits/stdc++.h>
using namespace std;

const int NR = 31e3;
int n,w,p[NR],l = 1,r,ans;

int main()
{
    cin>>w>>n;
    for(int i = 1;i <= n;i++)
    	cin>>p[i];
    sort(p + 1, p + 1 + n);
    r = n;
    while(l <= r){
    	ans++;
        l += (p[l] + p[r] <= w);
    	r--;
    }
    cout<<ans;
    return 0;
}
