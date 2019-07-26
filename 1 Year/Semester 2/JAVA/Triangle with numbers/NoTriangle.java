import java.util.Scanner;
class NoTriangle{

public static void main(String args[])
{
Scanner in = new Scanner(System.in);
int i,j,k=0,row;
System.out.print("Enter the no of rows in the triangle:");
row = in.nextInt();
for(i=0;i<row;i++)
{
for(j=0;j<=i;j++)
{if(k<10)
{System.out.print(k++ + "  " );
}
else{
System.out.print(k++ + " " );

}
}
System.out.println();

}

}

}