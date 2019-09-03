#include <iostream>
#include <climits>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class linknode{
public:
	int data;
	linknode* next;
	linknode(int d){
		data = d;
		next = NULL;
	}
};

class tree_node{
public:
	int data;
	tree_node* left;
	tree_node* right;
	tree_node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

tree_node* createTree(){
	int n;
	cin>>n;
	if(n==-1){
		return NULL;
	}
	tree_node* root =  new tree_node(n);
	root->left = createTree();
	root->right = createTree();
	return root;
}

int height(tree_node* root){
	if(root==NULL){
		return 0;
	}
	if(root->left==NULL && root->right==NULL){
		return 1;
	}
	int l = 1 + height(root->left);
	int r = 1 + height(root->right);
	return max(l, r);
}
void getNodeAtLevelK(linknode* &head, linknode* &tail, tree_node* root, int k){
	if(root==NULL){
		return;
	}
	if(k==1){
		if(head==NULL){
			head = new linknode(root->data);
			tail = head;
		}
		else{
			tail->next = new linknode(root->data);
		}
	}
	getNodeAtLevelK(head, tail, root->left, k-1);
	getNodeAtLevelK(head, tail, root->right, k-1);
}
void print_link(linknode* head){
	if(head==NULL){
		return;
	}
	while(head!=NULL){
		cout<<head->data<<"-->";
		head = head->next;
	}
	cout<<"\n";
} 
void levelOrder(tree_node* root){
	if(root==NULL){
		return;
	}
	int h = height(root);
	for (int i = 1; i <= h; ++i)
	{
		linknode* head = NULL;
		linknode* tail = NULL;
		getNodeAtLevelK(head, tail, root, i);
		print_link(head);
		/* code */
	}
}
void lot(tree_node* root, int i, vector<linknode*> &v){
	if(root==NULL){
		return;
	}
	if(v[i]==NULL){
		v[i] = new linknode(root->data);
	}
	else{
		linknode* temp = v[i];
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = new linknode(root->data);
	}
	lot(root->left, i+1, v);
	lot(root->right, i+1, v);
}

void print_list(linknode* root){
	while(root!=NULL){
		cout<<root->data<<" ";
		root = root->next;
	}
	cout<<"\n";
}
void print_v(vector<linknode*> v){
	int i = 0;
		while(v[i]!=NULL){
			print_list(v[i]);
			i++;
		}
}

void call_rec_lot(tree_node* root){
	if(root==NULL){
		return;
	}
	//int h = height(root);
	
}

int main(int argc, char const *argv[])
{
	tree_node* root = createTree();
	vector<linknode*> v;
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(NULL);
		/* code */
	}
	lot(root, 0, v);
	print_v(v);
	//cout<<height(root)<<"\n";
	//levelOrder(root);
	return 0;
}