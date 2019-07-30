#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

struct Stu
{
	char name[25];
	int y,m,d,num;
};

bool cmp(Stu x,Stu y){
	if(x.y != y.y)
		return x.y > y.y;
	if(x.m != y.m)
		return x.m > y.m;
	if(x.d != y.d)
		return x.d > y.d;
	return x.num < y.num;
}

int main()
{
	cin>>n;
	Stu student[n];
	for(int i = 0;i < n;i++){
		scanf("%s",student[i].name);
		cin>>student[i].y>>student[i].m>>student[i].d;
		student[i].num = i;
	}
	sort(student,student + n,cmp);
	for(int i = n - 1;i > -1;i--)
		cout<<student[i].name<<endl;
	return 0;
}
