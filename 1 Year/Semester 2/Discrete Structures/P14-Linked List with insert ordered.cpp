#include<iostream>
using namespace std;
template <class t>
class llnode{
public:	t info;
	llnode<t> *next;
	
		llnode<t>(t s)
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
		cout<<"\n\n";
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
	cout<<endl;}
void addElementBeg(t a)
	{
		llnode<t> *p;
		p = new llnode<t>(a);
			p->next = head;
			head = p;
		
	}

	void addElementLast(t a)
	{
		llnode<t> *p;
		p = new llnode<t>(a);
			tail->next = p;
			tail = p;
		
		
		}

	void addAfterNode(t a,t b)
	{
		llnode<t> *p, *q;
		p = new llnode<t>(a);
		q = head;
		while(q->info!=b && q!=NULL)
		{
			q = q->next;
		}
		if(q->info==b)
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


void insertOrder(t a)
{
	llnode<t> *q, *temp;
	q = head;
	if(head==0)
		{
		llnode<t> *p = new llnode<t>(a);
		head = tail = p;
	}
	else
	{
		if(a<q->info)
			addElementBeg(a);
		else if(a > tail->info)
			addElementLast(a);
		else
		{
			while(q->info < a)
			{	temp = q;
				q = q->next;
			}
			llnode<t> *p = new llnode<t>(a);
			p->next = q;
			temp->next = p;
		}
	}
}

void deleteElement(t a)
{
	
	llnode<t> *q = head;
	llnode<t> *temp;
	while(q!=0 && q->info!=a)
	{
	temp = q;
	q = q->next;
	}
	if(q->info == a)
	{
	
	cout<<"Deleting "<<q->info;
	temp->next = q->next;
	delete q;
		}
	else
		cout<<"\nElement not found!!";	
		
}
void merge(llist temp)
{
	llnode<t> *objList = temp.head;
	while(objList!=0)
	{
		this->insertOrder(objList->info);
		objList = objList->next;
	}
	this->display();
}
};
int main()
{
int temp;
llist<int> ob;
llist<int> ob2;
int ch, ele;
beg:
	cout<<"\nEnter your choice: ";
	cout<<"\n1. Add Element.";
	cout<<"\n2. Delete Element.";
	cout<<"\n3. Merge Lists.";
	cout<<"\n4. Quit: ";
	cin>>ch;
	switch(ch)
	{
		case 1: cout<<"Enter information of element: ";
				cin>>ele;
				ob.insertOrder(ele);
				goto beg;
				break;
		case 2: cout<<"Enter the element to delete: ";
				cin>>ele;
				ob.deleteElement(ele);
				goto beg;
				break;
		case 3: cout<<"Enter the second list: ";
				secondBeg:
					cout<<"\n1. Add element\n2.Stop : ";
					cin>>ch;
					if(ch==1)
					{
						cout<<"Enter the information of element: ";
						cin>>ele;
						ob2.insertOrder(ele);
						goto secondBeg;
					}
					else
						ob.merge(ob2);
					
					ob.display();
					goto beg;
					break;
	case 4: return 0;
			break;
	default: cout<<"Wrong choice: ";
			 goto beg;
		}

//do{
//	cout<<"\nEnter an element: ";
//	cin>>temp;
//	ob.insertOrder(temp);
//	cout<<"\n\nList is: ";
//	ob.display();
//	cout<<"\nPress y to repeat\nPress n to quit: ";
//	cin>>ch;
//}while(ch!='n');
	return 0;
}
