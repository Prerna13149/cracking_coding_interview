/*
	Delete the middle node given access to the middle node only
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
node* middle(node* head){
	if(head==NULL||head->next==NULL){
		return head;
	}
	node* s = head;
	node* f = head->next;
	while(f!=NULL && f->next!=NULL){
		s = s->next;
		f = f->next->next;
	}
	return s;
}
void delete_mid(node* &mid){
	if(mid==NULL){
		return;
	}
	node* prev;
	while(mid->next!=NULL){
		mid->data = mid->next->data;
		prev = mid;
		mid = mid->next;
	}
	prev->next = NULL;
	delete mid;
}

int main(int argc, char const *argv[])
{
	/* code */
	int n;
	cin>>n;
	int i=0;
	int num;
	node* head = NULL;
	node* tail = NULL;
	while(i<n){
		cin>>num;
		insert(head, tail, num);
		i++;
	}
	print(head);
	node* mid = middle(head);
	delete_mid(mid);
	print(head);
	return 0;
}