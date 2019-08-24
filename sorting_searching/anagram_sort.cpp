/*
	Sort on the basis of anagrams such that all anagrams come together
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int getlength(string s){
	int i=0;
	while(s[i]!='\0'){
		i++;
	}
	return i;
}
void bubbleSort(string arr_cpy[], int arr[], int n){
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if(arr_cpy[j]>arr_cpy[j+1]){
				swap(arr_cpy[j], arr_cpy[j+1]);
				swap(arr[j], arr[j+1]);
			}
			/* code */
		}
		/* code */
	}
}
int main(int argc, char const *argv[])
{
	string arr[100];
	string arr_cpy[100];
	int arr_i[100];
	//string s;
	int n;
	cin>>n;
	int i=0;
	while(i<n){
		cin>>arr[i];
		arr_cpy[i] = arr[i];
		arr_i[i] = i;
		i++;
	}
	//sort individual word in array
	for (int i = 0; i < n; i++)
	{
		sort(arr_cpy[i].begin(), arr_cpy[i].end());
	}
	bubbleSort(arr_cpy, arr_i, n);
	for (int i = 0; i < n; i++)
	{
		int a = arr_i[i];
		cout<<arr[a]<<" ";
		/* code */
	}
	return 0;
}