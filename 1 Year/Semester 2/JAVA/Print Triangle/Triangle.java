import java.util.Scanner;
class Triangle{

public static void main(String args[])
{
Scanner in = new Scanner(System.in);
int row,i,j;
System.out.println("Enter no of rows: ");
row = in.nextInt();
for(i=0;i<row;i++)
{
for(j=0;j<=i;j++)
{
System.out.print("*");

}
System.out.println();

}


}
}