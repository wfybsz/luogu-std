#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5 + 10;
long long n,cnt,t;
struct node{
    int t,d;
}a[NR];

bool cmp(node a,node b){
    return a.t * b.d < b.t * a.d;
}

int main()
{
    cin>>n;
    for(int i = 1;i <= n;++i)
        cin>>a[i].t>>a[i].d;
    sort(a + 1,a + n + 1,cmp);
    for(int i = 1;i <= n;++i){
        cnt += t * a[i].d;
        t += 2 * a[i].t;
    }
    cout<<cnt;
    return 0;
}
