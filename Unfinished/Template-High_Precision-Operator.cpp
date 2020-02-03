#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

struct ii{
	int a[MAXN];
	int len;
	ii(){
		a[0] = 0;
		len = 1;
	}
	void operator=(int b){
		while(b){
			(*this).a[len++] = b % 10;
			b /= 10;
		}
	}
	void flat(){
		len = 0;
		while(a[len]){
			a[len + 1] += a[len] / 10;
			a[len] %= 10;
			++len;
		}
	}
	const ii operator+(const int b)const{
		ii ret;
		ret = *this;
		ret.a[0] += b;
		ret.flat();
		return ret;
	}
};

ostream &operator<<(ostream &o,ii &a){
	for(int i = a.len - 1;i;--i)
		putchar(a.a[i] + '0');
	return o;
}

int main()
{
	ii x;
	x = 999;
	x = x + 999;
	cout<<x<<endl;
	return 0;
}
