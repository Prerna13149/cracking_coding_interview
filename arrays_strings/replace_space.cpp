/*
	Given a string, replace ' ' by '%20'.
*/

#include <iostream>
#include <cstring>
using namespace std;

void moveby(char ch[], int st, int n, int amt){
	int i = n-1;
	while(i>(st+amt)){
		ch[i] = ch[i-2];
		i--;
	}
	return;
}

void replace(char ch[], int n){
	int i=0;
	while(ch[i]!='\0'){
		if(ch[i]==' '){
			moveby(ch, i, n, 2);
			ch[i] = '%';
			ch[i+1] ='2';
			ch[i+2] = '0';
			i = i + 3;
		}
		else{
			i++;
		}
	}
	return;
}

int main(int argc, char const *argv[])
{
	char ch[1000];
	cin.getline(ch, 1000);
	int n = strlen(ch);
	replace(ch, n);
	cout<<ch<<"\n";
	return 0;
}