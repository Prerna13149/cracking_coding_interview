/*
	Given a string, find if the string has all unique characters without using any extra data structure
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool binarySearch(char ch[], int st, int e, char a){
	if(st>e){
		return false;
	}
	int mid = (st + e)/2;
	if(ch[mid]==a){
		return true;
	}
	else if(ch[mid]>a){
		return binarySearch(ch, st, mid-1, a);
	}
	else{
		return binarySearch(ch, mid+1, e, a);
	}
}

bool isUnique2(char ch[]){
	int n = strlen(ch);
	sort(ch, ch+n);
	int d = 0;
	for (int i = 0; i < n; ++i)
	{
		char a = ch[i];
		if(binarySearch(ch, i+1, n, a)){
			return false;
		}
		/* code */
	}
	return true;
}

bool isUnique(char ch[]){
	int n = strlen(ch);
	sort(ch, ch+n);
	int d = 0;
	for (int i = 0; i < n-1; ++i)
	{
		d = ch[i+1]-ch[i];
		if(d==0){
			return false;
		}
		/* code */
	}
	return true;
}

int main(int argc, char const *argv[])
{
	char ch[1000];
	cin>>ch;
	if(isUnique2(ch)){
		cout<<"All unique characters"<<"\n";
	}
	else{
		cout<<"Not unique characters"<<"\n";
	}
	return 0;
}