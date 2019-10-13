#include <bits/stdc++.h>
using namespace std;

const int NR = 1e8 + 1;
int n,cnt;
bool notprime[NR];

void genprime(){
	for(int i = 2;i <= NR;++i){
		if(notprime[i])
			continue;
		for(int j = i + i;j <= NR;j += i)
			notprime[j] = true;
	}
}

int main()
{
	freopen("C:\\Users\\Administrator\\Documents\\out","w",stdout);
	genprime();
	for(int i = 0;i <= NR;++i)
		printf("%d,",notprime[i]);
	return 0;
}
