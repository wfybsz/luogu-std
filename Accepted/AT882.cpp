#include <bits/stdc++.h>
using namespace std;

const int NR = 1e2 + 10;
int L,R,l[NR],r[NR],tmp,cnt,n;

int main()
{
    cin>>L>>R;
    n = max(L,R);
    for(int i = 1;i <= L;++i){
        cin>>tmp;
        ++l[tmp];
    }
    for(int i = 1;i <= R;++i){
        cin>>tmp;
        ++r[tmp];
    }
    for(int i = 1;i <= 50;++i)
        cnt += min(l[i],r[i]);
    cout<<cnt<<endl;
    return 0;
}
