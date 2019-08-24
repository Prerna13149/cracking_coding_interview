/*
	Given a sorted array of strings which is interspersed with empty strings, write a method to find the location of a given string
*/

#include <iostream>
#include <cstring>
using namespace std;

int binarySearch(string arr[], int s, int e, string ele){
	if(s > e){
		return -1;
	}
	int mid = (s+e)/2;
	//cout<<mid<<"\n";
	if(arr[mid]==""){
		int l = mid-1;
		int r = mid+1;
		if(l>=s &&  r<=e){
			while(1){
				if(arr[l]!="" && l>=s){
					mid = l; 
					break;
				}
				if(arr[r]!="" && r<=e){
					mid = r;
					break;
				}
				l--;
				r++;
			}
		}
		
	}
	if(arr[mid]==ele){
		return mid;
	}
	if(arr[mid]>ele){
		return binarySearch(arr, s, mid-1, ele);
	}
	else{
		return binarySearch(arr, mid+1, e, ele);
	}
}

int main(int argc, char const *argv[])
{
	string arr[100] = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
	// int n;
	// cin>>n;
	// int i=0;
	// while(i<n){
	// 	cin>>arr[i];
	// 	i++;
	// }
	string ele="ball";
	//cin>>ele;
	cout<<binarySearch(arr, 0, 11, ele)<<"\n";
	return 0;
}