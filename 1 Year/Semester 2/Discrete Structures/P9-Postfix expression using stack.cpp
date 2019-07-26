#include<iostream>
#include<string.h>
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
	int eval;
	node* top;
	public:
		Stack()
		{
			top = 0;
			eval = 0;
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
			}}		
			void display()
			{
				if(top == 0)
					cout<<"Empty linked list";
				else{
				node *temp = top;
				int i=1;
				while(temp!=0)
				{
					temp = temp->next;
				i++;
				}
			}
				}
	int pop()
	{
		if(top == 0)
		{	
				return -1;
				}
		else
		{
			int n = top->info;
			node *temp = top;
			top = top->next;
			delete temp;
			return n;
		}
			
	}
	void evaluateExpression()
	{ string exp;
		int size;
	int a, b;
	int temp = 0;
		cout<<"Enter the postfix expression (with spaces): ";
		getline(cin, exp);
		size = exp.size();
		for(int i=0; i<size;i++)
		{
			if(exp[i]!=' ')
			{
			
			if((int)exp[i]>=48 && (int)exp[i]<=57)
				{
				temp = temp*10 + ((int)exp[i] - 48);
				push(temp);
				display();
				}
			else if((int)exp[i] >=42 && (int)exp[i] <= 47)
			{
			a = pop();
			b = pop();
			switch(exp[i])
			{
				case '+': push(b+a);
							break;
				case '-': push(b-a);
							break;
				case '*': push(b*a);
							break;
				case '/': push(b/a);
							break; 
				}	
				
			}
		}
		else
		{
			temp = 0;
		}

		display();
		}
	cout<<"Answer is: "<<pop();
	}
};
int main()
{
	Stack stk;
	stk.evaluateExpression();
	return 0;
}
