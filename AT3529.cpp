#include <iostream>
#include <cmath>
int main()
{
	int n,cnt = 0,tmp1,tmp2;
	std::cin>>n;
	for(int i = 1;i <= n;i++){
		std::cin>>tmp1>>tmp2;
		cnt += std::abs(tmp1 - tmp2) + 1;
	}
	std::cout<<cnt;
	return 0;
}
