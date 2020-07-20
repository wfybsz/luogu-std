#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define __BIGINT_MAXIMUM_LENGTH__ 10000
#define __BIGINT_BASE__ 100000000

struct ii {
	static char s[__BIGINT_MAXIMUM_LENGTH__*10];
	typedef int _T;
	_T a[__BIGINT_MAXIMUM_LENGTH__];
	int len;
	void clear() {
		len = 1;
		a[len] = 0;
	}
	ii() {
		clear();
	}
	ii(_T x) {
		*this = x;
	}
	ii(char s[]) {
		this->str(s);
	}
	ii operator=(const ii &b) {
		len = b.len;
		for (int i = 1; i <= len; ++i)
			a[i] = b.a[i];
		return *this;
	}
	ii operator+(const ii &b) {
		int L = len > b.len ? len : b.len;
		ii tmp;
		for (int i = 1; i <= L + 1; ++i)
			tmp.a[i] = 0;
		for (int i = 1; i <= L; ++i) {
			if (i > len)
				tmp.a[i] += b.a[i];
			else
				if (i > b.len)
					tmp.a[i] += a[i];
				else {
					tmp.a[i] += a[i] + b.a[i];
					if (tmp.a[i] >= __BIGINT_BASE__) {
						tmp.a[i] -= __BIGINT_BASE__;
						++tmp.a[i + 1];
					}
				}
		}
		if (tmp.a[L + 1])
			tmp.len = L + 1;
		else
			tmp.len = L;
		return tmp;
	}
	ii operator-(ii b) {
		int L = len > b.len ? len : b.len;
		ii tmp;
		for (int i = 1; i <= L + 1; ++i)
			tmp.a[i] = 0;
		for (int i = 1;i <= L; ++i) {
			if (i > b.len)
				b.a[i] = 0;
			tmp.a[i] += a[i] - b.a[i];
			if (tmp.a[i] < 0) {
				tmp.a[i] += __BIGINT_BASE__;
				--tmp.a[i + 1];
			}
		}
		while (L > 1 and !tmp.a[L])
			--L;
		tmp.len = L;
		return tmp;
	}
	ii operator*(const ii &b) const {
		int L = len + b.len;
		ii tmp;
		for (int i = 1; i <= L; ++i)
			tmp.a[i] = 0;
		for (int i = 1; i <= len; ++i)
			for (int j = 1; j <= b.len; ++j) {
				tmp.a[i + j - 1] += a[i] * b.a[j];
				if (tmp.a[i + j - 1] >= __BIGINT_BASE__) {
					tmp.a[i + j] += tmp.a[i + j - 1] / __BIGINT_BASE__;
					tmp.a[i + j - 1] %= __BIGINT_BASE__;
				}
			}
		tmp.len = len + b.len;
		while (tmp.len > 1 and !tmp.a[tmp.len])
			--tmp.len;
		return tmp;
	}
	pair<ii, ii> divide(const ii &a,const ii &b) {
		int L = a.len;
		ii c, d;
		for (int i = L; i; --i) {
			c.a[i] = 0;
			d = d * __BIGINT_BASE__;
			d.a[1] = a.a[i];
			int l = 0, r = __BIGINT_BASE__ - 1, mid;
			while (l < r) {
				mid = (l + r + 1) >> 1;
				if (b * mid <= d)
					l = mid;
				else
					r = mid - 1;
			}
			c.a[i] = l;
			d -= b * l;
		}
		while (L>  1 and !c.a[L])
			--L;
		c.len = L;
		return make_pair(c, d);
	}
	ii operator/(_T x) {
		_T d = 0;
		ii tmp;
		for (int i = len; i; --i) {
			d = d * __BIGINT_BASE__ + a[i];
			tmp.a[i] = d / x;
			d %= x;
		}
		tmp.len = len;
		while (tmp.len > 1 and !tmp.a[tmp.len])
			--tmp.len;
		return tmp;
	}
	_T operator%(_T x){
		_T d = 0;
		for (int i = len; i; --i)
			d = (d * __BIGINT_BASE__ + a[i]) % x;
		return d;
	}
	ii operator/(const ii &b) {
		return divide(*this, b).first;
	}
	ii operator%(const ii &b) {
		return divide(*this, b).second;
	}
	ii &operator+=(const ii &b) {
		*this = *this + b;
		return *this;
	}
	ii &operator-=(const ii &b) {
		*this = *this - b;
		return *this;
	}
	ii &operator*=(const ii &b) {
		*this = *this * b;
		return *this;
	}
	ii operator/=(const ii &b) {
		*this = *this / b;
		return *this;
	}
	ii operator%=(const ii &b) {
		*this = *this % b;
		return *this;
	}
	ii &operator++() {
		ii T;
		T = 1;
		*this = *this + T;
		return *this;
	}
	ii &operator--(){
		ii T;
		T = 1;
		*this = *this - T;
		return *this;
	}
	ii operator++(int) {
		ii T, tmp = *this;
		T = 1;
		*this = *this + T;
		return tmp;
	}
	ii operator--(int) {
		ii T, tmp = *this;
		T = 1;
		*this = *this - T;
		return tmp;
	}
	ii operator+(_T x) {
		ii T;
		T = x;
		return *this + T;
	}
	ii operator-(_T x) {
		ii T;
		T = x;
		return *this - T;
	}
	ii operator*(_T x) {
		ii T;
		T = x;
		return *this * T;
	}
	ii operator*=(_T x) {
		*this = *this * x;
		return *this;
	}
	ii operator+=(_T x) {
		*this = *this + x;
		return *this;
	}
	ii operator-=(_T x) {
		*this = *this - x;
		return *this;
	}
	ii operator/=(_T x) {
		*this = *this / x;
		return *this;
	}
	ii operator%=(_T x) {
		*this = *this % x;
		return *this;
	}
	bool operator==(_T x) {
		ii T;
		T = x;
		return *this == T;
	}
	bool operator!=(_T x) {
		ii T;
		T =x;
		return *this != T;
	}
	bool operator<=(_T x) {
		ii T;
		T = x;
		return *this <= T;
	}
	bool operator>=(_T x) {
		ii T;
		T = x;
		return *this >= T;
	}
	bool operator<(_T x) {
		ii T;
		T = x;
		return *this < T;
	}
	bool operator>(_T x) {
		ii T;
		T = x;
		return *this > T;
	}
	ii operator=(_T x) {
		len = 0;
		while (x)
			a[++len] = x % __BIGINT_BASE__, x /= __BIGINT_BASE__;
		if (!len)
			a[++len] = 0;
		return *this;
	}
	bool operator<(const ii &b) {
		if (len < b.len)
			return 1;
		if (len > b.len)
			return 0;
		for (int i = len; i; --i) {
			if (a[i] < b.a[i])
				return 1;
			if (a[i] > b.a[i])
				return 0;
		}
		return 0;
	}
	bool operator==(const ii &b) {
		if (len != b.len)
			return 0;
		for (int i = len; i; --i)
			if (a[i] != b.a[i])
				return 0;
		return 1;
	}
	bool operator!=(const ii &b) {
		return !(*this == b);
	}
	bool operator>(const ii &b) {
		return !(*this < b || *this == b);
	}
	bool operator<=(const ii &b) {
		return (*this < b) || (*this == b);
	}
	bool operator>=(const ii &b) {
		return (*this > b) || (*this == b);
	}
	void str(char s[]) {
		int l = strlen(s);
		_T x = 0, y = 1;
		len = 0;
		for (int i = l - 1; i >= 0; --i) {
			x = x + (s[i] - '0') * y;
			y *= 10;
			if (y == __BIGINT_BASE__)
				a[++len] = x, x = 0, y = 1;
		}
		if (!len || x)
			a[++len] = x;
	}
	void read(){
		scanf("%s", s);
		this->str(s);
	}
	void print(){
		printf("%d", (int)a[len]);
		for (int i = len - 1; i; --i) {
			for (int j = __BIGINT_BASE__ / 10; j >= 10; j /= 10) {
				if (a[i] < j)
					putchar('0');
				else
					break;
			}
			printf("%d", (int)a[i]);
		}
	}
};
 
ii gcd(ii a, ii b) {
	ii c;
	c.clear();
	c = 1;
	while ((a % 2 == 0) and (b % 2 == 0)) {
		a /= 2;
		b /= 2;
		c *= 2;
	}
	while (a % 2 == 0)
		a /= 2;
	while (b % 2 == 0)
		b/=2;
	while (a != b) {
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	c *= a;
	return c;
}

istream &operator>>(istream &is, ii &x) {
	x.read();
	return is;
}

ostream &operator<<(ostream &os, ii &x) {
	x.print();
	return os;
}
