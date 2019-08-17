/*
	CHeck if a given string is a permuation of another string
*/

#include <iostream>
#include <cstring>
using namespace std;

bool checkPermatuation(char ch1[], char ch2[]){
	int n1 = strlen(ch1);
	int n2 = strlen(ch2);
	if(n1!=n2){
		return false;
	}
	int arr[128]={0};
	int i=0;
	while(ch1[i]!='\0'){
		int a  = ch1[i];
		arr[a]++;
		i++;
	}
	i = 0;
	while(ch2[i]!='\0'){
		int a = ch2[i];
		arr[a]--;
		i++;
	}
	for (int j = 0; j < 128; j++)
	{
		if(arr[j]!=0){
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
	if(checkPermatuation(ch1, ch2)){
		cout<<"Given strings are permuatation"<<"\n";
	}
	else{
		cout<<"Given strings are not permuatation"<<"\n";
	}
	return 0;
}