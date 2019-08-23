#include <bits/stdc++.h>
using namespace std;

int n,cnt = 1;
char tmp,last = ' ';

int main()
{
    cin>>n;
    while(n--){
        cin>>tmp;
        if(tmp < 'A' || tmp > 'Z')
            continue;
        if(last != tmp){
            cnt++;
            last = tmp;
        }
    }
    cout<<cnt;
    return 0;
}
