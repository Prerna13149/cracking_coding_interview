/*
  Implement setOfStacks class which contains many stacks. Each stack has a capacity, when more elements are inserted, it topples and is   inserted into the next stack
*/

#include <iostream>
#include <climits>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class set_of_stacks{
public:
	vector<stack<int> > s;
	int curr_s;
	int capacity;
	int cs;
	set_of_stacks(int n){
		curr_s = 0;
		capacity = n;
		cs = 0;
		for(int i=0;i<n;i++){
			stack<int>local_stack;
			s.push_back(local_stack);
		}
	}
	void push_stack(int ele){
		if(s[curr_s].size()<capacity){
			s[curr_s].push(ele);
		}
		else{
			cout<<"Creating new stack"<<"\n";
			curr_s++;
			s[curr_s].push(ele);
		}
	}
	void pop_stack(){
		s[curr_s].pop();
		if(s[curr_s].empty()){
			curr_s--;
		}
	}
	int top_stack(){
		return s[curr_s].top();
	}
	void print_stack(){
		while(curr_s>=0){
			while(!s[curr_s].empty()){
				cout<<s[curr_s].top()<<" ";
				s[curr_s].pop();
			}
			cout<<"\n";
			curr_s--;
		}
	}
	int stack_num(){
		return curr_s;
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	set_of_stacks s(3);
	s.push_stack(1);
	s.push_stack(3);
	s.push_stack(5);
	s.push_stack(6);
	cout<<s.top_stack()<<"\n";
	cout<<"I am on stack "<<s.stack_num()<<"\n";
	s.push_stack(8);
	s.push_stack(9);
	s.print_stack();

	return 0;
}
