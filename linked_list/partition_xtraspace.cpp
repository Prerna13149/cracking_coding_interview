/*
	Partion a linked list around x using extra space
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

void insert(node* &head, node* &tail, int num){
	node* new_node = new node(num);
	if(head==NULL){
		head = new_node;
		tail = head;
	}
	else{
		node* curr = head;
		while(curr->next!=NULL){
			curr = curr->next;
		}
		curr->next = new_node;
		tail = new_node;
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
	node* small_head = NULL;
	node* small_tail= NULL;
	node* large_head = NULL;
	node* large_tail = NULL;
	int i=0;
	int num;
	while(i<n){
		cin>>num;
		if(num>x){
			insert(large_head, large_tail, num);
			cout<<large_head->data<<" ";
			cout<<large_tail->data<<"\n";
		}
		else{
			insert(small_head, small_tail, num);
			cout<<small_head->data<<" ";
			cout<<small_tail->data<<"\n";
		}
		i++;
	}
	node* temp = head;
	small_tail->next = head;
	head = small_head;
	//print(head);
	temp->next = large_head;
	print(head);
	return 0;
}
