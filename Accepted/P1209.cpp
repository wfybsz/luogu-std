#include <bits/stdc++.h>
using namespace std;

const int NR = 2e2;
int m,s,c,num[NR + 5],gap[NR + 5],minn;

bool cmp(int x,int y){
    return x > y;
}

int main()
{
    cin>>m>>s>>c;
    for(int i = 1;i <= c;i++)
        cin>>num[i];
    if(m > c){
        cout<<c;
        return 0;
    }
    sort(num + 1,num + c + 1);
    minn = num[c] - num[1] + 1;
    for(int i = 2;i <= c;i++)
        gap[i - 1] = num[i] - num[i - 1];
    sort(gap + 1,gap + c,cmp);
    for(int i = 1;i < m;i++)
        minn -= gap[i] - 1;
    cout<<minn;
    return 0;
}
