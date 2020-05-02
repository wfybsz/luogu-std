#include <bits/stdc++.h>
#define _for(i, a, b) for(int i = (a); i <= (b); i++)
using namespace std;
 
const int MAXN = 112;
const int base = 10000;
struct ii
{
	int len, s[505];
	ii() { len = 0; memset(s, 0, sizeof(s)); }
};
 
bool judge(ii a, ii b)
{
	if(a.len != b.len) return a.len > b.len;
	for(int i = a.len; i >= 1; i--)
		if(a.s[i] != b.s[i]) return a.s[i] > b.s[i];
	return true;
}

ii operator+ (const ii& a, const ii& b) 
{                                              
	ii c;
	int& len = c.len = max(a.len, b.len);
	
	_for(i, 1, len)
	{
		c.s[i] += a.s[i] + b.s[i]; //这里一定是+=，不是= 
		c.s[i+1] += c.s[i] / base;
		c.s[i] %= base;
	} 
	
	if(c.s[len+1]) len++;
	return c;
}
 
//高精度减法 
ii operator- (ii a, const ii& b)
{
	for(int i = a.len; i >= 1; i--)
	{
		a.s[i] -= b.s[i];
		if(a.s[i] < 0) a.s[i+1]--, a.s[i] += base;
	}
	while(!a.s[a.len] && a.len > 0) a.len--;
	return a;
}
 
//高精度*高精度 
ii operator* (const ii& a, const ii& b)
{
	ii c;
	int& len = c.len = b.len + a.len - 1;
	
	_for(i, 1, a.len)
		_for(j, 1, b.len)
		{
			c.s[i+j-1] += a.s[i] * b.s[j];
			c.s[i+j] += c.s[i+j-1] / base;
			c.s[i+j-1] %= base;
		}
	
	if(c.s[len+1]) len++;
	return c;
}
 
//低精度*高精度 
ii operator* (const int& a, const ii& b) //系统会根据数据类型来判断是低精度乘高精度还是高精度乘高精度 
{
	ii c;
	int& len = c.len = b.len;
	
	_for(i, 1, b.len)
	{
		c.s[i] += b.s[i] * a;
		c.s[i+1] += c.s[i] / base;
		c.s[i] %= base;
	}
	
	while(c.s[len+1] > 0) 
	{
		c.len++;
		c.s[len+1] += c.s[len] / base;
		c.s[len] %= base;
	}
	
	return c;
}
 
//读入
char str[10000 + 5];
void read(ii&a){
	scanf("%s", str);
	reverse(str, str + strlen(str)); //先翻转再说 
	int& len = a.len = 0;
	for(int i = 0, w; i < strlen(str); i++, w *= 10)
	{
		if(i % 4 == 0) len++, w = 1;
		a.s[len] += w * (str[i] - '0');
	}
}
 
//输出
void print(ii a,char c = '\n'){
	printf("%d", a.s[a.len]);
	for(int i = a.len - 1; i >= 1; i--)
		printf("%04d", a.s[i]);
	putchar(c);
}

int main()
{
	ii a,b;
	read(a);read(b);
	print(a + b);
	print(a - b);
	print(a * b);
	return 0;
}
