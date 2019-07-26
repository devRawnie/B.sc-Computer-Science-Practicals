interface Stack{
void push(int a);
int pop();

}
class FixedStack implements Stack{

private int stck[];
private int tos;
FixedStack(int size)
{
stck = new int[size];
tos = -1;

}
public void push(int x)
{
if(tos==stck.length-1)
	System.out.println("Stack is full");
else
	
	stck[++tos] = x;
}
public int pop()
{
if(tos<0){
	System.out.println("Underflow");
	return 0;
}
else
	
	return stck[tos--];
}

}
class DynamicStack implements Stack{

private int stck[];
private int tos;
DynamicStack(int size)
{
stck = new int[size];
tos = -1;

}
public void push(int x)
{
if(tos==stck.length-1)
{	int temp[] = new int[stck.length*2];

for(int i=0;i<stck.length;i++)
{
temp[i] = stck[i];
}
stck = temp;
stck[++tos] = x;
}
else
	{tos++;
	stck[tos] = x;
}}
public int pop()
{
if(tos<0){
	System.out.println("Underflow");
	return 0;}
else
	
	return stck[tos--];
}
}
class Interface{

public static void main(String args[])
{
int i;
FixedStack fs = new FixedStack(10);
DynamicStack ds = new DynamicStack(12);
for(i=0;i<10;i++)
{
fs.push(i);
}
for(i=0;i<15;i++)
{
ds.push(i);

}

System.out.println("Values in Fixed Stack");
for(i=0;i<10;i++)
{
System.out.println(fs.pop());
}
System.out.println("Values in Dynamic Stack");
for(i=0;i<15;i++)
{
System.out.println(ds.pop());
}

}
}