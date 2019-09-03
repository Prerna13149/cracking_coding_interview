#include<iostream>
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
node* createTree(){
	int n;
	cin>>n;
	node* root = new node(n);
	char ch[1000];
	cin>>ch;
	if(ch[0]=='t'){
		root->left = createTree();
	}
	else{
		root->left = NULL;
	}
	cin>>ch;
	if(ch[0]=='t'){
		root->right = createTree();
	}
	else{
		root->right = NULL;
	}
	return root;
};
bool found(node* root, int d){
	if(root==NULL){
		return false;
	}
	if(root->data == d){
		return true;
	}
	return found(root->left, d)||found(root->right, d);
}
node* LCA(node* root, int d1, int d2){
	if(root==NULL || !found(root, d1) || !found(root, d2)){
		return NULL; 
	}
	if(root->data==d1 && found(root, d2)){
		return root;
	}
	if(root->data==d2 && found(root, d1)){
		return root;
	}
	if(found(root->left, d1) && found(root->left, d2)){
		return LCA(root->left, d1, d2);
	}
	if(found(root->right, d1) && found(root->right, d2)){
		return LCA(root->right, d1, d2);
	}
	else{
		if(found(root->left, d1) && found(root->right, d2)){
			return root;
		}
		if(found(root->right, d1) && found(root->left, d2)){
			return root;
		}
	}

}
void inorder(node* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<"\n";
	inorder(root->right);
	return;
}
int main() {
	node* root = createTree();
	int d1, d2;
	cin>>d1>>d2;
	//inorder(root);
	node* out = LCA(root, d1, d2);
	if(out!=NULL){
		cout<<out->data<<"\n";
	}
	else{
		cout<<-1<<"\n";
	}
	return 0;
}

