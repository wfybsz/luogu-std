#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int NR = 32800;
int n,cnt;
struct init{
	int x,id;
}b[NR];
struct node{
	int x;
	node *next,*prev;
	node(){
		x = 0;
		next = prev = NULL;
	}
}*a[NR],*head,*tail;

bool cmp(init a,init b){
	return a.x < b.x;
}

void ins(node *t,node *p){
	t->next = p->next;
	t->next->prev = t;
	t->prev = p;
	p->next = t;
}

void del(node *t){
	t->prev->next = t->next;
	t->next->prev = t->prev;
	delete t;
}

int main()
{
	head = new node;
	tail = new node;
	head->next = tail;
	tail->prev = head;
	head->x = -2147483647;
	tail->x = 2147483647;
	cin>>n;
	for(int i = 1;i <= n;++i){
		cin>>b[i].x;
		b[i].id = i;
	}
	cnt = b[1].x;
	sort(b + 1,b + n + 1);
	for(int i = 1;i <= n;++i){
		node *t = new node;
		
	}
	return 0;
}
