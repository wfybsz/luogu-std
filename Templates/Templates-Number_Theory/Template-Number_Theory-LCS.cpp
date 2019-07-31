//Longest Common Subsequence(LCS)
#include <bits/stdc++.h>
int x[] = {0},y = {0},f[][] = {0},xl,yl;
int lcs(){
	for(int i = 1;i <= xl;i++)
		for(int j = 1;j <= yl;j++)
			if(x[i] == y[j])
				f[i % 2][j] = f[(i - 1) % 2][j - 1] + 1;
			else
				f[i % 2][j] = max(f[(i - 1) % 2][j],f[i % 2][j - 1]);
	return f[xl % 2][yl];
}
