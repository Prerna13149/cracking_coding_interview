/*
	Circular Linkedlist
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

void insert_end(node* &head, node* &tail, int num){
	node* new_node = new node(num);
	if(head == NULL){
		head = new_node;
		tail = head;
	}
	else{
		node* curr =  head;
		while(curr->next!=NULL){
			curr = curr->next;
		}
		curr->next= new_node;
		tail = new_node;
	}
}

bool detectCycle(node* head){
	if(head==NULL){
		return false;
	}
	node* s = head;
	node* f = head->next;
	while(f!=NULL && f->next!=NULL){
		if(s==f){
			return true;
		}
		s = s->next;
		f = f->next->next;
	}
	return false;
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


void cycleBreak(node* &head){
	node* s = head;
	node* f = head->next;
	while(1){
		// if(s==NULL||f==NULL||f->next==NULL||s->next==NULL){
		// 	return;
		// }
		if(s==f){
			break;
		}
		s = s->next;
		f = f->next->next;
	}
	node* prev =head;
	while(prev->next!=f){
		prev = prev->next;
	}
	s = head;
	while(s!=f){
		s=s->next;
		f=f->next;
		prev = prev->next;
	}
	prev->next = NULL;
	return;

}

int main(int argc, char const *argv[])
{
	int n;
	int i=0;
	cin>>n;
	int num;
	node* head = NULL;
	node * tail = NULL;
	while(i<n){
		cin>>num;
		insert_end(head, tail, num);
		i++;
	}
	tail->next = head;
	if(detectCycle(head)){
		cout<<"Cycle detected"<<"\n";
		cycleBreak(head);
	}
	print(head);
	
	return 0;
}