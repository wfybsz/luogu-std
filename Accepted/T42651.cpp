#include <bits/stdc++.h>
using namespace std;

struct qwq{
	int score,num;
}QAQ[1010];
int n;

bool OvO(qwq a,qwq b){
	if(a.score != b.score)
		return a.score > b.score;
	return a.num < b.num;
}

int main()
{
	cin>>n;
	for(int i = 1,math,chinese,chtholly;i <= n;++i){
		cin>>math>>chinese>>chtholly>>QAQ[i].num;
		QAQ[i].score = math + chinese + chtholly;
	}
	sort(QAQ + 1,QAQ + n + 1,OvO);
	for(int i = 1;i <= n;++i)
		cout<<QAQ[i].num<<endl;
	return 0;
}
