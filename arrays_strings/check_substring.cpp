/*
	Check if given 2 strings, check if strings are substrings
*/

#include <iostream>
#include <cstring>
using namespace std;

bool isPresent(char ch[], char a){
	int i=0;
	while(ch[i]!='\0'){
		if(ch[i]==a){
			return true;
		}
		i++;
	}
	return false;
}

bool check(char ch1[], char ch2[]){
	int i=0;
	int arr[128]={0};
	while(ch1[i]!='\0'){
		char a = ch1[i];
		if(!isPresent(ch2, a)){
			return false;
		}
		else{
			int p = ch1[i];
			arr[p]++;
		}
		i++;
	}
	i = 0;
	while(ch2[i]!='\0'){
		int p = ch2[i];
		arr[p]--;
		i++;
	}
	for (int i = 0; i < 128; ++i)
	{
		if(arr[i]>0){
			return false;
		}
		/* code */
	}
	return true;
}

int main(int argc, char const *argv[])
{
	char ch1[1000];
	char ch2[1000];
	cin>>ch1>>ch2;
	if(check(ch1, ch2)){
		cout<<"Yes, substrings"<<"\n";
	}
	else{
		cout<<"Not a substring"<<"\n";
	}
	return 0;
}