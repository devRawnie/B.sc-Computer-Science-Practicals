#include<iostream>
using namespace std;
template <class t>
class Stack{
	t *arr;
	t size;
	t top;
	public: 
	Stack(t s)
	{
		size = s;
		arr = new t[size];
		top = -1;
	}
	~Stack()
	{
		delete[] arr;
	}
	void push(t a)
	{
		if(top == size-1 )
			cout<<"Stack is full!!";
		
		else
		{
			arr[++top] = a;
		}
	}
	t pop()
	{
		if(top == -1)
			cout<<"Stack is empty";
		else
		{
			return arr[top--];
		}
	}
	void display()
	{
		cout<<"\n Stack is: \n";
		for(int i = top;i>=0;i--)
		{
			cout<<"-> "<<arr[i]<<endl;
		}
	}
		
void clearStack()
{
	for(int i=top;i>=0;i--)
	{
		cout<<"\nDeleting "<<pop();
	}
	}	
};
int main()
{
	int s,ch,info;
	cout<<"Enter the size of the STACK: ";
	cin>>s;
	Stack<int> obj(s);
	beg:
	cout<<"Choose from the following: \n";
	cout<<"1. Push \n";
	cout<<"2. Pop \n";
	cout<<"3. Clear \n";
	cout<<"4. Display ";
	cout<<"\n5. Quit\n..";
	cin>>ch;
	switch(ch)
	{
		case 1: cout<<"\nEnter the information: ";
				cin>>info;
				obj.push(info);
				break;
		case 2: info = obj.pop();
				if(info > 0)
					cout<<"\nDeleting "<<info;
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
	obj.clearStack();	
	return 0;
}
