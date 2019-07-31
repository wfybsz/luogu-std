#include <bits/stdc++.h>
using namespace std;

const int NR = 1e4;
int n,m,a[NR + 5],b[NR + 5],t,tmp;

int main()
{
    cin>>n>>m;
    tmp = m;
    for(int i = 1;i <= n;i++)
        cin>>a[i];
    for(int i = 1;i <= m;i++)
        b[i] = a[i];
    while(tmp < n){
        sort(b + 1,b + 1 + m);
        t += b[1];
        for(int i = 2;i <= m;i++){
            b[i] -= b[1];
            if(b[i] == 0)
                b[i] = a[++tmp];
        }
        b[1] = a[++tmp];
    }
    sort(b + 1,b + 1 + m);
    cout<<t + b[m];
    return 0;
}
