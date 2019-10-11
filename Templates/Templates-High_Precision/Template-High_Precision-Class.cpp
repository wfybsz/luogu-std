#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;

class ii{
private:
	int len,a[maxn];
	void fl(const int l){
		len = l;
		for(int i = 1;i <= len;++i){
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
		while(!a[len])
			--len;
	}
public:
	ii(int x = 0){
		memset(a,0,sizeof(a));
		for(len = 1;x;++len){
			a[len] = x % 10;
			x /= 10;
		}
		--len;
	}
	void read(){
		ii();
		string s;
		cin>>s;
		len = s.length();
		for(int i = 0;s[i] != '\0';++i)
			a[len - i] = s[i] - '0';
	}
	void print(){
		for(int i = max(len,1);i >= 1;--i)
			putchar(a[i] + '0');
	}
	int& operator[](const int i){
		return a[i];
	}
	ii operator+(const ii b)const{
		ii ret;
		int ln = max(len,b.len);
		for(int i = 1;i <= ln;++i)
			ret[i] += (*this).a[i] + b.a[i];
		ret.fl(ln + 1);
		return ret;
	}
	ii operator*(const int b)const{
		ii ret;
		int ln = len;
		for(int i = 1;i <= ln;++i)
			ret[i] = a[i] * b;
		ret.fl(ln + 12);
		return ret;
	}
};

istream& operator>>(ii& x,istream& is){
	x.read();
	return is;
}

ostream& operator<<(ii& x,ostream& os){
	x.print();
	return os;
}

int main(){
	ii qwq,QAQ,OvO;
	qwq.read();
	QAQ.read();
	OvO = qwq + QAQ;
	OvO.print();
	return 0;
}
