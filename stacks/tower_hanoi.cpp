/*
	Tower of hanoi using stacks
*/

#include <iostream>
#include <stack>
using namespace std;
void towerHanoi(int n, stack<int> s, stack<int> h, stack<int> d){
	if(n==0){
		return;
	}
	towerHanoi(n-1, s, d, h);
	int t =  s.top();
	s.pop();
	d.push(t);
	cout<<"Moving "<<t;
	towerHanoi(n-1, h, s, d);
}


int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	stack<int> s, h, d;
	towerHanoi(n, s, h, d);
	return 0;
}