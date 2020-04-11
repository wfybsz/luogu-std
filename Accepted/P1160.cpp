#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5 + 10;
int n,m,k,p;
struct node{
	int id;
	node *next,*prev;
	node(){
		id = 0;
		next = prev = NULL;
	}
}*a[NR];

void ins(int x,node *p){
	a[x] = new node;
	a[x]->id = x;
	a[x]->next = p->next;
	a[x]->next->prev = a[x];
	a[x]->prev = p;
	p->next = a[x];
}

void del(int x){
	a[x]->prev->next = a[x]->next;
	a[x]->next->prev = a[x]->prev;
	a[x]->id = 0;
}

int main()
{
	cin>>n;
	a[0] = new node;
	a[1] = new node;
	a[1]->id = 1;
	a[0]->next = a[1];
	a[1]->prev = a[0];
	a[1]->next = a[0];
	for(int i = 2;i <= n;++i){
		cin>>k>>p;
		if(p)
			ins(i,a[k]);
		else
			ins(i,a[k]->prev);
	}
	cin>>m;
	while(m--){
		cin>>k;
		if(a[k]->id == 0)
			continue;
		del(k);
	}
	for(node *p = a[0]->next;p != a[0];p = p->next)
		cout<<p->id<<' ';
	putchar('\n');
	return 0;
}
