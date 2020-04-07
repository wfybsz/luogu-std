#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5 + 10;
int n,m,k,p,tmp;
bool removed[NR];

struct node{
	int idx;
	node *next;
};

void ins(node *p,node *a){
	a->next = p->next;
	p->next = a;
}

int main()
{
	node *head = new node;
	head->next = NULL;
	node *t = new node;
	t->idx = 1;
	ins(head,t);
	cin>>n;
	for(int i = 2;i <= n;++i){
		cin>>k>>p;
		for(node *now = head;now != NULL;now = now->next)
			if(p?now->idx == k:now->next->idx == k){
				node *t = new node;
				t->idx = i;
				ins(now,t);
				break;
			}
	}
	cin>>m;
	while(m--){
		cin>>tmp;
		if(removed[tmp])
			continue;
		removed[tmp] = true;
		for(node *now = head->next;now != NULL;now = now->next)
			if(now->next->idx == tmp){
				now->next = now->next->next;
				break;
			}
	}
	for(node *now = head->next;now != NULL;now = now->next)
		cout<<now->idx<<' ';
	putchar('\n');
	return 0;
}
