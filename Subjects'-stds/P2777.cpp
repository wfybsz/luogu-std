#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i < n;i++)
        cin>>a[i];
    sort(a,a + n);
    int cnt = 0;
    for(int i = 0;i < n;i++)
        if(a[i] + n > a[n - 1])
            cnt++;
    cout<<cnt<<endl;
    return 0;
}
