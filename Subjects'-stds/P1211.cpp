#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n,tmp,ln2,ln3,ln4,cnt = 0;
bool flag[10];

bool inc(int q){
	do
		if(!flag[q % 10])
			return false;
	while(q /= 10);
	return true;
}

bool in_zone(int q){
	return 110 < q && q < 1000;
}

int main()
{
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>tmp;
		flag[tmp] = true;
	}
	for(int i = 111;i <= 999;i++)
		for(int j = 11;j <= 99;j++){
			ln2 = i * (j % 10);
			ln3 = i * (j / 10);
			ln4 = ln2 + ln3 * 10;
			if(in_zone(ln2) && in_zone(ln3) && (1110 < ln4 && ln4 < 10000))
				if(inc(i) && inc(j) && inc(ln2) && inc(ln3) && inc(ln4))
					cnt++;
		}
	cout<<cnt;
	return 0;
}
