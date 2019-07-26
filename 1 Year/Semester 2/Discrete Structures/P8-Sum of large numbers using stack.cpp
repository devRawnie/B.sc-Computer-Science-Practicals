
/*
	Name: 
	Copyright: 
	Author: 
	Date: 15-10-18 10:36
	Description: Add some functionality to make the process of entering the numbers easy. 
					And display the numbers once they have been added
*/
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
		if(isEmpty())
		{	
				cout<<"\nStack is empty!!\n";
				return -1;
				}
		else
		{
			node *temp = top;
			int n = temp->info;
		//	cout<<"\n::"<<n<<endl;
			top = top->next;
			delete temp;
			return n;
		}
			
	}
		void display()
	{	node *q = top;
		while(q!=0)
		{
			cout<<q->info<<" ";
			q = q->next;
		}
	}
	bool isEmpty()
	{
		if(top==0)
			return true;
		else
			return false;
	}
void addStacks(Stack ob1, Stack ob2)
{
	int sum = 0, carry = 0;
	while((!ob1.isEmpty()) && (!ob2.isEmpty()))
	{
	sum = carry + ob1.pop() + ob2.pop();
	this->push(sum%10);
	carry = sum/10;
}
if(carry>0)
	this->push(carry);
if(!ob1.isEmpty())
{
	//cout<<"in1";
	while(!ob1.isEmpty())
		this->push(ob1.pop());
}
else if(!ob2.isEmpty())
{
//	cout<<"in2";
	while(!ob2.isEmpty())
		this->push(ob2.pop());
}
}

};
int main()
{
	Stack s1, s2, s3;
	int n=0, carry = 0;

	cout<<"\nEnter numbers digit by digit: (-1 to exit): \n";
	cout<<"\n Number 1: \n";
	for(int i=0;n!=-1;i++)
	{
		cin>>n;
		if(n!=-1)
			s1.push(n);		
	}
	n=0;
	cout<<"\n Number 2: \n";
	for(int i=0;n!=-1;i++)
	{
		cin>>n;
		if(n!=-1)
			s2.push(n);
	}
	//cout<<"\nNUMBER 1: "; s1.display();
	//cout<<"\nNUMBER 2: "; s2.display();	
	s3.addStacks(s1,s2);
	cout<<"\nSUM: ";    s3.display();
	
	return 0;
}

