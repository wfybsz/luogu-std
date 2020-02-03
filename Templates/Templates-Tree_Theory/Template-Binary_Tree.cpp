#include "Tree.h"

struct node{
	int left,right;
}t[MAXN];

void pre_order(int x){//First root, second left, third right.
	cout<<x<<endl;
	if(t[x].left)
		pre_order(t[x].left);
	if(t[x].right)
		pre_order(t[x].right);
}

void in_order(int x){//First left, second root, third right.
	if(t[x].left)
		in_order(t[x].left);
	cout<<x<<endl;
	if(t[x].right)
		in_order(t[x].right);
}

void post_order(int x){//First left, second right, third root.
	if(t[x].left)
		post_order(t[x].left);
	if(t[x].right)
		post_order(t[x].right);
	cout<<x<<endl;
}
