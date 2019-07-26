#include<iostream>
using namespace std;

template<class t>
class llnode{
public:	t info;
	llnode<t> *next;
	
		llnode(t s)
		{
			info = s;
			next =NULL;
		}
};
template <class t>
class llist{
	llnode<t> *head, *tail;
	public:
	llist()
	{
		head = tail = NULL;
	}
	void display()
	{
		cout<<endl;
		if(head==NULL)
			cout<<"Empty list";
		else{
		llnode<t> *q;
		 q = head;
		while(q!=NULL)
		{
			cout<<q->info<<"->";
			q = q->next;
		}
	}
	}
	void addElementBeg(t a)
	{
		llnode<t> *p;
		p = new llnode<t>(a);
		if(head==NULL)
		{
			head = p;
			tail = p;
		}
		else
		{
			p->next = head;
			head = p;
		}
	}
	void addElementLast(t a)
	{
		llnode<t> *p;
		p = new llnode<t>(a);
		if(head==NULL)
			{head = tail = p;
			}
		else{
			tail->next = p;
			tail = p;
		}
		
		}
	void addAfterNode(t a,t b)
	{
		llnode<t> *p, *q;
		p = new llnode<t>(a);
		q = head;
		while(q!=NULL && q->info!=b)
		{
			q = q->next;
		}
		if(q!=NULL && q->info!=b)
		{
			p->next = q->next;
			q->next = p;
			if(p->next==NULL)
				tail = p;
		}
		else
		{
			cout<<"\nElement not found!!";
		}
		
		
	}

	void addBeforeNode(t a,t b)
	{
		llnode<t> *p, *q, *temp;
		p = new llnode<t>(a);
		q = head;
		if(b==head->info)
	{
		p->next = head;
		head = p;
	}
	else{
	
		while(q!=NULL && q->info!=b )
		{
			temp = q;
			q = q->next;
		}
		if(q!=NULL && q->info!=b)
		{
			p->next = q;
			temp->next = p; 
		}
		else
			cout<<"\nElement not found!!";
	}
}

void deleteFromBeg()
{
	llnode<t> *q;
	q = head;
	if(head==NULL)
		delete head;
	else if(head==tail)
		{
			delete head;
			head = tail = NULL;
		}
	else
		{
			q = head;
			head = head->next;
			delete q;
		}
}
void deleteFromEnd()
{
	llnode<t> *q;
	q = head;
	if(head==NULL)
		delete head;
	else if(head==tail)
		{
			delete head;
			head = tail =NULL;
		}
	else
		{
			while(q->next!=tail)
			{
				q = q->next;
			}
			delete tail;
			tail = q;
			q->next = NULL;
			
		}
}
void deletePartiular(t b)
{
	if(head==NULL)
		delete head;
	else if(head==tail)
		{
			delete head;
			head = tail = NULL;
		}
		else{
			
			llnode<t> *q, *temp;
			q = head;
			while(q->info!=b && q!=NULL)
			{
				temp = q;
				q = q->next;
			}
			if(q->info==b)
			{
			temp->next = q->next;
			delete q;
			}
			else
				cout<<"Element "<<b<<" not found";
		}
}
void search(t b)
{
	llnode<t> *q;
	q = head;
	while(q!=0)
		{	if(q->info==b)
			{
			cout<<"\nELEMENT "<<q->info<<" found."<<endl;
			break;
	}
		q = q->next;	
	}	
	if(q==0)
			cout<<"\nElement "<<b<<" not found."<<endl;
}
void modify(t s, t b)
{
	llnode<t> *q;
	q = head;
	while(q!=0)
		{	if(q->info==b)
			{
			q->info = s;
			display();
			break;
	}
		q = q->next;	
	}
if(q==0)
			cout<<"\nElement "<<b<<" not found."<<endl;		
}


void sort()
{
	llnode<t> *p,*q;
	q = head;
	t temp;
	while(q->next!=NULL)
	{
		p=q->next;
		while(p!=0)
		{
			if(q->info>p->info)
			{
				temp = q->info;
				q->info = p->info;
				p->info = temp;
			}
				p = p->next;	
		}
		q = q->next;
	}
cout<<"\n\nSORTED LIST IS: \n";
}
void reversal()
{
	llnode<t> *p, *q, *r;
	p = head;
	q = p->next;
	r = q->next;
	p->next = 0;
	while(q->next!=0)
	{
		q->next = p;
		p = q;
		q = r;
		r = r->next;
	//cout<<"\nQ: "<<q<<"\nQ: "<<<<"\nR: "<<r;
	
	}
	q->next = p;
llnode<t> *temp;
temp = head;
head = tail;
tail = temp;
display();
}
void deleteList()
{
	llnode<t> *q, *p;
	q = head;
	if(q==0)
		return;
	while(q->next!=0)
		{
			p = q;
			q = q->next;
			delete p;
		}
	delete q;
	head = tail = 0;
	}	
	llist<t> concat(llist<t> ob2)
	{
		llist<t> temp;
		int num, x, i;
		cout<<"\nEnter the no of elements in second linked list: ";
		cin>>num;
		cout<<"\nEnter elements of second linked list: ";
		for(i=0;i<num;i++)
		{
			cin>>x;
			ob2.addElementLast(x);
		}		
		
		llnode<t> *p = this->head;
		while(p!=0)
		{
			temp.addElementLast(p->info);
			p = p->next;
		}
		p = ob2.head;
		while(p!=0)
		{
			temp.addElementLast(p->info);
			p = p->next;
		}
		
		return temp;
	}
	};
int main()
{
	newList:
	system("cls");
	llist<int> ob, ob1, ob2;
	char c;
	int ch,temp,b;
	do{
	route:
	cout<<"\nEnter your choice: ";
	cout<<"\n1. Add a node.";
	cout<<"\n2. Delete a node.";
	cout<<"\n3. Search for an element";
	cout<<"\n4. Modify a node.";
	cout<<"\n5. Sort the linked list.";
	cout<<"\n6. Reverse the linked list.\n: ";
	cout<<"\n7.Concatenate two linked list.\n";
	cin>>ch;
	switch(ch)
	{
		case 1: cout<<"\n1. Add a node in the beginning.";
				cout<<"\n2. Add a node in the end.";
				cout<<"\n3. Add a node after a node";
				cout<<"\n4. Add an node before a node.\n: ";
				cin>>ch;
				cout<<"Enter the information of the node: ";
				cin>>temp;
				switch(ch)
				{
					case 1: ob.addElementBeg(temp);
							break;
					case 2: ob.addElementLast(temp);
							break;
					case 3: 
							cout<<"\nEnter the node\'s information after which, new node is to be inserted: ";
							cin>>b;
							ob.addAfterNode(temp,b);
							break;
					case 4: 
							cout<<"\nEnter the node\'s information before which, new node is to be inserted: ";
							cin>>b;
							ob.addBeforeNode(temp,b);
							break;
					default: cout<<"Wrong choice.";
								goto route;
				}
				ob.display();
				break;
		case 2: cout<<"\n1. Delete first node.";
				cout<<"\n2. Delete last node.";
				cout<<"\n3. Delete a paricular node.";
				cin>>ch;
				switch(ch)
				{
					case 1: ob.deleteFromBeg();
							break;
					case 2: ob.deleteFromEnd();
							break;
					case 3: cout<<"Enter the information of the node: ";
							cin>>temp;
							ob.deletePartiular(temp);
							break;
					default: cout<<"Wrong choice.";
								goto route;
				}
				ob.display();
				break;
		case 3: cout<<"Enter the information of the node: ";
				cin>>temp;
				ob.search(temp);
				ob.display();
				break;
		case 4: cout<<"Enter the information of the node to be modified: ";
				cin>>b;
				cout<<"Enter the information of the new node: ";
				cin>>temp;
				ob.modify(temp,b);
				ob.display();
				break;
		case 5: ob.sort();
				ob.display();
				break;
		case 6: ob.reversal();
				ob.display();
				break;
		case 7: ob2 = ob.concat(ob1);	
				ob2.display();
				break;
		default: cout<<"Wrong choice.";
				 goto route;
	}

cout<<"\nEnter y to repeat\nEnter n to quit: ";
cin>>c;
}while(c!='n');
ob.deleteList();
ob1.deleteList();
ob2.deleteList();
	return 0;
}
