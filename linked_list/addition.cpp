/*
	Adding two linked list
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
			curr = curr -> next;
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
int getLength(node* head){
	if(head==NULL){
		return 0;
	}
	int i=0;
	while(head!=NULL){
		i++;
		head = head->next;
	}
	return i;
}
node* add(node* &head1, node* &tail1, node* &head2, node* &tail2){
	if(head1==NULL && head2==NULL){
		return NULL;
	}
	else if(head1==NULL){
		return head2;
	}
	else if(head2==NULL){
		return head1;
	}
	else{
		int n1 = getLength(head1);
		int n2 = getLength(head2);
		node* curr1 = head1;
		node* curr2 = head2;
		node* prev = NULL;
		int carry = 0;
		if(n1>=n2){
			while(curr1!=NULL & curr2!=NULL){
				int temp = curr1->data;
				curr1->data = (curr1->data + curr2->data + carry)%10;
				carry = (temp + curr2->data + carry)/10;
				prev = curr1;
				curr1 = curr1->next;
				curr2 = curr2->next;
			}
			if(carry!=0){
				node* new_node = new node(carry);
				prev->next = new_node;
				tail1 = new_node; 
			}
			return head1;
		}
		else{
			while(curr1!=NULL & curr2!=NULL){
				int temp = curr2->data;
				curr2->data = (curr1->data + curr2->data + carry)%10;
				carry = (curr1->data + temp + carry)/10;
				prev = curr2;
				curr1 = curr1->next;
				curr2 = curr2->next;
			}
			if(carry!=0){
				node* new_node = new node(carry);
				prev->next = new_node;
				tail2 = new_node; 
			}
			return head2;
		}

	}
}

void reverse(node* &head){
	if(head==NULL||head->next==NULL){
		return;
	}
	node* curr = head;
	node* prev;
	node* n;// = curr->next;
	while(curr!=NULL){
		n = curr->next;
		curr->next = prev;
		prev = curr;
		curr = n;
	}
	head = prev;
}
int main(int argc, char const *argv[])
{
	node* head = NULL;
	node* tail = NULL;
	int n;
	cin>>n;
	int i=0;
	int num;
	while(i<n){
		cin>>num;
		insert_end(head, tail, num);
		i++;
	}
	print(head);
	i =0;
	node* head2 = NULL;
	node* tail2 = NULL;
	while(i<n){
		cin>>num;
		insert_end(head2, tail2, num);
		i++;
	}
	print(head2);
	node* out = add(head, tail, head2, tail2);
	reverse(out);
	print(out);
	return 0;
}