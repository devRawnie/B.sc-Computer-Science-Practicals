import java.util.Scanner;
class Array{
Scanner in = new Scanner(System.in);
int[] ar;
int size;
Array(int n)
{
size = n;
ar = new int[size];
}
void enter()
{

System.out.print("Enter the elements of the array: ");
for(int i=0;i<size;i++)
{
ar[i] = in.nextInt();
}
}
int Reverse(int n)
{

if(n==0)
{
return 1;
}
else
{
System.out.println("AR[" + (n-1) + "]: " + ar[n-1]);
return Reverse(n-1);

}
}
int Original(int n)
{
if(n==size)
{
return n-1;
}
else
{
System.out.println( " AR[" + (n) + "]: " + ar[n] );
return Original(n+1);
}
}
}
class UseArray{
public static void main(String args[])
{
Scanner in = new Scanner(System.in);
int s;
System.out.print("Enter the size of the array: ");
s = in.nextInt();
Array ob = new Array(s);
ob.enter();
System.out.println("Array in reverse order is: ");
ob.Reverse(s);
System.out.println("Array in Original order is: ");
ob.Original(0);

}

}