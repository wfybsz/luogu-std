#include <bits/stdc++.h>
using namespace std;

const int NR = 1e3;
int n,a[NR],minn = 2147483647,cnt;

int main()
{
    cin>>n;
    for(int i = 0;i < n;i++)
        cin>>a[i];
    for(int i = 0;i <= 84;i++){
        for(int j = 0;j < n;j++){
            if(a[j] < i)
                cnt += (i - a[j]) * (i - a[j]);
            if(a[j] > i + 17)
                cnt += (a[j] - i - 17) * (a[j] - i - 17);
        }
        minn = min(cnt,minn);
        cnt = 0;
    }
    cout<<minn;
    return 0;
}
