#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5;
long long n,i,cnt,none;
int ans[NR] = {1,1},tmp[NR] = {1,1};

void print(int a[]){
    for(int i = a[0];i >= 1;i--)
        putchar(a[i] + '0');
    puts("");
}

void Times(int a[],int b,int ans[]){
    ans[0] = a[0]+1;
    for(int i = 1;i <= ans[0];i++)
        ans[i] = a[i] * b;
    for(int i = 1;i < ans[0];i++){
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    while(ans[ans[0]] >= 10){
        ans[ans[0] + 1] = ans[ans[0]] / 10;
        ans[ans[0]] %= 10;
        ans[0]++;
    }
    while(ans[ans[0]] == 0 && ans[0] > 1)
        ans[0]--;
}

int main()
{
    cin>>n;
    for(;cnt <= n;i++)
        cnt += i;
    none = cnt - n - 1;
    for(long long j = 2;j < i;j++){
        if(j == none)
            continue;
        cout<<j<<' ';
        Times(ans,j,tmp);
        memcpy(ans,tmp,sizeof(ans));
    }
    puts("");
    print(ans);
    return 0;
}
