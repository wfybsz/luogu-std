#include <bits/stdc++.h>
using namespace std;

const int NR = 1e4;
int n,q,a[NR],ans[110],mem[NR];
string tmp,_tmp;

istream &operator>>(string &s,istream &is){
	char c = getchar();
	while(c == ' ' or c == '\n' or c == '\r' or c == '\t')
		c = getchar();
	s += c;
	while(('a'))
}

int gen(string s){
	int ret = 0;
	for(int i = 0;s[i] != '\0';++i)
		ret += s[i];
	return ret;
}

int main()
{
	cin>>n>>q;
	for(int i = 0;i < n;++i){
		cin>>tmp;
		cin>>_tmp;
		a[gen(tmp)] = gen(_tmp);
	}
	for(int i = 0;i < q;++i){
		cin>>tmp;
		_tmp = "";
		while(gen(_tmp) != a[gen(tmp)]){
			cin>>_tmp;
			++ans[gen(tmp)];
		}
		printf("%c\n",ans[gen(tmp)] + 'A' - 1);
	}
	return 0;
}
