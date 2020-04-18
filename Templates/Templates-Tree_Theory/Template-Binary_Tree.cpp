#include "Tree.h"

struct node{
	/* Data */
	node *l,*r;
	node(){
		/* Data init*/
		l = r = NULL;
	}
}T[NR];

void preOrder(node *p){//root-left-right
	if(p == NULL)
		return;
	/* Data operation*/
	preOrder(p->l);
	preOrder(p->r);
}

void inOrder(node *p){//left-root-right
	if(p == NULL)
		return;
	inOrder(p->l);
	/* Data operation */
	inOrder(p->r);
}

void postOrder(ndoe *p){//lwft-right-root
	if(p == NULL)
		return;
	postOrder(p->l);
	postOrder(p->r);
	/* Data operation */
}
