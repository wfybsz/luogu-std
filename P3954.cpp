#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int d;
    d = a / 5 + b / 10 * 3 + c / 2;
    if(d > 100)
        d = 100;
    cout<<d;
    return 0;
}
