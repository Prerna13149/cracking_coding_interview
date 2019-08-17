/*
	In place rotation of a matrix by 90 degrees
*/

#include <iostream>
using namespace std;

void rotate(int mat[4][4], int R, int C){
	for (int i = 0; i < R/2; ++i)
	{
		for (int j = i; j < C-i-1; ++j)
		{
			int temp = mat[i][j];
			mat[i][j] = mat[j][C-1-i];
			int temp2 = mat[R-1-j][i];
			mat[R-1-j][i] = temp;
			temp = mat[R-1-i][C-1-j];
			mat[R-1-i][C-1-j] = temp2;
			mat[j][C-1-i] = temp;
			/* code */
		}
		/* code */
	}
}

int main(int argc, char const *argv[])
{
	int mat[4][4]={{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	rotate(mat, 4, 4);
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout<<mat[i][j]<<" ";
			/* code */
		}
		cout<<"\n";
		/* code */
	}
	return 0;
}