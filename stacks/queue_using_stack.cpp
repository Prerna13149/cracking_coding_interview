/*
	IMplement a MyQueue class which implements a queue using 2 stacks
*/

#include <iostream>
#include <stack>
using namespace std;

class myQueue{
public:
	stack<int> s1;
	stack<int> s2;
	void enqueue(int d){
		s1.push(d);
	}
	void dequeue(){
		while(!s1.empty()){
			int t = s1.top();
			s1.pop();
			s2.push(t);
		}
		s2.pop();
		while(!s2.empty()){
			int t = s2.top();
			s2.pop();
			s1.push(t);
		}
	}
	int front(){
		while(!s1.empty()){
			int t = s1.top();
			s1.pop();
			s2.push(t);
		}
		int out = s2.top();
		while(!s2.empty()){
			int t = s2.top();
			s2.pop();
			s1.push(t);
		}
		return out;
	}
	bool isEmpty(){
		return s1.empty();
	}
};

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int i=0;
	int num;
	myQueue q;
	while(i<n){
		cin>>num;
		q.enqueue(num);
		i++;
	}
	while(!q.isEmpty()){
		cout<<q.front()<<" ";
		q.dequeue();
	}
	/* code */
	return 0;
}