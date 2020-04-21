#define __CUSTOM_STACK_RETURN_TYPE__ long long
#define __CUSTOM_STACK_ERROR__ -70773
#define __CUSTOM_STACK_MAXIMUM_SIZE__ 1000005
//Guess what? The defined digit is the mirroring of "Error"!
template<typename _T>
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
};
