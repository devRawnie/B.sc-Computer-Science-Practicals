	#include<iostream>
using namespace std;
class llnode{
public:	int power, coeff;
	llnode* next;
		llnode()
		{
			power = coeff = 0;
			next = 0;
		}
		llnode(int p, int c)
		{	
			power = p;
			coeff = c;
			next = 0;
		}
		
};
class llist{
	llnode *head, *tail;
	public:
	llist()
	{
		head = tail = 0;
	}
void addElementBeg(llnode *P)
	{		P->next = head;
			head = P;
	}

	void addElementLast(llnode *P)
	{		tail->next = P;
			tail = P;		
		}

void display()
{
		//cout<<"HERE";
		if(head==0)
			cout<<"Empty list";
		else{
		llnode *q;
		q = head;
		while(q!=0)
		{
			if(q->power != 0 && q->next!=0)
				cout<<q->coeff<<"x^"<<q->power<<" + ";
			else if(q->power == 0)
				cout<<q->coeff<<" ";
			else
				cout<<q->coeff<<"x^"<<q->power;
			q = q->next;
		}
	}	}
void getValues()
{
	int p, c;
	cout<<"\nEnter the power: ";
	cin>>p;
	cout<<"\nEnter the coeff: ";
	cin>>c;
	//insertOrder(p,c);
	llnode *x = new llnode(p,c);
	addElementBeg(x);
	sort();
}

void sort()
{
	llnode *x,*q;
	q = head;
	int temp;
	while(q->next!=0)
	{
		x = q->next;
		while(x!=0)
		{
			if(q->power < x->power)
			{
				temp = q->power;
				q->power = x->power;
				x->power = temp;
				temp = q->coeff;
				q->coeff = x->coeff;
				x->coeff = temp;
			}
				x = x->next;	
		}
		q = q->next;
	}
}
void addPolynomials(llist A, llist B)
{
//	cout<<"\n\n";
//	A.display();
//	B.display();
	int flag = 0;
	int tempSum, tempPowA;
	llnode *tempA = A.head;
	llnode *tempB = B.head;
	while(tempA != 0)
	{
		tempPowA = tempA->power;
		//cout<<"POW :"<<tempPowA;
		tempB = B.head;
		while(tempB != 0)
		{
			//cout<<"\n comparing with pow: "<<tempB->power;
			if(tempPowA == tempB->power)
			{
				//cout<<"\nAdding term for pow: "<<tempPowA;
				tempSum = tempA->coeff + tempB->coeff;
				llnode *x = new llnode(tempPowA, tempSum);
				this->addElementBeg(x);
				flag = 1;
				break;
			}
			tempB = tempB->next;
		}
		if(flag == 0)
		{
			llnode *x = new llnode(tempA->power, tempA->coeff);
				this->addElementBeg(x);
		}
	tempA = tempA->next;
	}
	this->sort();
	cout<<"\nThe resultant polynomial is: ";
	this->display();
}
};
int main()
{
	int ch = 0;
llist p1,p2;
cout<<"\nEnter polynomial 1: ";
startp1:
cout<<"\nChoose an option: \n ";
cout<<"1. Add term\t\t";
cout<<"2. Stop:  ";
cin>>ch;
if(ch==1)
	{
	p1.getValues();
	goto startp1;}
ch = 0;
cout<<"\nEnter polynomial 2: ";
startp2:
cout<<"\nChoose an option: \n ";
cout<<"1. Add term\t\t";
cout<<"2. Stop:  ";
cin>>ch;
if(ch==1)
	{
	p2.getValues();
	goto startp2;}
cout<<"\nP1: ";
p1.display();
cout<<"\nP2: ";
p2.display();	
llist sum;
sum.addPolynomials(p1,p2);
return 0;
}
