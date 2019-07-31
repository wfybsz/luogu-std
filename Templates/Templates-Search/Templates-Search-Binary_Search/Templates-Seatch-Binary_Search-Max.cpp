#include "Search_Object_Function.h"
int Binary_Search_Max(int Left,int Right){
	while(Left <= Right){
		int Mid = (Left + Right) / 2;
		if(f(Mid))
			Left = Mid + 1;
		else
			Right = Mid - 1;
	}
	return Left - 1;
}
