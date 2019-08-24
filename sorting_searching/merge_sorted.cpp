/*
	Given two sorted arrays, A and B where A has large enough buffer at the end to hold B. Write a method to merge A and B in sorted order.
*/

#include <iostream>
#include <vector>
using namespace std;

void merge(int A[], int B[], int n1, int n2, int max_S){
	int i = n1-1;
	int j = n2-1;
	int k = max_S - 1;
	while(i >= 0 && j >= 0){
		if(A[i]>B[j]){
			A[k] = A[i];
			i--;
		}
		else{
			A[k] = B[j];
			j--;
		}
		k--;
	}
	while(j>=0){
		A[k] = B[j];
		k--;
		j--;
	}
	return;
}

int main(int argc, char const *argv[])
{
	int A[100];
	int B[100];
	int n_a, n_b;
	cin>>n_a>>n_b;
	int max_S = n_a + n_b;
	for (int i = 0; i < n_a; ++i)
	{
		cin>>A[i];
		/* code */
	}
	for (int i = 0; i < n_b; ++i)
	{
		cin>>B[i];
		/* code */
	}
	merge(A, B, n_a, n_b, max_S);
	for (int i = 0; i < max_S; ++i)
	{
		cout<<A[i]<<" ";
		/* code */
	}
	return 0;
}