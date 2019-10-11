#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int cnt;

int main()
{
    cin>>s;
    for(int i = 0;s[i] != '\0';++i)
        if(s[i] == '(')
            ++cnt;
        else
            if(s[i] == ')')
                if(cnt)
                    --cnt;
    if(cnt == 0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
