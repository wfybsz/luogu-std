#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
 int n,m,zh = 0,ch;
 cin>>n>>m;
 ch=((m + 1) * (n + 1) * m * n) / 4;
 for(;m >= 1 && n >= 1;m--,n--)
  zh += m * n;                       
 cout<<zh<<" "<<ch - zh;
return 0;
}
