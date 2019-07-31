#include <iostream>
using namespace std;

int code1[3],code2[3],n,cnt;
bool flag[101][101][101];

int main()
{
	cin>>n;
	for(int i = 0;i < 3;i++)
		cin>>code1[i];
	for(int i = 0;i < 3;i++)
		cin>>code2[i];
	for(int i = -2;i <= 2;i++)
		for(int j = -2;j <= 2;j++)
			for(int k = -2;k <= 2;k++){
				flag[(code1[0] + i + n) % n][(code1[1] + j + n) % n][(code1[2] + k + n) % n] = true;
				flag[(code2[0] + i + n) % n][(code2[1] + j + n) % n][(code2[2] + k + n) % n] = true;
			}
	int cnt = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			for(int k = 0;k < n;k++)
				cnt += flag[i][j][k];
	cout<<cnt;
	return 0;
}
