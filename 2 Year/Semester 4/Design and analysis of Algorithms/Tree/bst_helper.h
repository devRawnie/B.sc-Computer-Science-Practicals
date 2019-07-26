#ifndef _BINARY_SEARCH_TREE_HELPER_H
#define _BINARY_SEARCH_TREE_HELPER_H
#include "tree_helper.h"
class BST: public TreeHelper{
	public:
		BST() : TreeHelper(){
		}
		BST(int d) : TreeHelper(d){
		}
		int addNodeInTree(node* n, int data);
		void insert(int data);
};
void BST::insert(int data){
	this->addNodeInTree(this->root, data);
}
int BST::addNodeInTree(node* n , int data){
{ 
	    /* If the tree is empty, return a new n */
    if (n == NULL) return new node(data); 
  
    /* Otherwise, recur down the tree */
    if (data < n->data) 
        n->left  = insert(n->left, data); 
    else if (data > n->data) 
        n->right = insert(n->right, data);    
  
    /* return the (unchanged) n pointer */
    return n; 
}

#endif
