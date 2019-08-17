/*
	Perform string compression
	aaabcccccaaa = a3b1c5a3
*/

#include <iostream>
#include <cstring>
using namespace std;

void compress(char ch[]){
	int i=0;
	while(ch[i]!='\0'){
		char p = ch[i];
		int j = i;
		int ct = 0;
		while(ch[j]==p){
			ct++;
			j++;
		} 
		cout<<p<<ct;
		i = i + ct;
	}
}
int main(int argc, char const *argv[])
{
	char ch[1000];
	cin>>ch;
	compress(ch);
	return 0;
}