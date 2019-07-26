#ifndef _TREE_HELPER_H
#define _TREE_HELPER_H
#include <cstddef>
#include<iostream>
using namespace std;
struct treeNode{
	int data;
	struct treeNode* left;
	struct treeNode* right;
	treeNode(){
		this->left = NULL;
		this->right = NULL;
	}
	treeNode(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

class TreeHelper{
	protected:
	struct treeNode* root;
	int height;
	public:
	void inorder(treeNode* n);
	void postorder(treeNode* n);
	void preorder(treeNode* n);
	int getHeight();
		TreeHelper()
		{
			root = NULL;
		}
		TreeHelper(int data){
			root = new treeNode(data);
		}
	
//	virtual int addtreeNodeInTree(treeNode* n, int data) = 0;
	void displayTree();
};

int TreeHelper::getHeight(){
	return this->height;
}

void TreeHelper::postorder(treeNode* n){
	if(n!=NULL){
		postorder(n->left);
		postorder(n->right);
		cout<<n->data<<" ";	
	}
}

void TreeHelper::inorder(treeNode* n){
	if(n!=NULL){
		inorder(n->left);
		cout<<n->data<<" ";
		inorder(n->right);
	}
}

void TreeHelper::preorder(treeNode* n){
	if(n!=NULL){
		cout<<n->data<<" ";	
		preorder(n->left);
		preorder(n->right);
	}
}

void TreeHelper::displayTree(){
	int ch;
	cout<<"\nSelect the type of tree traversal: \n";
	cout<<"1. PRE-ORDER\n2. IN-ORDER\n3. POST-ORDER\n::";	
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
