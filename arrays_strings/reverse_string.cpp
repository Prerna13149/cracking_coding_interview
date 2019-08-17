/*
	Given a null terminated string, reverse it
*/

#include <iostream>
#include <cstring>
using namespace std;

void reverse(char ch[]){
	int n = strlen(ch);
	int i = 0;
	int j = n-1;
	while(i<j){
		swap(ch[i], ch[j]);
		i++;
		j--;
	}
	//cout<<ch<<"\n";
	return;
}
int main(int argc, char const *argv[])
{
	char ch[1000];
	cin>>ch;
	reverse(ch);
	cout<<ch<<"\n";
	return 0;
}