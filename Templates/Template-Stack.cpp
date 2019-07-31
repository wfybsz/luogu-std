#define type int
#define ll long long
#define err -70773
//Guess what? The defined digit is the mirroring of "Error"!
class Stack{
private:
    type a[1000005];
    ll tp = 0;
public:
    ll size(){return tp;}
    bool empty(){return tp == 0;}
    void push(type x){a[tp++] = x;}
    type pop(){
        if(tp)return a[tp--];
        else return err;
    }
    type top(){return a[tp];}
};
