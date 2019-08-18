/*
	Check if a linkedlist is a palindrome
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

void insert_end(node* &head, node* &tail, int d){
	node* new_node = new node(d);
	if(head == NULL){
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
	return;

}
void print(node* head){
	if(head==NULL){
		return;
	}
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<"\n";
	return;
}
void reverse(node* &head, node * &tail){
	if(head==NULL||head->next==NULL){
		return;
	}
	node* curr = head;
	node* prev;
	node* n;
	while(curr!=NULL){
		n = curr->next;
		curr->next= prev;
		prev = curr;
		curr = n;
	}
	tail = head;
	head = prev;
	return;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int i =0;
	int num;
	node* head = NULL;
	node* tail = NULL;
	node* head1 = NULL;
	node* tail1 = NULL;
	while(i<n){
		cin>>num;
		insert_end(head, tail, num);
		insert_end(head1, tail1, num);
		i++;
	}
	reverse(head1, tail1);
	print(head1);
	while(head1!=NULL && head!=NULL){
		if(head1->data != head->data){
			cout<<"Not a palindrome"<<"\n";
			return 0;
		}
		head1 = head1->next;
		head = head ->next;
	}
	if(head1!=NULL || head!=NULL){
		cout<<"Not a palindrome"<<"\n";
		return 0;
	}
	cout<<"Palindrome"<<"\n";
	return 0;
}