#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x,y,z;

int gcd(int a,int b){return b?gcd(b,a % b):a;}

int main()
{
    cin>>x>>y>>z;
    cout<<gcd(gcd(x,y),z);
    return 0;
}
