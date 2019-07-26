#include<iostream>
using namespace std;
template <class t>
class llnode{
	public:
	t info;
	llnode<t>* next;
	llnode<t>()
	{
		cout<<"\n!\n";
		info = 0;
		next  = 0;
	}
	llnode<t>(t a)
	{
//		cout<<"\n+\n";
		info = a;
		next = 0;
	}
//	~llnode<t>()
//	{
//		cout<<"\n--\n";
//	
//	}	
	
	
};
template <class t>
class Circular{
	llnode<t>  *tail;
	public:
		Circular()
		{
			tail = 0;		
		}
		~Circular()
		{
			if(tail!=0)
			{
				llnode<t> *q = tail->next;
				llnode<t> *p = q->next;
				while(p!=tail)
				{
					delete q;
					q = p;
					p=p->next;
				}
				delete p;
				delete q;
				tail = 0;
				
			}
			cout<<"deleted";
		}
void insertBeg(t a)
	{
		llnode<t> *p = new llnode<t>(a);
	
		if(tail==0)
		{
			tail = p;	
			tail->next = tail;					
		}
		else
		{
			p->next = tail->next;
			tail->next = p;
		}
	}
void insertEnd(t a)
{
	llnode<t> *p = new llnode<t>(a);
	
	if(tail==0)
		{
		tail = p;
		tail->next = p;
		}
	else
	{
		p->next = tail->next;
		tail->next = p;
		tail = p;
	}
}
void display()
{
if(tail == 0)
	cout<<"\n EMPTY LINKED LIST";
else if(tail->next == tail)
	cout<<tail->info<<"->";
else{
	cout<<endl;
	llnode<t>* q = tail->next;
	do{	
		cout<<q->info<<"->";
		q= q->next;	
	}while(q!=tail);
	cout<<q->info<<"->";			//for printing the last element
}
}
void insertAfterParticular(t a, t b)
{
	llnode<t> *p = new llnode<t>(a);
	if(tail == 0)
	{
tail = p;
tail->next = tail;
	}
	else if(tail->info == b)
		{
			delete p;
			insertBeg(a); 	//check this
			
		}
	else
	{
	llnode<t> *q;
	q = tail;
	while(q->next!=tail && q->info!=b)
		q = q->next;
	if(q->info==b)
	{
		p->next = q->next;
		q->next = p;
	}
	else{
		cout<<"\nElement not found";
	}
	}}

void insertBeforeParticular(t a, t b)
{
	llnode<t> *p = new llnode<t>(a);
	if(tail == 0)
	{
		tail = p;
		tail->next = p;
	}
	
	else
	{
	llnode<t> *q, *temp;
	q = tail;
	
		do{	temp = q;
			q = q->next;
		}while(q!=tail && q->info!=b );
//		t tempInfo = tail->info;
//	if(tempInfo==b)
	if(q->info==b )
	{	
		p->next = temp->next;
		temp->next = p;
	}
	else{
		cout<<"\nElement not found";
	}
	}
}
void deleteBeg()
{
	llnode<t> *q;
	if(tail==0)
		cout<<"Empty linked list";	
	else if(tail->next == tail)
	{
		delete tail;
		tail = 0;
	}
	else{
		q = tail->next;
		tail->next = q->next;
		delete q;
	}
		 } 
void deleteLast()
{
	if(tail == 0 )
		cout<<"Empty linked list";
	else if(tail->next == tail)
	{
		delete tail;
		tail = 0;
	}
	else
	{
		llnode<t> *q = tail;
		while(q->next!=tail)
			q = q->next;
		llnode<t> *temp = tail;
		q->next = temp->next;
		tail = q;
		delete temp;
		
		
	}
}
void deleteParticular(t b)
{
	
	if(tail->info == b)
		{
			deleteBeg();
		}
	else
	{
		llnode<t> *q = tail->next;
		llnode<t> *temp;
			do{
				temp = q;
				q = q->next;
			}while(q!=tail && q->info!=b);
		
		if(q->info == b)
		{
			temp->next = q->next;
			delete q;
		}
		
	}
}
t search(t a)
{
	t pos;

		pos = 0;
	if((tail->next)->info == a)
		pos = 1;
	else{
		llnode<t> *q = tail->next;
		pos = 1;
			do{
				q = q->next;
				pos++;
			}while(q!=tail && q->info != a);

		if(q->info == a)
			return pos;
		else
			{
			cout<<"\nElement not found!!";
			return -1;
			}
		
	}
	return pos;
}
void reversal()
{
	llnode<t> *prev, *curr, *next, *q;
	prev = 0;
	curr = tail;
	next = 0;
	do{
	next = curr->next;
	curr->next = prev;
	prev = curr;
	curr = next;
	}while(curr!=tail);
	tail->next = prev;
	
	q = tail;
	do{
		q = q->next;
	}while(q->next!=tail);
	curr = tail;
	tail = q;
	tail->next = curr;
}


};
void prtN(char c, int n)
{
	cout<<endl;
	while(n!=0)
	{
		cout<<c;
		n--;
	}
}
int main()
{
	Circular<int> ob;
	int ch, temp,b;
	route:
	prtN('*',120);
cout<<"\nEnter your choice: ";
	cout<<"\n1. Add a node.";
	cout<<"\n2. Delete a node.";
	cout<<"\n3. Search for an element.";
	cout<<"\n4. Reverse the linked list. ";
	cout<<"\n5. Quit:   ";
	cin>>ch;
	switch(ch)
	{
		case 1: cout<<"\n1. Add a node in the beginning.";
				cout<<"\n2. Add a node in the end.";
				cout<<"\n3. Add a node after a node";
				cout<<"\n4. Add a node before a node.\n: ";
				cin>>ch;
				cout<<"Enter the information of the node: ";
				cin>>temp;
				switch(ch)
				{
					case 1: ob.insertBeg(temp);
							break;
					case 2: ob.insertEnd(temp);
							break;
					case 3: cout<<"\nEnter the node\'s information after which, new node is to be inserted: ";
							cin>>b;
							ob.insertAfterParticular(temp,b);
							break;
					case 4: cout<<"\nEnter the node\'s information before which, new node is to be inserted: ";
							cin>>b;
							ob.insertBeforeParticular(temp,b);
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
					case 1: ob.deleteBeg();
							break;
					case 2: ob.deleteLast();
							break;
					case 3: cout<<"Enter the information of the node: ";
							cin>>temp;
							ob.deleteParticular(temp);
							break;
					default: cout<<"Wrong choice.";
								goto route;
				}
				ob.display();
				break;
		case 3: cout<<"Enter the information of the node: ";
				cin>>temp;
				b = ob.search(temp);
				if(b!= -1)
					cout<<"\nElement found at pos: "<<b;
				else
					cout<<"\nElement not found!!";
				ob.display();
				break;
		case 4: ob.reversal();
				ob.display();
				break;
		case 5: return 0;
		default: cout<<"Wrong choice.\n";
				 }
		 goto route;
	return 0;
}
