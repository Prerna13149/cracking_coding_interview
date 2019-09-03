/*
	Create a balanced bst from a sorted array
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
node* createTree(int arr[], int st, int e){
	if(st>e){
		return NULL;
	}
	int mid = (st+e)/2;
	node* root = new node(arr[mid]);
	root->left = createTree(arr, st, mid-1);
	root->right = createTree(arr, mid+1, e);
	return root;
}

void inorder(node* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
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
	int arr[1000];
	int n;
	cin>>n;
	int i=0;
	while(i<n){
		cin>>arr[i];
		i++;
	}
	//node* temp = NULL;
	node* root = createTree(arr, 0, n-1);
	inorder(root);
	cout<<"\n";
	preorder(root);
	return 0;
}