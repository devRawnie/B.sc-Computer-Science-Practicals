import java.util.Scanner;
class Rectangle{
public static void main(String args[])
{
Scanner in = new Scanner(System.in);
int l,b,i,j,k;
System.out.print("Enter length and breadth of the rectangle. l: " );
l = in.nextInt();
System.out.print("b: ");
b = in.nextInt();
for(i=0;i<b;i++)
{
System.out.print(" * ");
k=i;
if(k<1||k>b-2)
{
for(j=0;j<l-2;j++)
{
System.out.print(" * ");
}

}
else{
for(j=0;j<l-2;j++)
{
System.out.print("   ");
}

}
System.out.println(" * ");
}

}

}