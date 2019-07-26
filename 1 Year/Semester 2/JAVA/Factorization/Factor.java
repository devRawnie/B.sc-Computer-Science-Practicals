import java.util.Scanner;
class Factor{

public static void main(String args[])
{

Scanner in = new Scanner(System.in);
int no,i,flag=0;
System.out.println("Enter a no: ");
no = in.nextInt();
System.out.print("The factors of " + no + " are: ");
for(i=1;i<=no;i++)
{
	if(no%i==0)
{
System.out.print(i + " " );
}

}

}



}