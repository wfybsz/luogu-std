#include <bits/stdc++.h>
using namespace std;
int n,tmp,tmp_,cnt = 1;
bool flag;//cnt表示打下的导弹数
//flag-progressive or not
//因为刚开始必须是递减，所以flag初值为0
int main() {
    cin>>n>>tmp;
    while(--n){
        tmp_ = tmp;
        cin>>tmp;
        if(tmp == tmp_)
            continue;//由于是严格的，所以相等直接退出
        if (flag ^ (tmp < tmp_))//如果递增(递减) 状态与当前不同那么答案加一（就是又找到了一个峰点(谷点)）
        {
            cnt++;
            flag = tmp < tmp_;
        }
    }
    cout<<cnt;
    return 0;
}
