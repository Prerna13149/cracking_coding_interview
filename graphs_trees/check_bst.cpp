/*
	Check if a binary tree is a binary search tree
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