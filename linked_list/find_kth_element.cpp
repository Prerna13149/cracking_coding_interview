/*
	Find the kth element from the end
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
void insert_front(node* &head, node* &tail, int d){
	node* new_node = new node(d);
	if(head ==NULL){
		head = new_node;
		tail = head;
	}
	else{
		new_node->next = head;
		head = new_node;
	}
	return;
}
int getLength(node* head){
	if(head==NULL){
		return 0;
	}
	int i = 0;
	while(head!=NULL){
		head = head -> next;
		i++;
	}
	return i;
}
void find_kth_last(node *head, node* tail, int k){
	if(head==NULL){
		return;
	}
	int n = getLength(head);
	if(k>n){
		return;
	}
	node* s = head;
	node* f = head;
	int i=0;
	while(i<k){
		s = s ->next;
		i++;
	}
	while(s!=NULL){
		f = f->next;
		s = s->next;
	}
	cout<<f->data<<"\n";
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

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int i = 0;
	int num;
	node * head = NULL;
	node* tail = NULL;
	while(i<n){
		cin>>num;
		insert_front(head, tail, num);
		i++;
	}
	print(head);
	int k;
	cin>>k;
	find_kth_last(head, tail, k);
	return 0;
}