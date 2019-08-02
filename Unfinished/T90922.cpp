#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll lm = 2,ms,ss,nlm,nms,nss,mod = 19260817;
ll n;

int main()
{
    scanf("%lld",&n);
    if(!n){
        printf("0");
        return 0;
    }
    for(int i = 0;i < n;i++){
        nlm = lm;
        nms = lm + ms;
        nss = ms + ss + ss;
        lm = nlm;
        ms = nms;
        ss = nss;
    }
    printf("%lld",ss % mod);
    return 0;
}
