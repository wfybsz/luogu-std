#include <iostream>
using namespace std;

bool iln1,iln2,iln3,iln4;

bool cmp(){
	return ((iln1 != iln2) && (iln3 || iln4)) != ((iln2 && iln3) || (iln1 != iln4));
}

int main()
{
	cin>>iln1>>iln2>>iln3>>iln4;
	cout<<cmp();
	return 0;
}
