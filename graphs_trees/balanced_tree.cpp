/*
	Check if a given binary tree is balanced
*/
#include <iostream>
#include <cmath>
using namespace std;
class node{
public:
	int data;
	node* left;
	node* right;
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

int height(node* root){
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

bool isBalanced(node* root){
	if(root==NULL){
		return true;
	}
	int lh = height(root->left);
	int rh = height(root->right);
	if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right)){
		return true;
	}
	return false;
}
node* createTree(){
	int n;
	cin>>n;
	if(n==-1){
		return NULL;
	}
	node* root = new node(n);
	root->left = createTree();
	root->right = createTree();
	return root;

}

void preorder(node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

int main(int argc, char const *argv[])
{
	node * root = createTree();
	preorder(root);
	if(isBalanced(root)){
		cout<<"Tree is balanced"<<"\n";
	}
	else{
		cout<<"Not balanced"<<"\n";
	}
	return 0;
}