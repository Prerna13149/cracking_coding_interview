/*

*/

#include <iostream>
using namespace std;

void sort_2d(int arr[2][100], int n){
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if(arr[0][j]> arr[0][j+1]){
				swap(arr[0][j], arr[0][j+1]);
				swap(arr[1][j], arr[1][j+1]);
			}
			/* code */
		}
		/* code */
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[2][100];
	for (int i = 0; i < n; i++)
	{
		cin>>arr[0][i];
		cin>>arr[1][i];
		/* code */
	}
	sort_2d(arr, n);
	
	//reverse sorted array to get in reverse order
	int i=0;
	int j = n-1;
	while(i<j){
		swap(arr[0][i], arr[0][j]);
		swap(arr[1][i], arr[1][j]);
		i++;
		j--;
	}

	cout<<"Sorted in decreasing order"<<"\n";
	for (int i = 0; i < n; i++)
	{
		cout<<arr[0][i]<<" "<<arr[1][i]<<"\n";
		/* code */
	}

	int ct = 1;
	for (int k = 0; k < (n-1); k++)
	{
		if(arr[1][k]>arr[1][k+1] && arr[0][k]>arr[0][k+1]){
			ct++;
		}
		else{
			break;
		}
		/* code */
	}
	cout<<ct<<"\n";
	return 0;
}