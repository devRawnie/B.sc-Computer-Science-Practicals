#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

enum COLOR{RED,BLACK};

class RBTnode{
	public:
		int data;
		enum COLOR color;
		RBTnode *left,*right,*parent;
		RBTnode(int data){
			this->data=data;
			left=NULL;
			right=NULL;
			parent=NULL;
			color=RED;
		}
};

class RedBlackTree{
	RBTnode *root;
	public:
		RedBlackTree(){
			root=NULL;
		}
		void insert(int val){
			if(root==NULL){
				root=new RBTnode(val);
				root->color=BLACK;
			}
			else{
				RBTnode *p=new RBTnode(val),*q,*r;
				for(q=root;q!=NULL;){
					r=q;
					if(val<q->data)
						q=q->left;
					else
						q=q->right;
				}
				if(val<r->data)
					r->left=p;
				else
					r->right=p;
				p->parent=r;
				fix(p);	
			}
		}
		
		void fix(RBTnode *at){
			if(at->parent->color==BLACK)
				return;
			
			RBTnode *parent=at->parent,*grandParent=parent->parent,*uncle;
				
			//finding uncle
			if(grandParent->left==parent)
				uncle=grandParent->right;
			else
				uncle=grandParent->left;	
				
			if(uncle==NULL || uncle->color==BLACK){
				if(grandParent->left==parent && parent->left==at)
					rotateRight(parent,true);
				else if(grandParent->right==parent && parent->right==at)
					rotateLeft(parent,true);
				else if(grandParent->left==parent && parent->right==at)
					rotateLeft(at,false), rotateRight(at,true);
				else if(grandParent->right==parent && parent->left==at)
					rotateRight(at,false), rotateLeft(at,true);
			}
			else if(uncle->color==RED){
				flipColor(parent);
				flipColor(uncle);
				if(grandParent!=root){
					flipColor(grandParent);
					fix(grandParent);
				}
			}
		}
		
		void flipColor(RBTnode *node){
			if(node->color==RED)
				node->color=BLACK;
			else
				node->color=RED;
		}
		
		void rotateLeft(RBTnode *at, bool changeColor){
			RBTnode *parent=at->parent,*grandParent=parent->parent;
			parent->right=at->left;
			parent->parent=at;
			at->left=parent;
			at->parent=grandParent;
			if(grandParent!=NULL){
				if(grandParent->left==parent)
					grandParent->left=at;
				else
					grandParent->right=at;
			}
			if(parent==root)
				root=at;
			if(changeColor){
				flipColor(at);
				flipColor(parent);
			}
		}
		
		void rotateRight(RBTnode *at, bool changeColor){
			RBTnode *parent=at->parent,*grandParent=parent->parent;
			parent->left=at->right;
			parent->parent=at;
			at->right=parent;
			at->parent=grandParent;
			if(grandParent!=NULL){
				if(grandParent->left==parent)
					grandParent->left=at;
				else
					grandParent->right=at;
			}
			if(parent==root)
				root=at;
			if(changeColor){
				flipColor(at);
				flipColor(parent);
			}
		}
		
		void print(){
			if(root==NULL)
				return;
			queue<RBTnode *>q1;
			queue<RBTnode *>q2;
			q1.push(root);
			while(!q1.empty() || !q2.empty()){
				RBTnode *p=q1.front();
				q1.pop();
				cout<<p->data<<"("<<p->color<<") ";
				if(p->left!=NULL)
					q2.push(p->left);
				if(p->right!=NULL)
					q2.push(p->right);
				if(q1.empty()){
					cout<<endl;
					q1=q2;
					queue<RBTnode *>q3;
					q2=q3;
				}
			}
		}	
		
		string getColor(int val){
			RBTnode *p=find(val);
			if(p==NULL)
				return "\nNode not found";
			else
				return p->color==BLACK?"Black":"Red";
		}
		
		COLOR getNodeColor(RBTnode *node){
			if(node==NULL)
				return BLACK;
			return node->color;
		}
		
		RBTnode* find(int val){
			RBTnode *p=root;
			while(p!=NULL){
				if(p->data==val)
					return p;
				if(p->data>val)
					p=p->left;
				else
					p=p->right;
			}
			return p;
		}
		
		void del(int val){
			//find smallest in right subtree and replace it with the node to be deleted, now the node to be deleted has either no child or 1 child.
			RBTnode *p=find(val);
			if(p==NULL)
				return;
			if(p->left!=NULL && p->right!=NULL){
				RBTnode *r=p->right;
				while(r->left!=NULL)
					r=r->left;
				p->data=r->data;
				p=r;
			}
			delNode(p);
		}
		
		void delNode(RBTnode *node){
			RBTnode *parent=node->parent;
			//either node is red or if it is black then it has a red child
			if((node->color==RED) || getNodeColor(node->left)==RED || getNodeColor(node->right)==RED)
				setParent(node,parent), delete(node);
			else
				fix2(node), setParent(node,parent), delete(node);
		}
		
		void setParent(RBTnode *child, RBTnode *parent){
			if(parent==NULL)
				{root=NULL; return;}
			if(parent->left==child){
				if(child->left!=NULL)
					parent->left=child->left, parent->left->color=child->color;
				else if(child->right!=NULL)
					parent->left=child->right, parent->left->color=child->color;
				else
					parent->left=NULL;
			}
			else{
				if(child->left!=NULL)
					parent->right=child->left, parent->right->color=child->color;
				else if(child->right!=NULL)
					parent->right=child->right, parent->right->color=child->color;
				else
					parent->right=NULL;
			}
		}
		
		//* - terminating case
		void fix2(RBTnode *doubleBlackNode){
			//(case 1)*
			if(doubleBlackNode==root)
				return;
			RBTnode *parent=doubleBlackNode->parent,*sibling;
			//finding sibling
			if(parent->left==doubleBlackNode)
				sibling=parent->right;
			else
				sibling=parent->left;
			//sibling red, parent and sibling's child are black (case 2)
			if(getNodeColor(parent)==BLACK && getNodeColor(sibling)==RED && getNodeColor(sibling->left)==BLACK && getNodeColor(sibling->right)==BLACK){
				if(parent->right==sibling)
					rotateLeft(sibling,true);
				else
					rotateRight(sibling,true);
				fix2(doubleBlackNode);
			}
			//parent, sibling and its child are all black (case 3) 
			else if(getNodeColor(parent)==BLACK && getNodeColor(sibling)==BLACK && getNodeColor(sibling->left)==BLACK && getNodeColor(sibling->right)==BLACK){
				sibling->color=RED;
				fix2(parent);
			}
			//parent red and sibling and its child black (case 4)*
			else if(getNodeColor(parent)==RED && getNodeColor(sibling)==BLACK && getNodeColor(sibling->left)==BLACK && getNodeColor(sibling->right)==BLACK)
				flipColor(parent), flipColor(sibling);
			//parent is black, sibling is black, sibling has one red children which is not in same direction, other child is black (case 5)
			else if(getNodeColor(parent)==BLACK && getNodeColor(sibling)==BLACK && ((parent->left==sibling && getNodeColor(sibling->left)==BLACK && getNodeColor(sibling->right)==RED) || (parent->right==sibling && getNodeColor(sibling->right)==BLACK && getNodeColor(sibling->left)==RED))){
				//make it (case 6)
				if(parent->right==sibling)
					rotateRight(sibling->left,true);
				else
					rotateLeft(sibling->right,true);
				fix2(doubleBlackNode);
			}
			//sibling is black and has red child in same direction, parent's color and other sibling child color doesn't matter (case 6)* 
			else if(getNodeColor(sibling)==BLACK && ((parent->right==sibling && getNodeColor(sibling->right)==RED) || (parent->left==sibling && getNodeColor(sibling->left)==RED))){
				if(parent->right==sibling){
					rotateLeft(sibling,false);
					//red sibling gets black
					sibling->right->color=BLACK;
				}
				else{
					rotateRight(sibling,false);
					sibling->left->color=BLACK;
				}
				//sibling gets the color of parent and parent get black
				sibling->color=parent->color;
				parent->color=BLACK;
			} 
		} 
};

int main(){
	char choice;
	RedBlackTree rbt;
	do{
		cout<<"1. Insert\n2. Delete\n3. Display\n4. Check color of a node\n\nEnter choice : ";
		int ch;
		cin>>ch;
		int n;
		switch(ch){
			case 1:
				cout<<"\nEnter element : ";
				cin>>n;
				rbt.insert(n);
				break;
			case 2:
				cout<<"\nEnter value to delete : ";
				cin>>n;
				rbt.del(n);
				break;
			case 3:
				rbt.print();
				cout<<endl;
				break;
			case 4:
				cout<<"Enter the node value : ";
				cin>>n;
				cout<<rbt.getColor(n);
				break;
			default:
				cout<<"Wrong Choice";
				break;
		}
		cout<<"\nDo you want to continue? (Y/N) - ";
		cin>>choice;
	}while(choice=='y'||choice=='Y');
}
