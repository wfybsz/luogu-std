#include <bits/stdc++.h>
using namespace std;

const int NR = 250 * 250 * 2;
int n,m,cnt;
bool flag[NR + 10];
struct node{
	int a,b;
}ans[10010];

bool cmp(node x,node y){
	if(x.b != y.b)
		return x.b < y.b;
	return x.a < y.a;
}

int main(){
	cin>>n>>m;
	for(int i = 0;i <= m;i++)
		for(int j = 0;j <= m;j++)
			flag[i * i + j * j] = true;
	int maxm = m * m * 2;
	for(int i = 0;i <= maxm;i++)
		if(flag[i])
			for(int j = i + 1;j <= maxm;j++)
				if(flag[j]){
					int b = j - i;
					int maxi = i + b * (n - 1);
					if(maxi > maxm)
						break;
					bool Flag = true;
					for(int j = i + b;j <= maxi;j += b)
					if(!flag[j]){
						Flag = false;
						break;
					}
					if(Flag){
						cnt++;
						ans[cnt].a = i;
						ans[cnt].b = b;
					}
				}
	if(!cnt){
		cout<<"NONE";
		return 0;
	}
	sort(ans + 1,ans + 1 + cnt,cmp);
	for(int i = 1;i <= cnt;i++)
		cout<<ans[i].a<<' '<<ans[i].b<<endl;
	return 0;
}
