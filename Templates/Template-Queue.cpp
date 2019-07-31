#define type int
#define ll long long
#define err -70773
class Queue{
private:
    type a[1000005];
    ll l = 0,r = 0;
public:
    type front(){
        if(empty())return err;
        else return a[l];
    }
    type back(){
        if(empty())return err;
        else return a[r];
    }
    ll size(){return l - r;}
    bool empty(){return l == r;}
    void push(type x){a[++r] = x;}
    type pop(){
        if(empty())return err;
        else return a[l++];
    }
};