/*
	Sort the stack iteratively
*/

#include <iostream>
#include <stack>
using namespace std;

void sort_stack(stack<int> &s){
	if(s.empty()){
		return;
	}
	stack<int> r;
	while(!s.empty()){
		int t = s.top();
		s.pop();
		while(!r.empty() && r.top()>t){
			s.push(r.top());
			r.pop();
		}
		r.push(t);
	}
	while(!r.empty()){
		s.push(r.top());
		r.pop();
	}
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