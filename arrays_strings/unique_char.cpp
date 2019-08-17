/*
	Given a string, find if the string has all unique characters
*/
#include <iostream>
#include <cstring>
using namespace std;

bool isUnique(char ch[]){
	int arr[128]={0};
	int i=0;
	while(ch[i]!='\0'){
		int a = ch[i];
		arr[a]++;
		i++;
	}
	for (int j = 0; j < 128; j++)
	{
		if(arr[j]!=0 && arr[j]!=1){
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
	int n = strlen(ch);
	if(isUnique(ch)){
		cout<<"All unique characters"<<"\n";
	}
	else{
		cout<<"Not unique characters"<<"\n";
	}

	return 0;
}
