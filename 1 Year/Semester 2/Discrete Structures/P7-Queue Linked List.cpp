#include<iostream>
using namespace std;
class node{
	public:
		int info;
		node *next;
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
class Queue{
	
	node *head, *tail;
	public: 
	Queue()
	{
		head = tail = 0;
	}
	bool isempty()
	{
		if(head == 0)
		{
			//cout<<"\nEMPTY QUEUE";
			return true;
		}
			
			
		else
			return false;
	}
	void enqueue(int b)
	{
		node *p = new node(b);
		if(isempty())
			head = tail = p;
		else
		{
			tail->next = p;
			tail = p;
		}
	}
	void dequeue()
	{
		if(isempty())
			{
				cout<<"\nEMPTY QUEUE\n";
			}
		else{
		node *temp = head;
		cout<<"\nDeleting: "<<head->info;
		head = head->next;
		delete temp;	
}
	}
	void display()
	{
		if(isempty())
		{
			cout<<"\nEMPTY QUEUE\n";
		}
		else
		{
		cout<<"\n\nThe queue is: ";
		node *q = head;
		while(q!=0)
		{
			cout<<q->info<<"->";
			q = q->next;
		}
	}
	
	}
};
void lineBreak(char c)
{
	cout<<endl;
	int i = 81;
	while(--i != 0)
		cout<<c;
}
int main()
{
	Queue q;
	int ch,temp;
	char c = '*';
	start:
	cout<<"\nEnter your choice: \n";
	cout<<"1. Add an element\n";
	cout<<"2. Delete an element\n";
	cout<<"3. Display Queue\n";
	cout<<"4. Exit .. ";
	cin>>ch;
	switch(ch)
	{
		case 1: lineBreak(c);
				cout<<"\nEnter the information of element: ";
				cin>>temp;
				q.enqueue(temp);
				q.display();
				lineBreak(c);
				break;
		case 2: q.dequeue();
				lineBreak(c);
				break;
		case 3: q.display();
				lineBreak(c);
				break;
		case 4:	return 0;
		default: cout<<"Wrong choice";
	}
	goto start;
	return 0;
}
