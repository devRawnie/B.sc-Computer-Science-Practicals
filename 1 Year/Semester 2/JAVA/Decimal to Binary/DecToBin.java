import java.util.Scanner;
class Stack{
final int size =10 ;
int arr[] = new int[size];
int ptr,bin,temp;
Stack()
{
ptr = -1;
temp = 0;
}
public void display()
{ int i=ptr;

System.out.println("Stack now is:-");
while(i>=0)
{
System.out.print(arr[i] + " " );
i--;
}

}
public void push(int n)
{
if(ptr==(size-1))
{
System.out.println("Overflow!");
}
else
{
 temp = n;
while(temp>0)
{
bin = temp%2;
ptr++;
arr[ptr]=bin;
temp = temp/2;
if(temp==1)
{
ptr++;
arr[ptr] = 1;
break;
}
}
display();
}
}
public void pop()
{
if(ptr==-1)
{
System.out.println("Underflow!");
}
else
{
while(ptr>=0)
{
--ptr;
}
}
}
}
class DecToBin{

public static void main(String args[])
{

int ch,el;
Scanner in = new Scanner(System.in);
Stack ob = new Stack();
do{	
System.out.println("Enter your choice");
System.out.println("1.Push");
System.out.println("2.Pop");
ch = in.nextInt();
switch(ch)

{
case 1:System.out.print("Enter an element: ");
	el = in.nextInt();       
 	ob.push(el);
	break;
case 2: ob.pop();
	ob.display();
	break;
default: System.out.println("Wrong choice");	
	}


System.out.println();
System.out.print("Press 1 to continue");
ch = in.nextInt();
}while(ch==1);

}
}