template<typename T>
class stck{
private:
	T a[1000000];
	int tp = 0;
public:
	void push(const T b){a[++tp] = b;}
	T pop(){return a[tp--];}
	T top()const{return a[tp];}
	int size()const{return tp;}
	bool empty()const{return !tp;}
};
