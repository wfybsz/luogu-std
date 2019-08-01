#include <bits/stdc++.h>
using namespace std;

const int NR = 5e5;
int n,last;
struct node{
    int x,y;
}a[NR];

bool cmp(node x,node y){
    if(x.y == y.y)
        return x.x > y.x;
    return x.y > y.y;
}

int main()
{
    cin>>n;
    for(int i = 0;i < n;i++)
        cin>>a[i].x>>a[i].y;
    sort(a,a + n,cmp);
    printf("(%d,%d)",a[0].x,a[0].y);
    last = a[0].x;
    for(int i = 1;i < n;i++){
        if(a[i].x > last){
            last = a[i].x;
            printf(",(%d,%d)",a[i].x,a[i].y);
        }
    }
    return 0;
}
