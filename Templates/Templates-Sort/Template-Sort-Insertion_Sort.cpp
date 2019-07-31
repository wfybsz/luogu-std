void Isort(int begin,int end){
		typedef typename std::iterator_traits<int>::value_type value_type;
	int bond = begin;
	std::advance(bond,1);
	for(;bond != end;std::advance(bond,1))
	{
		value_type key = *bond;
		int ins = bond;
		int pre = ins;
		std::advance(pre,-1);
		while(ins != begin && *pre > key){
			*ins = *pre;
			std::advance(ins,-1);
			std::advance(pre,-1);
		}
		*ins = key;
	}
}
