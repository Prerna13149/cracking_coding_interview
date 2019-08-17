/*
	If an element in an MXN matrix is 0, its entire row and column are set to 0.
*/

#include <iostream>
#include <cstring>
using namespace std;

void convertZero(int mat[1000][1000], int r, int c, int R, int C){
	for (int i = 0; i < C; ++i)
	{
		if(mat[r][i]!=1){
			mat[r][i] = 0;
		}
		/* code */
	}
	for (int i = 0; i < R; ++i)
	{
		if(mat[i][c]!=1){
			mat[i][c] = 0;
		}
		/* code */
	}
	return;
}
void setMatrix(int mat[1000][1000], int r, int c){
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if(mat[i][j]==1){
				convertZero(mat, i, j, r, c);
				mat[i][j] = 0;
			}
			/* code */
		}
		/* code */
	}
}

int main(int argc, char const *argv[])
{
	int m, n;
	cin>>m>>n;
	int mat[1000][1000];
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>mat[i][j];
			/* code */
		}
		/* code */
	}
	setMatrix(mat, m, n);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<mat[i][j]<<" ";
			/* code */
		}
		cout<<"\n";
		/* code */
	}
	return 0;
}