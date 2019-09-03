#include <iostream>
#include <climits>
#include <vector>
#include <stack>
#include <climits>

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

node* creatTree(){
	int num;
	cin>>num;
	if(num==-1){
		return NULL;
	}
	node* root = new node(num);
	root->left = creatTree();
	root->right = creatTree();
	return root;
}
bool found(node* root, int d){
	if(root==NULL){
		return false;
	}
	if(root->data==d){
		return true;
	}
	return found(root->left, d) || found(root->right, d);
}

node* findAncestor(node* root, int d1, int d2){
	if(root==NULL){
		return root;
	}
	if(root->data == d1 || root->data == d2){
			return root;
	}
	else if(found(root->left, d1) && found(root->left, d2)){
		return findAncestor(root->left, d1, d2);
	}
	else if(found(root->right, d1) && found(root->right, d2)){
		return findAncestor(root->right, d1, d2);
	}
	else{
		if(!found(root->left, d1) && !found(root->left, d2)){
			return NULL;
		}
		if(!found(root->right, d1) && !found(root->right, d2)){
			return NULL;
		}
		
		return root;

	}

}
void inorder(node* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int nextInorder(node* root){
	if(root==NULL){
		return INT_MAX;
	}
	return min(root->data, nextInorder(root->left));
}
int main(int argc, char const *argv[])
{
	node* root =  creatTree();
	inorder(root);
	cout<<"\n";
	node* out = findAncestor(root, 3, 4);
	if(out!=NULL){
		cout<<out->data<<"\n";
	}
	//cout<<nextInorder(root->right)<<"\n";
	return 0;
}