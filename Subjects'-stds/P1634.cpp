#include<cstdio>
#include<iostream>
#define ll long long
using namespace std;

int main()
{
    ll x,n;
    ll y = 1;
    cin>>x>>n;
    for(ll i = 0;i < n;i++)
    {
        y += y * x;
    }
    cout<<y<<endl;
    return 0;
}
