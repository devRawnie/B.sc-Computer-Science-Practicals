#include<iostream>
using namespace std;
class node{
	public:
	int info;
	node* next;
	 node()
	 {
	 	info = 0;
	 	next = 0;
	 }
	 node(int a)
	 {
	 	info = a;
	 	next = 0;
	 }
	 
};
class Stack{
	node* top;
	public:
		Stack()
		{
			top = 0;
		}
		void push(int a)
		{
			node *p = new node(a);
			if(top == 0)
			{
				top = p;
			}
			else
			{
				p->next = top;
				top = p;
			}
			
				}		
	int pop()
	{
		if(top == 0)
		{	
				cout<<"\nStack is empty!!\n";
				return -1;
				}
		else
		{
			node *temp = top;
			int a = temp->info;
			top = top->next;
			delete temp;
			return a;
		}
			
	}
	void clearStack()
	{
		node *temp;
		while(top!=0)
		{
			temp = top;
			cout<<"\nDeleting "<<top->info;
			top = top->next;
			delete temp;
		}
		
	}
	void display()
	{
		
		node *q = top;
		cout<<"\nStack now is: ";
		while(q!=0)
		{
			cout<<"-> "<<q->info<<endl;
			q = q->next;
		}
	}
};
int main()
{	int s,ch,info;
	Stack obj;
	beg:
	cout<<"Choose from the following: \n";
	cout<<"1. Push \n";
	cout<<"2. Pop \n";
	cout<<"3. Clear \n";
	cout<<"4. Display \n";
	cout<<"5. Quit:  ";
	cin>>ch;
	switch(ch)
	{
		case 1: cout<<"\nEnter the information: ";
				cin>>info;
				obj.push(info);
				break;
		case 2: info = obj.pop();
				if(info > 0)
					cout<<"Deleting "<<info;
				break;
		case 3: obj.clearStack();
				cout<<"\nStack is now empty";
				break;
		case 4: obj.display();
				break;
		case 5: return 0;
		default: cout<<"Wrong choice";
	}
	ch = 0;
	cout<<"\nPress 1 to repeat: ";
	cin>>ch;
	if(ch==1)
		goto beg;

	return 0;
}
