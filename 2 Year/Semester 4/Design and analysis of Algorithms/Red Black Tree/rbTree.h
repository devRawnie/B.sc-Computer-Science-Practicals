#ifndef _RB_TREE_H
#define _RB_TREE_H
#include <cstddef>
#include<iostream>
const char red = 'R';
const char black = 'B';
using namespace std;
struct rbNode{
	int data;
	char color;
	struct rbNode *left, *right, *parent;
	rbNode(){
		this->left = NULL;
		this->right = NULL;
		this->color = 'n';
	}
	rbNode(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->color = 'n';
	}
	rbNode(int data, char c){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		this->color = c;
	}

};

class RBTree{
	protected:
	struct rbNode* root;
	int blackHeight;
	void inorder(rbNode* n);
	void postorder(rbNode* n);
	void preorder(rbNode* n);
	public:
	struct rbNode* insertInBst(rbNode* n, int data);
	int getHeight();
	void incrementHeight();
		RBTree()
		{
			root = NULL;
		}
	
	int insertNode(int data);
	void displayTree();
};

int RBTree::insertNode(int data){
	if(root == NULL){
		root = new rbNode(data, black);
		this->incrementHeight();
	}else{
		insertInBst(this->root, data);
	}
}

struct rbNode* RBTree::insertInBst(rbNode* node, int data){
	if(node == NULL) return new rbNode(data, red);
	
	if( data < node->data)
		node->left = insertInBst(node->left, data);
	else
		node->right = insertInBst(node->right, data);
	return node;
}
int RBTree::getHeight(){
	return this->blackHeight;
}
void RBTree::incrementHeight(){
	this->blackHeight++;
}

void RBTree::postorder(rbNode* n){
	if(n!=NULL){
		postorder(n->left);
		postorder(n->right);
		printf("%d (%c) ", n->data, n->color);
	}
}

void RBTree::inorder(rbNode* n){
	if(n!=NULL){
		inorder(n->left);
		printf("%d (%c) ", n->data, n->color);
		inorder(n->right);
	}
}

void RBTree::preorder(rbNode* n){
	if(n!=NULL){
		printf("%d (%c) ", n->data, n->color);
//		cout<<n->data<<" ";	
		preorder(n->left);
		preorder(n->right);
	}
}

void RBTree::displayTree(){
	int ch;
	cout<<"\nSelect the type of tree traversal: \n";
	cout<<"1. PRE-ORDER\n2. IN-ORDER\n3. POST-ORDER\n::";	
	cin>>ch;
	switch(ch){
		case 1: this->preorder(this->root);
			break;
		case 2: this->inorder(this->root);
			break;
		case 3: this->postorder(this->root);
			break;		
		default: cout<<"Wrong choice.";
	}
}

#endif
