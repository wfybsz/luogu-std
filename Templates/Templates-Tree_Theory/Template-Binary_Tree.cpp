#include "Tree.h"

struct node{
	bool have_value;
	int v;
	node *l,*r;
	node():have_value(false),l(NULL),r(NULL){}
}*root;
