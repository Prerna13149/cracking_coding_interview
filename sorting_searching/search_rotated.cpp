/*
	Find element in rotated and sorted array
*/

#include <iostream>
using namespace std;

int binarySearch(int arr[], int s, int e, int ele){
	if(s>e){
		return -1;
	}
	int mid = (s+e)/2;
	if(arr[mid]==ele){
		return mid;
	}
	if(ele>arr[e]){
		return binarySearch(arr, s, mid-1, ele);
	}
	else{
		return binarySearch(arr, mid+1, e, ele);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[100];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		/* code */
	}
	int ele;
	cin>>ele;
	cout<<binarySearch(arr, 0, n-1, ele)<<"\n";
	return 0;
}
