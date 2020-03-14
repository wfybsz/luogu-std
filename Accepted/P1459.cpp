#include <bits/stdc++.h>
using namespace std;

const int NR = 1e3 + 10;
int n,a[NR],l1,l2,l3,cnt;

int main()
{
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
		switch(a[i]){
			case 1:++l1;break;
			case 2:++l2;break;
			case 3:++l3;break;
		}
	}
	l2 = l1 + l2;
	l3 = l1 + l2 + l3;
	for(int i = n;i > l2;--i){
		if(a[i] == 1){
			bool flag = true;
			for(int j = 1;j <= l1;++j)
				if(a[j] == 3){
					swap(a[j],a[i]);
					flag = false;
					++cnt;
					break;
				}
			if(flag)
				for(int j = 1;j <= l2;++j){
					if(a[j] != 1){
						swap(a[j],a[i]);
						++cnt;
						break;
					}
				}
		}
		if(a[i] == 2){
			bool flag = true;
			for(int j = l1 + 1;j <= l2;++j)
				if(a[j] == 3){
					swap(a[j],a[i]);
					++cnt;
					flag = false;
					break;
				}
			if(flag)
				for(int j = 1;j <= l1;++j)
					if(a[j] == 3){
						++cnt;
						swap(a[j],a[i]);
						break;
					}
		}
	}
	for(int i = l2;i >= l1 + 1;--i){
		if(a[i] == 1)
			for(int j = 1;j <= l1;++j)
				if(a[j] == 2){
					swap(a[j],a[i]);
					++cnt;
					break;
				}
	}
	cout<<cnt;
	return 0;
}
