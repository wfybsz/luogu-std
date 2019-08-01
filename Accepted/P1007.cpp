#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n,l,x,max_ = 0,min_ = 0;
    cin >> l >> n;
    for(int i = 1;i <= n;i++)
    {
        cin>>x;
        max_ = max(max_ , max(l - x + 1 , x));
        min_ = max(min_ , min(l - x + 1 , x));
    }
    cout << min_ << " " << max_;
    return 0;
}
