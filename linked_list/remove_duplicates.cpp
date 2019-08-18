/*
	Remove duplicates in a linkedlist
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
	node * new_node = new node(d);
	if(head==NULL){
		head = new_node;
		tail = head;
	}
	else{
		new_node->next = head;
		head = new_node;
	}
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

void remove_duplicates(node* &head, node* &tail){
	int arr[1000000]={0};
	if(head==NULL){
		return;
	}
	node* prev = NULL;
	node* curr = head;
	while(curr!=NULL){
		if(arr[curr->data]==0){
			arr[curr->data]++;
			prev = curr;
			curr= curr->next;
		}
		else{
			prev->next = curr->next;
			curr->next = NULL;
			delete curr;
			curr = prev->next;
		}
	}
	tail = prev;
	return;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int i = 0;
	int num;
	node* head = NULL;
	node* tail = NULL;
	while(i<n){
		cin>>num;
		insert_front(head, tail, num);
		i++;
	}
	print(head);
	remove_duplicates(head, tail);
	print(head);
	return 0;
}
