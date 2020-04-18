#include <bits/stdc++.h>
using namespace std;

const int NR = 2e6 + 10;
int n,m,a[NR];

int main()
{
    cin>>n>>m;
    for(int i = 1;i <= n;++i)
        cin>>a[i];
    while(m--){
        cin>>n;
        cout<<a[n]<<endl;
    }
    return 0;
}
