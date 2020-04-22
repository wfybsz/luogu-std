#include <bits/stdc++.h>
#define __CUSTOM_STACK_RETURN_TYPE__ long long
#define __CUSTOM_STACK_ERROR__ -70773
#define __CUSTOM_STACK_MAXIMUM_SIZE__ 1000005
//Guess what? The defined digit is the mirroring of "Error"!
/*template<typename _T>
class Stack{
private:
	_T a[__CUSTOM_STACK_MAXIMUM_SIZE__];
	__CUSTOM_STACK_RETURN_TYPE__ tp = 0;
public:
	__CUSTOM_STACK_RETURN_TYPE__ size(){return tp;}
	bool empty(){return tp == 0;}
	void push(_T x){a[tp++] = x;}
	_T pop(){if(tp)return a[tp--];else return __CUSTOM_STACK_ERROR__;}
	_T top(){return a[tp];}
};*/

template<typename _T>
struct Stack{
	struct node{
		_T a;
		node *prev;
		node(){a = 0;prev = NULL;}
	}*bottom,*top;
	__CUSTOM_STACK_RETURN_TYPE__ len;
	Stack(){bottom = new node;top = new node;top->prev = bottom;len = 0;}

	__CUSTOM_STACK_RETURN_TYPE__ size(){return len;}
	bool empty(){return len == 0;}
	void push(_T x){++len;node *p = new node;p->a = x;p->prev = top->prev;top->prev = p;}
	_T pop(){if(top != bottom){--len;return top->a;}else return __CUSTOM_STACK_ERROR__;}
	_T top(){return (*top).a;}
};
int main()
{
	return 0;
}
