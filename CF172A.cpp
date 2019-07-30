#include<bits/stdc++.h>
using namespace std;

string now,last,tmp;
int n;

int main()
{
    cin>>n;
    cin>>last;
    while(--n){
        cin>>now;
        tmp = "";
        int len = min(now.length(),last.length());
        for(int i = 0;i < len;i++){
            if(last[i] == now[i])
                tmp += last[i];
            else
                break;
        }
        last = tmp;
    }
    cout<<last.length();
    return 0;
}
