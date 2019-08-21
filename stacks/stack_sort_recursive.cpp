/*
	Sort the stack recursive
*/

#include <iostream>
#include <stack>
using namespace std;

void push_bottom(stack<int> &s, int ele){
	if(s.empty()|| ele<=s.top()){
		s.push(ele);
		return;
	}
	int  p = s.top();
	if(ele> s.top()){
		s.pop();
		push_bottom(s, p);
	}
	s.push(ele);
	return;
}

void sort_stack(stack<int> &s){
	if(s.empty()||s.size()==1){
		return;
	}
	int t = s.top();
	s.pop();
	sort_stack(s);
	push_bottom(s, t);
	return;
}

int main(int argc, char const *argv[])
{
	stack<int> s;
	int n;
	cin>>n;
	int i=0;
	int num;
	while(i<n){
		cin>>num;
		s.push(num);
		i++;
	}
	sort_stack(s);
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	return 0;
}
