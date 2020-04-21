#define __CUSTOM_QUEUE_RETURN_TYPE__ long long
#define __CUSTOM_QUEUE_ERROR__ -70773
#define __CUSTOM_QUEUE_MAXIMUM_SIZE__ 1000005
template<typename _T>
class Queue{
private:
	_T a[__CUSTOM_QUEUE_MAXIMUM_SIZE__];
	__CUSTOM_QUEUE_RETURN_TYPE__ l = 0,r = 0;
public:
	_T front(){if(empty())return __CUSTOM_QUEUE_ERROR__;else return a[l];}
	_T back(){if(empty())return __CUSTOM_QUEUE_ERROR__;else return a[r];}
	__CUSTOM_QUEUE_RETURN_TYPE__ size(){return l - r;}
	bool empty(){return l == r;}
	void push(_T x){a[++r] = x;}
	_T pop(){if(empty())return __CUSTOM_QUEUE_ERROR__;else return a[l++];}
};
