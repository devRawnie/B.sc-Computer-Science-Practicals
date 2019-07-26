#include<iostream>
#include "rbTree.h"

int main()
{
	RBTree tree;
	tree.insertNode(10);
	tree.insertNode(20);
	tree.insertNode(5);
	tree.insertNode(6);
	tree.insertNode(11);
	tree.displayTree();
	return 0;
}
