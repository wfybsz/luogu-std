#include <bits/stdc++.h>
using namespace std;

const int NR = 5e3 + 10;
struct ii{
	int a[NR],len;
	ii(){
		memset(a,0,sizeof(a));
		len = 1;
	}
	void read(){
		char s[NR];
		scanf("%s",s);
		len = strlen(s);
		for(int i = 1;i <= len;i++)
			a[i] = s[len - i] - '0';
	}
	void print(){
		for(int i = len;i >= 1;i--)
			putchar(a[i] + '0');
		puts("");
	}
	ii operator+(const ii b)const{
		ii ans;
		ans.len = max(len,b.len);
		for(int i = 1;i <= ans.len;i++){
			ans.a[i] += a[i] + b.a[i];
			ans.a[i + 1] = ans.a[i] / 10;
			ans.a[i] %= 10;
		}
		if(ans.a[ans.len + 1] > 0)
			ans.a[0]++;
		return ans;
	}
	ii operator*(const ii b)const{
		ii ans;
		for(int i = 1;i <= len;i++)
			for(int j = 1;j <= b.len;j++)
				ans.a[i + j - 1] += a[i] * b.a[j];
		ans.len = len + b.len + 1;
		for(int i = 1;i < ans.len;i++){
			ans.a[i + 1] += ans.a[i] / 10;
			ans.a[i] %= 10;
		}
		while(ans.a[ans.len] == 0 && ans.len > 1)
			ans.len--;
		return ans;
	}
	ii operator/(const int b)const{
		ii ans = *this;
		ans.a[ans.len + 1] = 0;
		for(int i = ans.len;i >= 1;i--)
			ans.a[i] += ans.a[i + 1] % b * 10;
		for(int i = ans.len;i >= 1;i--)
			ans.a[i] /= b;
		while(ans.a[ans.len] == 0 && ans.len > 1)
			ans.len--;
		return ans;
	}
	bool operator<(const ii b)const{
		if(len != b.len)
			return len < b.len;
		for(int i = len;i >= 1;i--)
			if(a[i] != b.a[i])
				return a[i] < b.a[i];
		return false;
	}
}a,b;

int main()
{
	a.read();
	b.read();
	(a * b).print();
	return 0;
}
