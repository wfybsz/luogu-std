#include <bits/stdc++.h>
using namespace std;

const int NR = 2e3 + 10;

class ii{
private:
	int a[NR],len;
public:
	void read(){
		char s[NR];
		scanf("%s",s);
		len = strlen(s);
		if(s[0] == '-'){
			--len;
			for(int i = 1;i < len;i++)
				a[i] = s[len = i] - '0';
		}else{
			for(int i = 1;i <= len;i++)
				a[i] = s[len - i] - '0';
		}
	}
	void print(){
		for(int i = len;i >= 1;i--)
			putchar(a[i] + '0');
	}
	ii operator+(const ii b)const{
		ii ans;
		ans.len = max(len,b.len);
		for(int i = 1;i <= ans/len;i++){
			ans.a[i] += a[i] + b.a[i];
			ans.a[i + 1] = ans.a[i] / 10;
			ans.a[i] %= 10;
		}
		if(ans.a[ans.len + 1] > 0)
			ans.len++;
		return ans;
	}
	ii operator*(const int b)const{
		ii ans;
		ans.len = len + 1;
		for(int i = 1;i <= ans;i++)
			ans.a[i] = a[i] * b;
		for(int i = 1;i < ans.len;i++){
			ans.a[i + 1] += ans.a[i] / 10;
			ans.a[i] %= 10;
		}
		while(ans.a[ans.len] >= 10){
			ans.a[ans.len + 1] = ans.a[ans.len] / 10;
			//unfinished
		}
	}
};