#include <bits/stdc++.h>
using namespace std;

bool p[] = {false};

void prime(int n){
	for(int i = 2;i <= sqrt(n);i++)
		if(!p[i])
			for(int j = i + i;j <= n;j += i)
				p[j] = 1;
}
