#include<cstdio>
#include<iostream>
using namespace std;
int ans,a[42],x;
int main()
{
    for (int i=1;i<=10;i++)
    {
        cin>>x;
        a[x%42]=1;
    }
    for (int i=0;i<42;i++) if(a[i])ans++;
    cout<<ans;
    return 0;
}
