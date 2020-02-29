#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5 + 10;
int n,d,x,a[NR],pos = -1,len,brk;
string s;

int main()
{
    cin>>n>>d;
    x = n / d;
    do{
        s = char(x % 10 + '0') + s;
        x /= 10;
    }while(x);
    s += '.';
    n %= d;
    do{
        if(a[n]){
            pos = a[n];
            break;
        }else
            a[n] = s.length();
        n *= 10;
        x = n / d;
        s += char(x + '0');
        n %= d;
    }while(n);
    if(pos != -1)
        s += ')';
    len = s.length();
    for(int i = 0;i < len;++i){
        if(i == pos){
            putchar('(');
            --i;
            pos = -1;
        }else
            putchar(s[i]);
        ++brk;
        if(brk % 76 == 0)
            cout<<endl;
    }
    return 0;
}
