#include<iostream>
#define size 20
using namespace std;
template <class t>
class QUEUE{
	public:
	t head, tail;
	t arr[size];
	QUEUE()
	{
		head = tail = -1;
		for(int i = 0;i<size;i++)
			arr[i] = 0;
	}
	bool isempty()
	{
		if(head == -1 || head > tail)
			{
				cout<<"EMPTY QUEUE";
				return true;
			}
		else
			return false;
	}
	bool isfull()
	{
		if((head==0 && tail == size -1) || (head == tail+1))
			{
				cout<<"FULL QUEUE";
				return true;
			}
		else 
			return false;	
		
	}
	void enqueue(t a)
	{
		if(isfull())
		{ }
		else
		{
			if(tail == size-1)
				tail = 0;
			else 
				{
					if(head == -1)
						head = 0;
				}
			
			arr[++tail] = a;
			
		}
	}
	void dequeue()
	{
		if(isempty())
		{}
		else
		{
	//	cout<<"\nhead: "<<head<<" tail: "<<tail<<endl;
		cout<<"Deleting "<<arr[head];
		arr[head]= 0;
		head++;
		}
	}
	void display()
	{
		if(this->isempty())
		{}
		else
		{
			for(int i = head;i<=tail;i++)
			{
					cout<<arr[i]<<"->";
		
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
	QUEUE<int> q;
	int ch,temp;
	char c = '*';
	start:
	cout<<"\nEnter your choice: \n";
	cout<<"1. Add an element\n";
	cout<<"2. Delete an element\n";
	cout<<"3. Display Queue\n";
	cout<<"4. Exit\n .. ";
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
		case 4: q.
				return 0;
		default: cout<<"Wrong choice";
	}
	goto start;
	
	return 0;
}
