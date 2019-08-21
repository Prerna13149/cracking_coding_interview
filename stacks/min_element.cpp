/*
	Design a stack which has a min function. The min function should return the minimum element in the stack at any instant.
*/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class stack{
public:
	int cs;
	int min_ele;
	vector<int> s;
	stack(){
		cs = 0;
		min_ele = INT_MAX;
	}
	void push(int d){
		s.push_back(d);
		cs++;
		if(d < min_ele){
			min_ele = d;
		}
	}
	void pop(){
		int t = s[cs-1];
		if(t!=min_ele){
			s.erase(s.end()-1);
		}
		else{
			s.erase(s.end()-1);
			min_ele =INT_MAX;
			for (int i = 0; i < s.size(); ++i)
			{
				if(s[i]<min_ele){
					min_ele = s[i];
				}
				/* code */
			}
		}
		
		cs--;
	}
	int top(){
		return s[cs-1];
	}
	int getMin(){
		return min_ele;
	}
	bool isEmpty(){
		return cs==0;
	}
};

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int i=0;
	int num;
	stack stk;
	while(i<n){
		cin>>num;
		stk.push(num);
		i++;
	}
	while(!stk.isEmpty()){
		cout<<stk.top()<<" "<<"min ele: "<<stk.getMin()<<"\n";
		stk.pop();
	}

	return 0;
}