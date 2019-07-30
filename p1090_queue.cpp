#include <bits/stdc++.h>
using namespace std;

const int NR = 1e4 + 1e3;
int n,q1[NR],q2[NR],l1 = 1,r1,l2 = 1,r2;

int getmin(){
    int ans1 = 2e9,ans2 = 2e9;
    if(l1 <= r1)
        ans1 = q1[l1];
    if(l2 <= r2)
        ans2 = q2[l2];
    if(ans1 < ans2){
        l1++;
        return ans1;
    }
    else{
        l2++;
        return ans2;
    }
}

int main()
{
    cin>>n;
    for(int i = 1;i <= n;i++)
        cin>>q1[i];
    sort(q1 + 1,q1 + 1 + n);
    r1 = n;
    int ans = 0;
    for(int i = 1;i <= n - 1;i++) {
        int x = getmin();
        int y = getmin();
        ans += x + y;
        q2[++r2] = x + y;
    }
    cout<<ans<<endl;
    return 0;
}
