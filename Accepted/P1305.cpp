#include <bits/stdc++.h>
using namespace std;

const int NR = 1000;
int n;
char tmp,tmp_;
struct node{
	char x;
	node *l,*r;
	node(){
		x = 0;
		l = r = NULL;
	}
}*root,*a[NR];

void dfs(node *p){
	if(p == NULL)
		return;
	putchar(p->x);
	dfs(p->l);
	dfs(p->r);
}

int main()
{
	cin>>n;
	cin>>tmp;
	a[int(tmp)] = new node;
	root = a[int(tmp)];
	a[int(tmp)]->x = tmp;
	cin>>tmp_;
	if(tmp_ != '*'){
		a[int(tmp_)] = new node;
		a[int(tmp)]->l = a[int(tmp_)];
		a[int(tmp_)]->x = tmp_;
	}
	cin>>tmp_;
	if(tmp_ != '*'){
		a[int(tmp_)] = new node;
		a[int(tmp)]->r = a[int(tmp_)];
		a[int(tmp_)]->x = tmp_;
	}
	for(int i = 1;i < n;++i){
		cin>>tmp;
		if(a[int(tmp)] == NULL)
			a[int(tmp)] = new node;
		a[int(tmp)]->x = tmp;
		cin>>tmp_;
		if(tmp_ != '*'){
			a[int(tmp_)] = new node;
			a[int(tmp)]->l = a[int(tmp_)];
			a[int(tmp_)]->x = tmp_;
		}
		cin>>tmp_;
		if(tmp_ != '*'){
			a[int(tmp_)] = new node;
			a[int(tmp)]->r = a[int(tmp_)];
			a[int(tmp_)]->x = tmp_;
		}
	}
	dfs(root);
	return 0;
}
