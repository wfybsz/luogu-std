#include "Search_Object_Function.h"
int Binary_Search_Min(int Left,int Right){
	while(Left <= Right){
		int Mid = (Left + Right) / 2;
		if(f(Mid))
			Right = Mid - 1;
		else
			Left = Mid + 1;
	}
	return Right + 1;
}
