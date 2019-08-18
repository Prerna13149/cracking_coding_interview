/*
	Partitiona linked list around a value x, s.t all the nodes less than x come before and all the nodes greater than come after.
*/

#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* next;
	node(int d){
		data = d;
		next = NULL;
	}
};

void print(node* head){
	if(head==NULL){
		return;
	}
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<"\n";
}

void insert(node* &head, node* &tail, int num, int x){
	node* new_node = new node(num);
	if(num>x){
		tail->next = new_node;
		tail = new_node;
	}
	else{
		new_node->next = head;
		head = new_node;
	}
}

int main(int argc, char const *argv[])
{
	int x;
	int n;
	cin>>x;
	cin>>n;
	node* head = new node(x);
	node* tail = head;
	int i=0;
	int num;
	while(i<n){
		cin>>num;
		insert(head, tail, num, x);
		i++;
	}
	print(head);
	return 0;
}