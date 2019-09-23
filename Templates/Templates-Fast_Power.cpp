long long fp(int x,int y){
    int ret = 1;
    while(y){
        if(y & 1)
            ret *= x;
        x *= x;
        y >>= 1;
    }
    return ret;
}
