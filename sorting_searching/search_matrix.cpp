/*
	Search an element in a matrix which is row and column sorted
*/
#include <iostream>
using namespace std;

void search(int mat[100][100], int r, int c, int ele){
	int sr = 0;
	int er = r-1;
	int sc = 0;
	int ec = c-1;
	while(sr<=er && ec>=sc){
		if(mat[sr][ec]==ele){
			cout<<sr<<" "<<ec<<"\n";
			return;
		}
		else if(mat[sr][ec]<ele){
			sr++;
		}
		else{
			ec--;
		}
	}
}

int main(int argc, char const *argv[])
{
	int r, c;
	cin>>r>>c;
	int mat[100][100];
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin>>mat[i][j];
			/* code */
		}
		/* code */
	}
	int ele;
	cin>>ele;
	search(mat, r, c, ele);
	return 0;
}