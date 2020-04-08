#include <bits/stdc++.h>
using namespace std;

const int NR = 10000;
char s[NR];

struct node{
	char x;
	node *next;
};

int main()
{
	while(scanf("%s",s)){
		node *head = new node,*tail,*now;
		head->next = NULL;
		now = tail = head;
		int len = strlen(s);
		for(int i = 0;i < len;++i){
			switch(s[i]){
				case '[':now = head;break;
				case ']':now = tail;break;
				default:{
					node *t = new node;
					t->x = s[i];
					t->next = now->next;
					now->next = t;
					if(now == tail)
						tail = t;
					now = t;
				}break;
			}
		}
		for(node *p = head->next;p != NULL;p = p->next)
			putchar(p->x);
		putchar('\n');
	}
	return 0;
}
