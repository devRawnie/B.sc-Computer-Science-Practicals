#include<iostream>
using namespace std;
template<class t>
class dllnode{
	public: 
	t info;
	dllnode<t> *next;
	dllnode<t> *prev;

	
	dllnode()
	{
		info = 0;
		prev =0;
		next = 0;
	}
	dllnode(t data)
	{
		info = data;
		prev =0;
		next = 0;
	}
	
};
template<class t>
class dll_list{
	dllnode<t> *head, *tail;
	public:
		dll_list()
		{
//		head->prev = tail->prev = 0;
//		head->next = tail->next = 0;
		head =0;
		 tail =0;
		
		}
//		void deleteList()
//		{
//			dllnode<t> *q, *p;
//			q = head;
//			while(q!=0)
//			{
//				p = q;
//				delete p;
//				q = q->next;
//			}
//		}
	void display()
	{
		cout<<endl;
		if(head==0 || tail==0)
			cout<<"Empty list";
		else{
		dllnode<t> *q;
		 q = head;
		 while(q!=0)
		{
			cout<<q->info<<"->";
			q = q->next;
		}
	}
	}

void insertAtBeg(t a)
	{
		dllnode<t> *p;
		p = new dllnode<t>(a);
		if(head == 0)
			{
			head = p;
			tail = p;
			
			}
		else
		{
			p->next = head;
			head->prev = p;
			head = p;
		}
			}

void insertAtEnd(t a)
		{
			dllnode<t> *p;
			p = new dllnode<t>(a);
			if(tail==0)
				{
					
					head = tail = p;
				}
			else{
				tail->next = p;
				p->prev = tail;
				tail = p;
			}
		}

void insertAfter(t a,t b)
{
	dllnode<t> *p;
	p = new dllnode<t>(a);	
	if(head==0)
	{
		head = tail = p;
	}
	else if(b == tail->info)
	{
	tail->next = p;
	p->prev = tail;
	tail = p;
	}
	else
	{
		dllnode<t> *q, *temp;
		q = head;
		temp = 0;
		while( q!=0 && q->info!=b )
		{
			q = q->next;	
		}
	
	if(q!=0 && q->info==b)
	{	
		temp = q->next;		
		p->prev = q;
		p->next = temp;
		temp->prev = p;
		q->next = p;
}
else{
	cout<<"Element "<<b<<"  not found!!";
}
	}
	
}
void insertBefore(t a, t b)
{
	dllnode<t> *p;
	p = new dllnode<t>(a);	
	if(head==0)
	{
		head = tail = p;
	}
	else if(b == head->info)
	{
		p->next = head;
			head->prev = p;
			head = p;
	}
	
	else
	{   dllnode<t> *q, *temp;
		q = head;
		temp = 0;
		while( q!=0 && q->info!=b )	
		{
			q = q->next;
		}
		
		if(q!=0 && q->info==b)
		{
			temp = q->prev;
			temp->next = p;
			p->prev = temp;
			p->next = q;
			q->prev = p;
		}
	else{
		cout<<"Element "<<b<<"  not found!!";
	}
	}
}
void deleteBeg()
{
	if(head==0 || tail==0)
		cout<<"The list is empty!!";
	else if(head==tail)
		{
//			cout<<"\nfirst else\n";
			delete head;
			head = tail = 0;
		}
	else
		{	
//			cout<<"\nsecond else\n";
			dllnode<t> *q = head;
			head = head->next;
			head->prev = 0;
			delete q;
		}
}
void deleteEnd()
{
	if(head==0||tail==0)
		cout<<"\nList is EMPTY!!";
	else if(head == tail)
		{
			delete head;
			head = tail = 0;
		}
	else
		{	dllnode<t> *q;
			q = tail;
			tail = tail->prev;
			tail->next = 0;
			delete q;
		}
}
void deleteParticular(t b)
{
	if(head==0 || tail == 0)
		cout<<"The list is empty!!";
	else if(head->info == b)
		{
			deleteBeg();
		}
	else if(tail->info == b)
	{
		deleteEnd();
	}
	else
	{	dllnode<t> *q, *temp1, *temp2;
		q = head;
		while(q!=0 && q->info!=b)
			{
			cout<<endl<<q->info;
			q = q->next;
		}
		if(q!=0 && q->info==b)
			{
				temp1 = q->prev;
				temp2 = q->next;
				temp1->next = temp2;
				temp2->prev == temp1;
				delete q;
				
			}
		else
			cout<<"\nElement not found!!";
	}
}
void search(t b)
{
	if(head->info == b)
		cout<<"Element found at the beginning.";
	else if(tail->info ==b)	
		cout<<"Element found at the end.";
	else{
		dllnode<t> *q = head;
		t count = 1;
		while(q!=0 && q->info!=b)
		{	count++;
			q = q->next;
		}
		if(q!=0 && q->info==b)
			cout<<"\nElement found at pos: "<<count;
	}
}
void reversal()
{
//	dllnode<t> *p,*q,*r;
//	p = head;
//	q = p->next;
//	r = q->next;
//	p->next = 0;
//	while(q->next!=0)
//	{
//		q->next = p;
//		p = q;
//		q = r;
//		r = r->next;
//	}
//	q->next = p;
//	//for reversing from end
//	p =	tail;
//	q = p->prev;
//	r = q->prev;
//	p->prev = 0;
//	while(q->prev!=0)
//	{
//		q->prev = p;
//		p = q;
//		q = r;
//		r = r->prev;
//	}	
//	q->prev = p;
//p = head;
//head = tail;
//tail = p;
dllnode<t> *temp, *q;
temp = 0;
q = head;
while(q!=0)
{
	
	temp = q->prev;
	q->prev = q->next;
	q->next = temp;
	q = q->prev;
}

temp = head;
head = tail;
tail = temp;
//if(temp!=0)
//	head = temp;
//cout<<"\n\nhead->info"<<head->info;
}

};
int main()
{
	dll_list<int> ob;
	char c;
	int ch,temp,b;
	do{
		route:
	cout<<"\nEnter your choice: ";
	cout<<"\n1. Add a node.";
	cout<<"\n2. Delete a node.";
	cout<<"\n3. Search for an element";
	cout<<"\n4. Reverse the linked list.\n: ";
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
					case 1: ob.insertAtBeg(temp);
							break;
					case 2: ob.insertAtEnd(temp);
							break;
					case 3: cout<<"\nEnter the node\'s information after which, new node is to be inserted: ";
							cin>>b;
							ob.insertAfter(temp,b);
							break;
					case 4: cout<<"\nEnter the node\'s information before which, new node is to be inserted: ";
							cin>>b;
							ob.insertBefore(temp,b);
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
					case 2: ob.deleteEnd();
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
				ob.search(temp);
				ob.display();
				break;
		case 4: ob.reversal();
				ob.display();
				break;
		default: cout<<"Wrong choice.";
				 goto route;
	}

cout<<"\nPress any button to continue('n' to quit)";
cin>>c;
}while(c!='n');
return 0;
}
